#include <cstring>
#include <sstream>

#if 1
#include <iostream>
#include <iomanip>
#endif

#include "./fixed.hpp"
#include "./chunk/managed.hpp"

using namespace GS_DDMRM::S_system::S_allocator::S_fixed;

//#define Dc_system_allocator_fixed_NAMESPACED(DP_class) GS_DDMRM::S_system::S_allocator::S_fixed::DP_class
#define Dc_system_allocator_fixed_DEBUG 0


struct GC_manager::C2_hat
 {
   std::uint32_t M_bound;
   T_index       M_index;
   std::uint16_t M_count;
   std::uint32_t M_end;
   C2_hat()
   {
     M_bound = 0xAAAAAAAA;
     M_index = Fs_invalid();
     M_count = 0;
     M_end   = 0xBBBBBBBB;
   }

   ~C2_hat()
   {
     M_bound = 0xCCCCCCCC;
     M_index = Fs_invalid();
     M_count = 0;
     M_end   = 0xDDDDDDDD;
   }
 };
#if 1
bool GC_manager::M_debug = false;
#endif

GC_manager::GC_manager( T_size const& P_weight )
 :M2_weight( P_weight )
 {
  M2_acquired=0;
  //M2_available=0;
 }

GC_manager::~GC_manager()
 {
 }

void GC_manager::F_reserve( T_size const& P_size )
 {
  M2_container.resize( P_size * F_gross() );
  M2_vacant.reserve( P_size );
  //M2_occupied.clear();

  F_clear();
 }

bool GC_manager::F_share( T_data & P_data, T_data const& P_model )
 {
#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << __func__ << "(" << __LINE__ << "):" << " I:" << to_string( P_model );
   }
#endif

  return F_share( P_data, P_model.F_ptr() );
 }

bool GC_manager::F_share( T_chunk& P_data, T_ptr const& P_ptr )
 {
  if( false == F_check( P_ptr ) )
   {
    return false;
   }

  this->F_release( P_data );

  T2_hat& I_hat = this->F2_hat( P_ptr );
  if( Fs_invalid() == I_hat.M_index )
   {
#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << __func__ << "   (" << __LINE__ << "):" << "\033[31m" << "invalid "<<"\033[0m"<< " O:" << to_string( P_data ) << std::endl;
   }
#endif
    return false;
   }

  if( 0 == I_hat.M_count )
   {
#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << __func__ << "   (" << __LINE__ << "):" << " O:" << to_string( P_data ) << std::endl;
   }
#endif
    return false;
   }
  ++I_hat.M_count;

  P_data.F_ptr( P_ptr );
  P_data.F_allocator( this );
#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << __func__ << "   (" << __LINE__ << "):" << " O:" << to_string( P_data ) << std::endl;
   }
#endif

  return true;
 }

bool GC_manager::F_new( T_data & P_data )
 {
  if( false == this->F_check( P_data ) )
   {
    if( 0 == M2_vacant.size() )
     {
      return false;
     }
   }

  this->F_release( P_data );

  T_index I_index = M2_vacant.back();
  M2_vacant.pop_back(); ++M2_acquired;

  T2_hat *I_hat = new (&( M2_container[ I_index *  F_gross() ] ) ) T2_hat;
  I_hat->M_index = I_index;
  I_hat->M_count = 1;
  void * I_head = I_hat + 1;
  P_data.F_ptr( I_head );
  P_data.F_allocator( this );

#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << __func__ << "    (" << __LINE__ << "):" << to_string( P_data ) << std::endl;;
   }
#endif
  return true;
 }

bool GC_manager::F_clone( T_data & P_data, T_data const& P_model )
 {
  if( false == this->F_check( P_model ) )
   {
    return false;
   }

#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << __func__ << "    (" << __LINE__ << "):" << to_string( P_model );
   }
#endif

  if( false == this->F_new( P_data ) )
   {
    return false;
   }

  std::memcpy( this->F_head( P_data ), this->F_head( P_model ), this->F_weight() );

  P_data.F_ptr( (T2_uint8*)P_data.F_ptr() + this->F2_offset( P_model ) ); //!< true == F_check;
  return true;
 }

bool GC_manager::F_release( T_data & P_data )
 {
  if( nullptr == P_data.F_ptr() )
   {
    P_data.F_allocator( nullptr );
    return true;
   }

  if( nullptr == P_data.F_allocator() )
   {
    P_data.F_ptr( nullptr );
    return true;
   }

  if( this != P_data.F_allocator() )
   {
    P_data.F_allocator()->F_release( P_data );
    return true;
   }

  if( false == F_check( P_data ) )
   {
    return false;
   }

#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << __func__ << "(" << __LINE__ << "):" << " I:" << to_string( P_data );
   }
#endif

  T2_hat *I_hat = & this->F2_hat( P_data );
  // unused void * I_head = I_hat + 1;
  if( Fs_invalid() == I_hat->M_index )
   {
    auto I_distance = (T2_uint8*)P_data.F_ptr() - M2_container.data();
    P_data.F_allocator( nullptr );
    P_data.F_ptr( nullptr );

#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << "\033[34m"<< " invalid"<< "\033[0m" << " O:" << to_string( P_data ) << std::endl;
   }
