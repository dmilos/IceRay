

#include <boost/python.hpp>

#define EXTERN_AND_CALL(dp_function) \
 {                                   \
  extern void dp_function();         \
  dp_function();                     \
 }

BOOST_PYTHON_MODULE(IceRayCpp)
 {
  extern void InitSystem( void );
  InitSystem();
  EXTERN_AND_CALL( expose_graph_picture_save_image );
  EXTERN_AND_CALL( expose_graph_type_color         );
  EXTERN_AND_CALL( expose_graph_picture_memory     );

  EXTERN_AND_CALL( expose_math_type_coord_coord );
  EXTERN_AND_CALL( expose_math_type_interval );
  EXTERN_AND_CALL( expose_math_type_matrix );
  EXTERN_AND_CALL( expose_math_type_affine );

  EXTERN_AND_CALL( expose_IceRay_library_function_function );


  EXTERN_AND_CALL( expose_IceRay_camera__pure       );
  EXTERN_AND_CALL( expose_IceRay_camera__parent     );
  EXTERN_AND_CALL( expose_IceRay_camera_focus       );
  EXTERN_AND_CALL( expose_IceRay_camera_cone        );

  EXTERN_AND_CALL( expose_IceRay_camera_transform_invert      );
  EXTERN_AND_CALL( expose_IceRay_camera_transform_affine   );

  EXTERN_AND_CALL( expose_IceRay_camera_cylinder_horizontal    );
  EXTERN_AND_CALL( expose_IceRay_camera_cylinder_vertical    );

  EXTERN_AND_CALL( expose_IceRay_camera_sphere_horizontal    );
  EXTERN_AND_CALL( expose_IceRay_camera_sphere_vertical    );
  EXTERN_AND_CALL( expose_IceRay_camera_sphere_package    );
  EXTERN_AND_CALL( expose_IceRay_camera_sphere_fisheye    );

  EXTERN_AND_CALL( expose_IceRay_camera_flat_perspective );
  EXTERN_AND_CALL( expose_IceRay_camera_flat_super );
  EXTERN_AND_CALL( expose_IceRay_camera_flat_orthogonal  );

  EXTERN_AND_CALL( expose_IceRay_light_type_Spot  );
  EXTERN_AND_CALL( expose_IceRay_light__Pure );

  EXTERN_AND_CALL( expose_IceRay_light_Area );
  EXTERN_AND_CALL( expose_IceRay_light_Disc );
  EXTERN_AND_CALL( expose_IceRay_light_Blocked );
  EXTERN_AND_CALL( expose_IceRay_light_Chandelier );
  EXTERN_AND_CALL( expose_IceRay_light_Circle );
  EXTERN_AND_CALL( expose_IceRay_light_Dark );
  EXTERN_AND_CALL( expose_IceRay_light_Line );
  EXTERN_AND_CALL( expose_IceRay_light_Point );
  EXTERN_AND_CALL( expose_IceRay_light_Reflector );
  EXTERN_AND_CALL( expose_IceRay_light_Sphere );
  EXTERN_AND_CALL( expose_IceRay_light_Spline );
  EXTERN_AND_CALL( expose_IceRay_light_SunSpot );
  EXTERN_AND_CALL( expose_IceRay_light_SunGeneral );
  EXTERN_AND_CALL( expose_IceRay_light_Clipped );
  EXTERN_AND_CALL( expose_IceRay_light_confine );

  EXTERN_AND_CALL( expose_IceRay_geometry__pure      );
  EXTERN_AND_CALL( expose_IceRay_geometry__inside    );


  EXTERN_AND_CALL( expose_IceRay_geometry_box        );
  EXTERN_AND_CALL( expose_IceRay_geometry_cone       );
  EXTERN_AND_CALL( expose_IceRay_geometry_cylinder   );
  EXTERN_AND_CALL( expose_IceRay_geometry_simple_ucylinder   );
  EXTERN_AND_CALL( expose_IceRay_geometry_disc       );
  EXTERN_AND_CALL( expose_IceRay_geometry_plane      );
  EXTERN_AND_CALL( expose_IceRay_geometry_sphere     );
  EXTERN_AND_CALL( expose_IceRay_geometry_simple_ellipsoid  );
  EXTERN_AND_CALL( expose_IceRay_geometry_simple_usphere );
  EXTERN_AND_CALL( expose_IceRay_geometry_simple_quadric );
  EXTERN_AND_CALL( expose_IceRay_geometry_torus      );
  EXTERN_AND_CALL( expose_IceRay_geometry_triangle   );
  EXTERN_AND_CALL( expose_IceRay_geometry_simple_paraboloid    );
  EXTERN_AND_CALL( expose_IceRay_geometry_simple_hyperboloid    );
  EXTERN_AND_CALL( expose_IceRay_geometry_simple_saddle         );

  EXTERN_AND_CALL( expose_IceRay_geometry_blobby___pure     );
  EXTERN_AND_CALL( expose_IceRay_geometry_blobby_system     );
  EXTERN_AND_CALL( expose_IceRay_geometry_blobby_sphere     );
  EXTERN_AND_CALL( expose_IceRay_geometry_blobby_uwaterZ    );
  EXTERN_AND_CALL( expose_IceRay_geometry_blobby_usphere    );
  EXTERN_AND_CALL( expose_IceRay_geometry_blobby_ucylinderZ );

  EXTERN_AND_CALL( expose_IceRay_geometry_blobby_translate );
  EXTERN_AND_CALL( expose_IceRay_geometry_blobby_affine    );

  EXTERN_AND_CALL( expose_IceRay_geometry_complex_intersect );
  EXTERN_AND_CALL( expose_IceRay_geometry_complex_aifs   );

  EXTERN_AND_CALL( expose_IceRay_geometry_hfield_system );

  EXTERN_AND_CALL( expose_IceRay_geometry_RTSS__pure );
  EXTERN_AND_CALL( expose_IceRay_geometry_RTSS_list );
  EXTERN_AND_CALL( expose_IceRay_geometry_RTSS_object );
  EXTERN_AND_CALL( expose_IceRay_geometry_RTSS_uniform );

  EXTERN_AND_CALL( expose_IceRay_geometry_transform_affine );
  EXTERN_AND_CALL( expose_IceRay_geometry_transform_mblur );
  EXTERN_AND_CALL( expose_IceRay_geometry_transform_projective );
  EXTERN_AND_CALL( expose_IceRay_geometry_transform_translate );
  EXTERN_AND_CALL( expose_IceRay_geometry_transform_identity );

  EXTERN_AND_CALL( expose_IceRay_geometry_mist    );
  EXTERN_AND_CALL( expose_IceRay_geometry_smoke   );
  EXTERN_AND_CALL( expose_IceRay_geometry_vacuum  );

  EXTERN_AND_CALL( expose_IceRay_material_medium__pure );
  EXTERN_AND_CALL( expose_IceRay_material_medium_constant );
  EXTERN_AND_CALL( expose_IceRay_material_medium_linear );
  EXTERN_AND_CALL( expose_IceRay_material_medium_quadratic );
  EXTERN_AND_CALL( expose_IceRay_material_medium_exponential );
  EXTERN_AND_CALL( expose_IceRay_material_medium_pattern );


  EXTERN_AND_CALL( expose_IceRay_material_pigment );
  EXTERN_AND_CALL( expose_IceRay_material_material );
  EXTERN_AND_CALL( expose_IceRay_material_surface );
  EXTERN_AND_CALL( expose_IceRay_material_instruction );

  EXTERN_AND_CALL( expose_IceRay_material_illumination_ALP );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_ambient );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_beckmann );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_blinn );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_gaussian );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_hs_lambert );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_hs_phong );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_lambert );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_on_p44 );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_on_f29 );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_on_YF );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_phong );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_ward_approx );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_ward_isotropic );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_ward_real );

  EXTERN_AND_CALL( expose_IceRay_material_illumination_AshikhminShirley_diffuse );
  EXTERN_AND_CALL( expose_IceRay_material_illumination_AshikhminShirley_specular );

  // TODO EXTERN_AND_CALL( expose_IceRay_material_illumination_CT_fresnel );
  // TODO EXTERN_AND_CALL( expose_IceRay_material_illumination_CT_slick );


  EXTERN_AND_CALL( expose_IceRay_material_geometry_distance  );
  EXTERN_AND_CALL( expose_IceRay_material_geometry_intersect );
  EXTERN_AND_CALL( expose_IceRay_material_geometry_normal    );
  EXTERN_AND_CALL( expose_IceRay_material_geometry_UVW       );

    EXTERN_AND_CALL( expose_IceRay_material_light_generator );
    EXTERN_AND_CALL( expose_IceRay_material_light_spotUVW );
    EXTERN_AND_CALL( expose_IceRay_material_light_spotCull );
    EXTERN_AND_CALL( expose_IceRay_material_light_spotSwarm );

  EXTERN_AND_CALL( expose_IceRay_material_compute_operation_convert );
  EXTERN_AND_CALL( expose_IceRay_material_compute_operation_scalar_clamp );
  EXTERN_AND_CALL( expose_IceRay_material_compute_operation_scalar_arithmetic );
  EXTERN_AND_CALL( expose_IceRay_material_compute_operation_switch );
  EXTERN_AND_CALL( expose_IceRay_material_compute_operation_mapping );

  EXTERN_AND_CALL(   expose_IceRay_material_compute_operation_color_arithmetic );

    EXTERN_AND_CALL( expose_IceRay_material_compute_pattern_constant );
    EXTERN_AND_CALL( expose_IceRay_material_compute_pattern_function );

  EXTERN_AND_CALL( expose_IceRay_material_transmission_reflect_one );
  EXTERN_AND_CALL( expose_IceRay_material_transmission_reflect_schlick );

  EXTERN_AND_CALL( expose_IceRay_material_transmission_refract_one );
  EXTERN_AND_CALL( expose_IceRay_material_transmission_refract_multi );
  EXTERN_AND_CALL( expose_IceRay_material_transmission_refract_fresnel );
  EXTERN_AND_CALL( expose_IceRay_material_transmission_refract_schlick );
  EXTERN_AND_CALL( expose_IceRay_material_transmission_refract_arbitrary );

  EXTERN_AND_CALL( expose_IceRay_material_transmission_blossom );

  EXTERN_AND_CALL( expose_IceRay_material_transmission_corrector );


  EXTERN_AND_CALL( expose_IceRay_core_object );

  EXTERN_AND_CALL( expose_IceRay_render_Engine            );
  EXTERN_AND_CALL( expose_IceRay_render_pierce__pure      );
  EXTERN_AND_CALL( expose_IceRay_render_pierce_Projector  );
  EXTERN_AND_CALL( expose_IceRay_render_pierce_UV         );

  EXTERN_AND_CALL( expose_IceRay_render_pixel_filter      );
  EXTERN_AND_CALL( expose_IceRay_render_pixel_strategy    );
  EXTERN_AND_CALL( expose_IceRay_render_pixel__pure       );
  EXTERN_AND_CALL( expose_IceRay_render_pixel_Base        );
  EXTERN_AND_CALL( expose_IceRay_render_pixel_UV          );
  EXTERN_AND_CALL( expose_IceRay_render_pixel_constant    );

  EXTERN_AND_CALL( expose_IceRay_render_scanner__pure     );
  EXTERN_AND_CALL( expose_IceRay_render_scanner_Block     );
  EXTERN_AND_CALL( expose_IceRay_render_scanner_Parallel  );

  EXTERN_AND_CALL( expose_IceRay_render_sheaf__pure     );
  EXTERN_AND_CALL( expose_IceRay_render_sheaf_ALL     );


  EXTERN_AND_CALL( expose_IceRay_render_ray__pure     );
  EXTERN_AND_CALL( expose_IceRay_render_ray__base     );
  EXTERN_AND_CALL( expose_IceRay_render_ray_distance  );
  EXTERN_AND_CALL( expose_IceRay_render_ray_C2A       );

 }


