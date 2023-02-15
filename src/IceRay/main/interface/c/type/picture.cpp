
#include "pnm/pnm.hpp"

#if defined( ICERAY_WINDOWS_USE_GDI)
#if defined( _MSC_VER  )

#include <windows.h>
#include <gdiplus.h>

#endif
#endif



#include <fstream>

#include "./picture.h"
#include "./coord.hpp"

#include "IceRay/type/picture/picture.hpp"


IceRayC_Type_Picture_Handle cpp2c( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Type_Picture_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure * c2cpp( IceRayC_Type_Picture_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure*> ( P_that );
 }

IceRayC_Type_Bool           IceRayC_Type_Picture_Release( IceRayC_Type_Picture_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
  return 1;
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

IceRayC_Type_Bool IceRayC_Type_Picture_Size(     IceRayC_Type_Picture_Handle P_this, IceRayC_TypeSize width, IceRayC_TypeSize height )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_size( Tf_memory::T_coord{ width, height } );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Type_Picture_SizeGet( IceRayC_Type_Picture_Handle P_this, IceRayC_TypeCoordSize2D * P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  *P_size = cpp2c( I_this->F_size() );
  return 1;
 }
IceRayC_Type_Bool IceRayC_Type_Picture_SizeSet( IceRayC_Type_Picture_Handle P_this, IceRayC_TypeCoordSize2D const* P_size  )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_size( c2cpp( *P_size ) );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Type_Picture_Crop0( IceRayC_Type_Picture_Handle P_this, IceRayC_TypeCoordSize2D const* P_A, IceRayC_TypeCoordSize2D const* P_B )
 {
  auto I_this = c2cpp( P_this );
  return GS_DDMRM::S_IceRay::S_type::S_picture::GF_crop( *I_this, { c2cpp( *P_A ), c2cpp( *P_B ) } );
 }

IceRayC_Type_Bool IceRayC_Type_Picture_Crop( IceRayC_Type_Picture_Handle P_target, IceRayC_Type_Picture_Handle P_source, IceRayC_TypeCoordSize2D const* P_A, IceRayC_TypeCoordSize2D const* P_B )
 {
  auto I_target = c2cpp( P_target );
  auto I_source = c2cpp( P_source );
  return GS_DDMRM::S_IceRay::S_type::S_picture::GF_crop( *I_target, *I_source, { c2cpp( *P_A ), c2cpp( *P_B ) } );
 }

IceRayC_Type_Bool IceRayC_Type_Picture_Load( IceRayC_Type_Picture_Handle P_this, char const* P_fileName )
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
  if( true == info.valid() )
   {
    if( PNM::P6 != info.type() )
     {
      return 0;
     }
    I_this->Fv_size( { info.width(), info.height() } );
    std::uint8_t * data = const_cast<  uint8_t * >( ( uint8_t const* )I_this->Fv_data() );
    { std::ifstream ifs( P_fileName, std::ios_base::binary ); ifs >> PNM::load( data, info ); }

    return 1;
   }

#if defined( ICERAY_WINDOWS_USE_GDI )

    auto I_image = Gdiplus::Bitmap::FromFile( std::wstring( P_fileName, P_fileName + strlen(P_fileName) ).c_str() );
    if( nullptr != I_image )
     {
      if( 0 == I_image->GetWidth() ) return 0;
      if( 0 == I_image->GetHeight() ) return 0;
      I_this->Fv_size( { I_image->GetWidth(), I_image->GetHeight() } );
      Gdiplus::Color I_color;

      for( Tf__pure::T_size y=0; y< I_this->F_size()[1]; ++y )
       for( Tf__pure::T_size x=0; x< I_this->F_size()[0]; ++x )
        {
         I_image->GetPixel( x, y, &I_color );
         I_this-> Fv_pixel( {x,y}, Tf__pure::T_color{ I_color.GetRed(), I_color.GetGreen(), I_color.GetBlue() } );
        }

      delete I_image;
      return 1;
     }
#endif

  return 0;
 }

IceRayC_Type_Bool IceRayC_Type_Picture_StoreJPEG( IceRayC_Type_Picture_Handle P_this, char const* P_filename )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;
  return 0;
 }

IceRayC_Type_Bool IceRayC_Type_Picture_StorePNG( IceRayC_Type_Picture_Handle P_this, char const* P_filename )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

#if defined( ICERAY_WINDOWS_USE_GDI )

   auto const& I_size = I_this->F_size();
   Gdiplus::Bitmap I_bmp( I_size[0], I_size[1], PixelFormat24bppRGB );
   if( Gdiplus::Ok == I_bmp.GetLastStatus() )
    {
     Tf__pure::T_coord  I_coord;
     Tf__pure::T_color  I_color;
     for( I_coord[1]=0; I_coord[1] < I_size[1]; ++I_coord[1] ) 
      for( I_coord[0]=0; I_coord[0] < I_size[0]; ++I_coord[0] )
       {
        auto I_pixel = I_this->Fv_pixel( I_color, I_coord );

        I_bmp.SetPixel( I_coord[0], I_coord[1], Gdiplus::Color( I_color[0], I_color[1], I_color[2]  ) );
       }

       CLSID I_pngClsid={ 0x557cf406L, 0x1a04L, 0x11d3L, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };
     //CLSID I_jpgClsid={ 0x557cf401L, 0x1a04L, 0x11d3L, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };
     //CLSID I_gifClsid={ 0x557cf402L, 0x1a04L, 0x11d3L, { 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };
     //CLSID I_bmpClsid={ 0xb96b3cabL, 0x0728L, 0x11d3L, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };
     //CLSID I_tifClsid={ 0x557cf405L, 0x1a04L, 0x11d3L, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };

     I_bmp.Save( std::wstring( P_filename, P_filename + strlen(P_filename) ).c_str(), &I_pngClsid, NULL ); 

     return 1;
    }
#endif

  return 0;
 }

IceRayC_Type_Bool IceRayC_Type_Picture_StorePNM( IceRayC_Type_Picture_Handle P_this, char const* P_filename )
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
  return 1;
 }

IceRayC_Type_Bool IceRayC_Type_Picture_Bits( IceRayC_Type_Picture_Handle P_this, unsigned char const** P_bits )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  *P_bits = reinterpret_cast< unsigned char const *> ( I_this->Fv_data() );
  return true;
 }

IceRayC_Type_Bool IceRayC_Type_Picture_Default( IceRayC_Type_Picture_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    Tf_memory;

  auto I_this = dynamic_cast<Tf_memory*>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  GS_DDMRM::S_IceRay::S_type::S_picture::GF_default( *I_this );
  return true;
 }

