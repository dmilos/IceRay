#ifndef  _d00a652409cf41d99389f8d840444ff6
#define  _d00a652409cf41d99389f8d840444ff6


#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Illumination_##D_P
#define P(D_P) IceRayC_##D_P
#define S(D_P) IceRayC_Type_Size P_##D_P
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle
#define E IceRayC__EXPORT
#define D IceRayC__DECLSPEC

E D H F( ALP0           )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( emission  ), S( diffuse    ), S( specular   ), S( shininess ) );
E D H F( Ambient0       )( S( result ), S( emission  ) );
E D H F( AsDiffuse0     )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( diffuse    ), S( specular   )  );
E D H F( AsSpecular0    )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( nu         ), S( nv        ) );
E D H F( Beckmann0      )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( roughness  ) );
E D H F( Blinn0         )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( shininess  ) );
E D H F( Gaussian0      )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( specular   ), S( smoothness ) );
E D H F( Lambert0       )( S( result ), S( point     ), S( normal    ), S( spotBegin ), S( spotEnd ), S( diffuse    ) );
E D H F( Phong0         )( S( result ),                                 S( spotBegin ), S( spotEnd ), S( specular   ), S( shininess  )  );


E D H F( HsLambert0     )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( groove ), S( diffuse ) );
E D H F( HsNormal0      )( S( result ),                 S( normal    ),                                S( groove ) );
E D H F( HsPhong0       )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( groove ), S( specular   ), S( shininess  ) );
E D H F( OnF29          )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( rho ), S( sigma ) );
E D H F( OnP44          )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( A ), S( B ) );
E D H F( OnYF           )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( A ), S( B ) );
E D H F( WardApprox0    )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alphaX  ), S( alphaY ), S( direction ) );
E D H F( WardIsotropic0 )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alpha   ) );
E D H F( WardReal0      )( S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alphaX  ), S( alphaY ), S( direction ) );


#undef D
#undef E
#undef H
#undef S
#undef P
#undef F


#endif
