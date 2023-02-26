#ifndef _8dda9e634412443a8c4968b733b102d6
#define _8dda9e634412443a8c4968b733b102d6

#include "../../../system/system.h"
#include "../../../type/size.h"
#include "../../../type/scalar.h"
#include "../../../type/color.h"
#include "../../../type/coord.h"
#include "../../../type/affine.h"
#include "../../../type/picture.h"

struct  IceRayC_Material_Pattern_Struct {};
typedef IceRayC_Material_Pattern_Struct* IceRayC_Material_Pattern_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC   int  IceRayC_Material_Pattern_Release( IceRayC_Material_Pattern_Handle  P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Brick0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Checker0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Hexagon0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Wave0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Onion0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Level0( );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Image0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Image1( IceRayC_Type_Picture_Handle P_picture );
IceRayC__EXPORT IceRayC__DECLSPEC  int                             IceRayC_Material_Pattern_Image_Picture( IceRayC_Material_Pattern_Handle P_this, IceRayC_Type_Picture_Handle P_picture );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Cells0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Crackle0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Gold0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Perlin0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Random0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Value0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Vdc0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Congruent3D0( );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Cube0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Dodecahedron0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Icosahedron0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Octahedron0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Tetrahedron0( );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Gradient0    ( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                             IceRayC_Material_Pattern_Gradient_Set ( IceRayC_Material_Pattern_Handle P_this, IceRayC_Type_Scalar P_point,   IceRayC_Type_Color_RGB* P_color );
IceRayC__EXPORT IceRayC__DECLSPEC  int                             IceRayC_Material_Pattern_Gradient_Bottom( IceRayC_Material_Pattern_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_bottom );
IceRayC__EXPORT IceRayC__DECLSPEC  int                             IceRayC_Material_Pattern_Gradient_Top(    IceRayC_Material_Pattern_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_top    );


#endif