#endif
    return true;
   }

  if( 0 == I_hat->M_count )
   {
    I_hat->M_count = I_hat->M_count;
   }
  --I_hat->M_count;
  if( 0 == I_hat->M_count )
   {
    M2_vacant.push_back( I_hat->M_index );
    if( 0 == M2_acquired )
     {
      M2_acquired = M2_acquired;
     }
#if 1 == Dc_system_allocator_fixed_DEBUG
      if( true == M_debug )
       {
        std::cout << "\033[32m" << "final" << "\033[0m";
       }
#endif
    --M2_acquired;
    I_hat->~C2_hat();
   }


  P_data.F_allocator( nullptr );
  P_data.F_ptr( nullptr );
#if 1 == Dc_system_allocator_fixed_DEBUG
  if( true == M_debug )
   {
    std::cout << " O:" << to_string( P_data ) << std::endl;
   }
#endif
  return true;
 }

bool GC_manager::F_check( T_ptr const& P_ptr )const
 {
  auto I_origin = M2_container.data();
  auto I_pointer = reinterpret_cast<T2_uint8*>(P_ptr);
  if( I_pointer < I_origin )
   {
    return false;
   }

  T_size I_distance = I_pointer - I_origin;
  if( (I_distance < 0) || ( M2_container.size() <= I_distance ) )
   {
    return false;
   }

  T_size I_offset = (I_distance) % this->F_gross();
  if( I_offset < sizeof( T2_hat ) )
   {
    return false;
   }
  T2_hat const& I_hat = this->F2_hat( P_ptr );
  if( 0 == I_hat.M_count )
   {
    return false;
   }
  if( Fs_invalid() == I_hat.M_index )
   {
    return false;
   }

  return true;
 }

bool GC_manager::F_check( T_data const& P_data )const
 {
  if( nullptr == P_data.F_allocator() )
   {
    return false;
   }

  if( this != P_data.F_allocator() )
   {
    return false;
   }

  if( nullptr == P_data.F_ptr() )
   {
    return false;
   }

  return F_check( P_data.F_ptr() );
 }

bool GC_manager::F_clear( )
 {
  T_index I_index = static_cast<T_index>( M2_container.size() / F_gross() );

  std::fill( M2_container.begin(), M2_container.end(), 0x69 );
  M2_acquired = 0;
  M2_vacant.resize( I_index, -1 );
  for( auto & I_info : M2_vacant )
   {
    --I_index;
    I_info = I_index;

    T2_hat *I_hat = reinterpret_cast<T2_hat *>( M2_container.data() + I_info*F_gross() );
    I_hat->M_bound = 0xE0000000 + I_index;
    I_hat->M_count =  0;
    I_hat->M_index = Fs_invalid();
    I_hat->M_end   = 0xF0000000 + I_index;
   }

  return true;
 }

bool  GC_manager::F_weight(  T_size const& P_weight )
 {
  M2_weight = P_weight;
  M2_gross = M2_weight + sizeof( T2_hat );
  return true;
 }

GC_manager::T2_hat      & GC_manager::F2_hat(    T_ptr const& P_ptr  )const
 {
  auto I_position = M2_gross *( ((T2_uint8*)P_ptr - M2_container.data() )/ M2_gross );
  return *(T2_hat*)( M2_container.data() + I_position );
 }

GC_manager::T2_hat   & GC_manager::F2_hat( T_data const& P_data )const
 {
  return F2_hat( P_data.F_ptr() );
 }

GC_manager::T2_container const& GC_manager::F_container()const
 {
  return M2_container;
 }

GC_manager::T_ptr GC_manager::F_head( T_data const& P_data )const
 {
  return  (T2_uint8*)P_data.F_ptr() - this->F2_offset( P_data );
 }

GC_manager::T_size GC_manager::F2_offset( T_data const& P_data )const
 {
  auto I_distance = (T2_uint8*)P_data.F_ptr() - this->M2_container.data();

  return ( I_distance ) % this->F_gross() - sizeof(T2_hat);
 }

//int GC_manager::F2_distance( T_data const& P_data )const
// {
//  return (T2_uint8*)P_data.F_ptr() - this->M2_container.data();
// }

std::string GC_manager::to_string( T_chunk const& P_chunk )
 {
  if( nullptr == P_chunk.F_ptr()  )
   {
    return "\033[1m nullptr \033[0m";
   }
  auto I_hat = P_chunk.F_allocator()->F2_hat( P_chunk );
  std::stringstream ss;
  auto I_allocator = P_chunk.F_allocator();
  if( nullptr != I_allocator )
   {
    ss << "{ ";
    //ss << I_distance / I_allocator->F_gross() << "; ";
    ss << std::hex << I_hat.M_bound << "; ";
    ss << "i: " << std::setw( 3 ) << I_hat.M_index << "; ";
    ss << "c: " << std::setw( 3 ) << I_hat.M_count << "; ";
    //ss << std::hex << I_hat.M_end << "; ";
    ss << "o: " << std::setw(4) << I_allocator->F2_offset( P_chunk ) << "; ";
    ss << " }";
   }
  else
   {
    ss << "A: nullptr";
   }

  return ss.str();
 }
