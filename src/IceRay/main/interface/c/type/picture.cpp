#include <fstream>

#include "./picture.h"

#include "IceRay/type/picture/memory.hpp"
#include "pnm/pnm.hpp"

void                       IceRayC_Type_Picture_Release( IceRayC_Type_Picture_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Type_Picture_Handle IceRayC_Type_Picture0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto Ir_result = new Tf_memory{  };
  return reinterpret_cast<IceRayC_Type_Picture_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
}

IceRayC_Type_Picture_Handle IceRayC_Type_Picture1( char * P_fileName )
{
  auto Ir_result = IceRayC_Type_Picture0();
  IceRayC_Type_Picture_Load( Ir_result, P_fileName );
  return Ir_result;
}

int IceRayC_Type_Picture_Size(     IceRayC_Type_Picture_Handle P_this, unsigned width, unsigned height )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_size( Tf_memory::T_coord{ width, height } );
  return 1;
 }

int IceRayC_Type_Picture_Load( IceRayC_Type_Picture_Handle P_this, char const* P_fileName )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  PNM::Info info;
  { std::ifstream ifs( P_fileName, std::ios_base::binary ); ifs >> PNM::probe( info ); }
  if( false == info.valid() )
   {
      return 0;
   }
  if( PNM::P6 != info.type() )
   {
    return 0;
   }

  I_this->Fv_size( { info.width(), info.height() } );
  std::uint8_t * data = const_cast<  uint8_t * >( ( uint8_t const* )I_this->Fv_data() );
  { std::ifstream ifs( P_fileName, std::ios_base::binary ); ifs >> PNM::load( data, info ); }

  return 1;
 }

int IceRayC_Type_Picture_StorePNM( IceRayC_Type_Picture_Handle P_this, char const* P_filename )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  std::ofstream ofs( P_filename, std::ios_base::binary );

  ofs << PNM::save( (const uint8_t *)I_this->Fv_data(), I_this->F_size()[0], I_this->F_size()[1], PNM::P6 );
  return true;
 }

