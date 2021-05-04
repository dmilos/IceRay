#include "./illumination.hpp"


#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Illumination_##D_P
#define S(D_P) IceRayC_Type_Size P_##D_P
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


H F( ALP0          )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( emission  ), S( diffuse    ), S( specular   ), S( shininess ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_AmbientLambertPhong Tf_this;
  auto I_this = new Tf_this{ P_result, P_point, P_normal, P_spotBegin , P_spotEnd, P_emission, P_diffuse, P_specular, P_shininess };
  return cpp2c( I_this );
 }
H F( Ambient0     )( S( result ), S( emission  ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_ambient Tf_this;
  auto I_this = new Tf_this{ P_result, P_emission };
  return cpp2c( I_this );
 }
H F( AsDiffuse0 )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( diffuse    ), S( specular   ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_AshikhminShirley::GC_diffuse Tf_this;
  auto I_this = new Tf_this{ P_result, P_point, P_normal, P_spotBegin , P_spotEnd, P_diffuse, P_specular };
  return cpp2c( I_this );
 }
H F( AsSpecular0 )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( nu         ), S( nv        )  )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_AshikhminShirley::GC_specular Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_specular, P_nu  ,P_nv  };
  return cpp2c( I_this );
 }
H F( Beckmann0    )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( roughness  ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_beckmann Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_specular  ,P_roughness  };
  return cpp2c( I_this );
 }
H F( Blinn0       )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( shininess  ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_blinn Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_specular  ,P_shininess };
  return cpp2c( I_this );
 }
H F( Gaussian0    )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( smoothness ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_gaussian Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_specular  ,P_smoothness };
  return cpp2c( I_this );
 }
H F( Lambert0     )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( diffuse    ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_lambert Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_diffuse };
  return cpp2c( I_this );
 }
H F( Phong0       )( S( result ),                                 S( spotBegin ), S( spotEnd ), S( specular   ), S( shininess  ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_phong Tf_this;
  auto I_this = new Tf_this{ P_result,  P_spotBegin , P_spotEnd, P_specular, P_shininess };
  return cpp2c( I_this );
 }

H F( HsLambert0     )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( groove ), S( diffuse ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_HeidrichSeidel::GC_Lambert Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_groove, P_diffuse };
  return cpp2c( I_this );
 }
H F( HsNormal0      )( S( result ),                 S( normal    ),                                S( groove ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_HeidrichSeidel::GC_normal Tf_this;
  auto I_this = new Tf_this{ P_result, P_normal    ,P_groove };
  return cpp2c( I_this );
 }
H F( HsPhong0       )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( groove ), S( specular   ), S( shininess  ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_HeidrichSeidel::GC_Phong Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_groove, P_specular, P_shininess };
  return cpp2c( I_this );
 }
H F( ON_f29          )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( rho ), S( sigma ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::GC_f29 Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_rho, P_sigma  };
  return cpp2c( I_this );
 }
H F( ON_f30          )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( rho ), S( sigma ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::GC_f30 Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_rho, P_sigma };
  return cpp2c( I_this );
 }

H F( ON_Fujii_Proposed  )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( A ), S( B ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::S_Fujii::GC_proposed Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_A, P_B  };
  return cpp2c( I_this );
 }

H F( ON_Fujii_Qualitative  )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( A ), S( B ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::S_Fujii::GC_qualitative Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_A, P_B  };
  return cpp2c( I_this );
 }

H F( ON_Ouwerkerk           )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( A ), S( B ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::GC_Ouwerkerk Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_A, P_B  };
  return cpp2c( I_this );
 }

H F( WardApprox0    )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alphaX  ), S( alphaY ), S( direction ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_ward::GC_approx Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_specular, P_alphaX, P_alphaY, P_direction };
  return cpp2c( I_this );
 }
H F( WardIsotropic0 )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alpha   ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_ward::GC_isotropic Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin , P_spotEnd, P_specular, P_alpha };
  return cpp2c( I_this );
 }
H F( WardReal0      )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alphaX  ), S( alphaY ), S( direction ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_ward::GC_real Tf_this;
  auto I_this = new Tf_this{ P_result, P_point     ,P_normal    ,P_spotBegin,  P_spotEnd, P_specular, P_alphaX, P_alphaY, P_direction };
  return cpp2c( I_this );
 }

#undef H
#undef S
#undef P
#undef F
