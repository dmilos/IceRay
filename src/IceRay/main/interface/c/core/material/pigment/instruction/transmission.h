#ifndef _cf9d08336a35441a9810d21f0aa8d132
#define _cf9d08336a35441a9810d21f0aa8d132


#include "./handle.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Transmission_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Grid0      )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_total, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Hexagon0   )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_total, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Poisson0   )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_total, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Sunflower0 )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_total, S P_beam );

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Pinwheel0  )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_beam );

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_LD0        )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Random0    )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Sobol0     )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Congruent0 )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Triangle0  )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_VDC0       )( S P_normal, S P_count, S P_leader, S P_angle, S P_gauss, S P_beam );

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Jitter_General0    )( S P_normal, S P_count, S P_leader, S P_angle, S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Jitter_Sobol0      )( S P_normal, S P_count, S P_leader, S P_angle );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Jitter_Congruent0  )( S P_normal, S P_count, S P_leader, S P_angle );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Jitter_Random0     )( S P_normal, S P_count, S P_leader, S P_angle );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Jitter_VDC0        )( S P_normal, S P_count, S P_leader, S P_angle );

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Correct_Cone0 )( S P_normal, S P_bump, S P_angleIn, S P_angleOut );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Correct_Trim0 )( S P_normal, S P_count, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Correct_Claim0)( S P_normal, S P_count, S P_leader );

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Reflect_One0     )( S P_point, S P_normal, S P_albedo, S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Reflect_Schlick0 )( S P_point, S P_normal, S P_ior,    S P_leader );

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Fresnel0 )( S P_point, S P_normal, S P_ior, S P_albedo, S P_total,        S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Schlick0 )( S P_point, S P_normal, S P_ior, S P_albedo, S P_total,        S P_leader );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Snell0   )( S P_point, S P_normal, S P_ior, S P_albedo, S P_transparency, S P_leader );

#undef H
#undef S
#undef F
#undef P


#endif

