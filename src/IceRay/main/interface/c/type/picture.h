#ifndef _0c941b45a2f74f459e47f6d561e2b62e
#define _0c941b45a2f74f459e47f6d561e2b62e

#include "../system/system.h"
#include "../type/bool.h"
#include "../type/size.h"
#include "../type/color.h"
#include "../type/scalar.h"

struct  IceRayC_Type_Picture_Struct {};
typedef IceRayC_Type_Picture_Struct* IceRayC_Type_Picture_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Release( IceRayC_Type_Picture_Handle P_this );


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Picture_Handle IceRayC_Type_Picture0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Picture_Handle IceRayC_Type_Picture1( char * P_filename );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Set(    IceRayC_Type_Picture_Handle P_this, IceRayC_TypeCoordSize2D const* P_location, IceRayC_TypeColorRGB const*P_color );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Size(    IceRayC_Type_Picture_Handle P_this, IceRayC_TypeSize width, IceRayC_TypeSize height );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_SizeGet( IceRayC_Type_Picture_Handle P_this, IceRayC_TypeCoordSize2D      * P_size );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_SizeSet( IceRayC_Type_Picture_Handle P_this, IceRayC_TypeCoordSize2D const* P_size  );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Crop0( IceRayC_Type_Picture_Handle P_this,                                         IceRayC_TypeCoordSize2D const* P_lo, IceRayC_TypeCoordSize2D const* P_hi );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Crop(  IceRayC_Type_Picture_Handle P_target, IceRayC_Type_Picture_Handle P_source, IceRayC_TypeCoordSize2D const* P_lo, IceRayC_TypeCoordSize2D const* P_hi );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Load(      IceRayC_Type_Picture_Handle P_this, char const* P_filename );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_StorePNM(  IceRayC_Type_Picture_Handle P_this, char const* P_filename );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_StorePNG(  IceRayC_Type_Picture_Handle P_this, char const* P_filename );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_StoreJPEG( IceRayC_Type_Picture_Handle P_this, char const* P_filename );

IceRayC__EXPORT IceRayC__DECLSPEC unsigned char const* IceRayC_Type_Picture_Buffer( IceRayC_Type_Picture_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Default( IceRayC_Type_Picture_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool IceRayC_Type_Picture_Clear( IceRayC_Type_Picture_Handle P_this, IceRayC_TypeColorRGB * P_average );


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool   IceRayC_Type_Picture_Average(    IceRayC_Type_Picture_Handle P_this, IceRayC_TypeColorRGB * P_average );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Scalar IceRayC_Type_Picture_Dispersion( IceRayC_Type_Picture_Handle P_this );

#endif
