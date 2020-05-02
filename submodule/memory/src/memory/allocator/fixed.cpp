#include <cstring>
#include "./fixed.hpp"
#include "./chunk/managed.hpp"

using namespace GS_DDMRM::S_system::S_allocator::S_fixed;

//#define Dc_system_allocator_fixed_NAMESPACED(DP_class) GS_DDMRM::S_system::S_allocator::S_fixed::DP_class


struct GC_manager::C2_hat
 {
   std::uint32_t M_bound;
   T_index       M_index;
   std::uint16_t M_count;
   std::uint32_t M_end;
   C2_hat()
   {
     M_bound = 0xAAAAAAAA;
     M_end   = 0xBBBBBBBB;
     M_index = Fs_invalid();
     M_count = 0;
   } 

   ~C2_hat()
   {
     M_bound = 0xCCCCCCCC;
     M_end   = 0xDDDDDDDD;
     M_index = Fs_invalid();
     M_count = 0;
   } 
 };

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
  if( false == this->F_check( P_model ) )
   {
    return false;
   }

  this->F_release( P_data );

  T2_hat & I_hat = this->F2_hat( P_model );
  if( Fs_invalid() == I_hat.M_index )
   {
    return false;
   }

  ++I_hat.M_count;

  P_data.F_ptr( P_model.F_ptr() );
  P_data.F_allocator( this );

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

  T_size I_index = M2_vacant.back();
  M2_vacant.pop_back(); ++M2_acquired;

  T2_hat *I_hat = new (&( M2_container[ I_index *  F_gross() ] ) ) T2_hat;
  I_hat->M_index = I_index;
  I_hat->M_count = 1;
  void * I_head = I_hat + 1;
  P_data.F_ptr( I_head );
  P_data.F_allocator( this );

  return true;
 }

bool GC_manager::F_new( T_data & P_data, T_data const& P_model )
 {
  if( false == this->F_check( P_model ) )
   {
    return false;
   }

  if( false == this->F_new( P_data ) )
   {
    return false;
   }

  std::memcpy( this->F_head( P_data ), this->F_head( P_model ), this->F_weight() );
  P_data.F_ptr( (T2_uint8*)P_data.F_ptr() + this->F2_offset( P_model ) );
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

  T2_hat *I_hat = & this->F2_hat( P_data );
  void * I_head = I_hat+1;
  if( Fs_invalid() == I_hat->M_index )
   {
    P_data.F_allocator( nullptr );
    P_data.F_ptr( nullptr );
    return true;
   }

  --I_hat->M_count;
  if( 0 == I_hat->M_count )
   {
    M2_vacant.push_back( I_hat->M_index ); --M2_acquired;
    I_hat->~C2_hat();
   }

  P_data.F_allocator( nullptr );
  P_data.F_ptr( nullptr );
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

  auto I_distance = (T2_uint8*)P_data.F_ptr() - M2_container.data();

  if( I_distance < 0 )
   {
    return false;
   }

  if( M2_container.size() <= (T_size)I_distance )
   {
    return false;
   }

  // ??? if( 0 != this->F2_offset( P_data ) )
  // ???  {
  // ???   return false;
  // ???  }

  return true;
 }

bool GC_manager::F_clear( )
 {
  T_size I_index = 0;

  //std::fill( M2_container.begin(), M2_container.end(), -1 );
  M2_acquired = 0;
  M2_vacant.resize( M2_container.size()/F_gross(), -1 );
  for( T_size & I_info : M2_vacant )
   {
    //I_info = M2_container.size()/F_gross() - I_index -1;
    I_info = M2_vacant.size() - I_index - 1;

    //T2_hat *I_hat = reinterpret_cast<T2_hat *>( M2_container.data() + I_info*F_gross() );
    //I_hat->M_count =  0;
    //I_hat->M_index = Fs_invalid();
    //I_hat->M_bound = 0xEEEEEEEE;
    //I_hat->M_end   = 0xFFFFFFFF;
    //
    ++I_index;
   }

  return false;
 }

bool  GC_manager::F_weight(  T_size const& P_weight )
 {
  M2_weight = P_weight; 
  M2_gross = M2_weight + sizeof( T2_hat ); 
  return true; 
 }

GC_manager::T2_hat   & GC_manager::F2_hat( T_data const& P_data )const
 {
  return *(T2_hat*)((T2_uint8*)this->F_head( P_data ) - sizeof( T2_hat ) );
 }

GC_manager::T2_hat   & GC_manager::F2_hat( T_data & P_data )const
 {
  return * (T2_hat*)((T2_uint8*)this->F_head( P_data ) - sizeof( T2_hat ) );
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
