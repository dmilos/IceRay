#ifndef _315d9ed207904c1da5d6f0a543f36d99
#define _315d9ed207904c1da5d6f0a543f36d99

#include "./handle.h"
#include "../../../../type/coord.h"
#include "../../../../type/affine.h"
#include "../../../../type/homography.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Color0   )( S P_result, S P_input, S P_candidate );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord2D0 )( S P_result, S P_input, S P_candidate );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord3D0 )( S P_result, S P_input, S P_candidate );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Scalar0  )( S P_result, S P_input, S P_candidate );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Size0    )( S P_result, S P_input, S P_candidate );

#undef H
#undef S
#undef F
#undef P


#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Ramp0     )( S P_result, S P_input );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Saw0      )( S P_result, S P_input );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Wave0     )( S P_result, S P_input );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Sinkhole0 )( S P_result, S P_input );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Relu0     )( S P_result, S P_input );

#undef H
#undef S
#undef F
#undef P

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Random_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Congruent1D0 )( S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Congruent2D0 )( S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Sobol1D0     )( S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Sobol2D0     )( S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Standard1D0  )( S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Table1D0     )( S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Table2D0     )( S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( VDC1D0       )( S P_count, S P_leader );

#undef H
#undef S
#undef F
#undef P
 

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


IceRayC__EXPORT IceRayC__DECLSPEC H   F(Identity3D0        )( S P_result, S P_left );

IceRayC__EXPORT IceRayC__DECLSPEC H   F(Translate3D0       )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H   F(Translate3D1       )(           IceRayC_Type_Coord_Scalar3D   * P_translate, S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC int F(Translate3D_Move   )( H P_that, IceRayC_Type_Coord_Scalar3D   * P_translate );

IceRayC__EXPORT IceRayC__DECLSPEC H   F(Affine3D0            )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H   F(Affine3D1            )(           IceRayC_Type_Math_Affine3D    * P_affine, S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC int F(Affine3D_Structure   )( H P_that, IceRayC_Type_Math_Affine3D    * P_affine );

IceRayC__EXPORT IceRayC__DECLSPEC H   F(Homography3D0             )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H   F(Homography3D1             )(           IceRayC_Type_Math_Homography3D     * P_homography, S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC int F(Homography3D_Structure    )( H P_that, IceRayC_Type_Math_Homography3D     * P_homography );

IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2Cylindric0 )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2Package0   )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2Spherical0 )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2Torus0     )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2Tablecloth0)( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2WoodX0     )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2WoodY0     )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2WoodZ0     )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cylindric2Cartesian0 )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cylindric2Spherical0 )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Spherical2Cartesian0 )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Spherical2Cylindric0 )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Euclid2Max0          )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Max2Euclid0          )( S P_result, S P_left );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Cartesian2Fisheye0   )( S P_result, S P_left );

#undef H
#undef S
#undef F
#undef P

// TODO IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Binary( );
// TODO IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Ternary( );
// TODO IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Unary( );


#endif
