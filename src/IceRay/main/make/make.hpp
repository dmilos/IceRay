#include "IceRay/type/basic\string.hpp"
#include "IceRay/type/basic\size.hpp"
#include "IceRay/type/basic\scalar.hpp"
#include "IceRay/type/basic\report.hpp"
#include "IceRay/type/basic\integer.hpp"
#include "IceRay/type/basic\bool.hpp"

#include "IceRay/type/math/matrix.hpp"
#include "IceRay/type/math/interval.hpp"
#include "IceRay/type/math/coord.hpp"
#include "IceRay/type/math/affine.hpp"

#include "IceRay/type/color.hpp"

#include "IceRay/light/type/spot.hpp"
#include "IceRay/light/_pure.hpp"
#include "IceRay/light/chandelier.hpp"
#include "IceRay/geometry/_pure/_base.hpp"
#include "IceRay/camera/_pure.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {

      typedef GS_DDMRM::S_IceRay::S_type::GT_size            GTs_size;
      typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          GTs_scalar;
      typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar GTs_color;

      typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     GTs_coord;
      typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size       GTs_dimension;

      typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D  GTs_matrix;
      typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D  GTs_affine;
      typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D  GTs_matrix4D;

      typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      GTs_spot;
      typedef GS_DDMRM::S_IceRay::S_light::GC__pure             GTs_light;
      typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier        GTs_chandelier;

      typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_geometry;
      typedef GS_DDMRM::S_IceRay::S_camera::GC__pure            GTs_camera;
      typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure    GTs_pigment;


      extern GTs_color     make_color( GTs_scalar P_r, GTs_scalar P_g, GTs_scalar P_b );
      extern GTs_coord     make_coord3( GTs_scalar P_x, GTs_scalar P_y, GTs_scalar P_z );
      extern GTs_coord     make_coord3_unit( GTs_scalar P_x, GTs_scalar P_y, GTs_scalar P_z );
      extern GTs_dimension make_dimension( GTs_size P_x,GTs_size P_y,GTs_size P_z );

      extern GTs_geometry * make_sphere( GTs_coord const& P_center, GTs_scalar const& P_radius );
      extern GTs_geometry * make_box( GTs_coord const& P_lo, GTs_coord const& P_hi );
      extern GTs_geometry * make_cone( GTs_coord const& P_top, GTs_coord const& P_bottom, GTs_scalar const& P_radius  );
      extern GTs_geometry * make_cylinder( GTs_coord const& P_top, GTs_coord const& P_bottom, GTs_scalar const& P_radius  );
      extern GTs_geometry * make_paraboloid( GTs_coord const& P_top, GTs_coord const& P_bottom, GTs_scalar const& P_radius  );
      extern GTs_geometry * make_affine( GTs_geometry *, GTs_matrix const& , GTs_coord const& );
      extern GTs_geometry * make_triangle( GTs_coord const& P_0, GTs_coord const& P_1, GTs_coord const& P_2 );
      extern GTs_geometry * make_csg_intersect( GTs_geometry * P_left,  GTs_geometry * P_right  );
      extern GTs_geometry * make_mblur( GTs_geometry * P_child, GTs_coord const& P_move );
      extern GTs_geometry * make_smoke( GTs_coord const& P_lo, GTs_coord const& P_hi );
      extern GTs_geometry * make_torus( GTs_scalar const& P_minor  );
      extern GTs_geometry * make_disc( GTs_coord const& P_center, GTs_coord const& P_normal, GTs_scalar const& P_radius );
      extern GTs_geometry * make_plane( GTs_coord const& P_pivot, GTs_coord const& P_normal );
      extern GTs_geometry * make_spline213( );

      extern GTs_geometry *make_blobby_system( );
      extern bool        make_blobby_system_rtss( GTs_geometry *P_system, GTs_geometry* P_rtss );
      extern bool        make_blobby_system_add( GTs_geometry *P_system, GTs_geometry* P_element );
      extern GTs_geometry *make_blobby_sphere( GTs_coord const& P_center, GTs_scalar const& P_influence, GTs_scalar const& P_radius );
      extern GTs_geometry *make_blobby_usphere( GTs_scalar const& P_radius );
      extern GTs_geometry *make_blobby_ucylinderZ( GTs_scalar const& P_radius );
      extern GTs_geometry *make_blobby_uwaterZ( GTs_scalar const& P_level);
      extern GTs_geometry *make_blobby_translate( GTs_geometry * P_element, GTs_coord const& P_translate );

      extern GTs_size     rtss_add( GTs_geometry * P_rtss, GTs_geometry * P_child );
      extern void         rtss_done( GTs_geometry * P_rtss );

      extern GTs_geometry * make_rtss_list();
      extern GTs_geometry * make_rtss_uniform( GTs_dimension const& P_dimension );
      extern GTs_geometry * make_rtss_object();
      extern GTs_geometry * make_rtss_object( GTs_geometry * P_object );

      extern GTs_spot    make_light_spot( GTs_coord const& P_center, GTs_color const& P_x );
      extern GTs_spot    make_light_spot( GTs_coord const& P_center, GTs_color const& P_0,  GTs_color const& P_1, GTs_color const& P_2  );
      extern GTs_spot    make_light_spot( GTs_coord const& P_center );
      extern GTs_light * make_light_point( GTs_coord const& P_center );
      extern GTs_light * make_light_point( GTs_spot const& P_spot );
      extern GTs_light * make_light_chandelier( GTs_chandelier::T_container const& P_cotainer );
      extern GTs_light * make_light_circle( GTs_spot const& P_spot, GTs_coord const&  P_x,GTs_coord const&  P_y );
      extern GTs_light * make_light_area( GTs_spot const& P_spot, GTs_coord const&  P_x, GTs_coord const&  P_y );
      extern GTs_light * make_light_disc( GTs_spot const& P_spot, GTs_coord const&  P_x, GTs_coord const&  P_y );
      extern GTs_light * make_light_reflector( GTs_spot const& P_spot, GTs_coord const& P_direction, GTs_scalar const& P_in, GTs_scalar const& P_out );
      extern GTs_light * make_light_sun( GTs_spot const& P_spot );
      extern GTs_light * make_light_line( GTs_spot const& P_spot, GTs_coord const& P_end );
      extern GTs_light * make_light_spline( GTs_spot const& P_spot, GTs_coord const& P_1, GTs_coord const& P_2, GTs_coord const& P_3 );

      extern GTs_pigment *make_ambient(    GTs_geometry *,  GTs_color const& P_color );
      extern GTs_pigment *make_lambert(    GTs_geometry * , GTs_light *, GTs_color const& P_diffuse );
      extern GTs_pigment *make_phong(      GTs_geometry * , GTs_light *, GTs_color const& P_specular,   GTs_color const& P_shininess );
      extern GTs_pigment *make_blinn(       GTs_geometry * , GTs_light * , GTs_color const& P_specular, GTs_color const& P_shininess );
      extern GTs_pigment *make_gaussian(   GTs_geometry * , GTs_light *  , GTs_color const&P_specular,  GTs_color const& P_smoothness );
      extern GTs_pigment *make_beckmann(   GTs_geometry *,GTs_light *, GTs_color const&P_specular, GTs_color const& P_roughness );
      extern GTs_pigment *make_HeidrichSeidel_lambert( GTs_geometry *, GTs_light * P_light, GTs_coord const& P_groove, GTs_color const&P_diffuse );
      extern GTs_pigment *make_HeidrichSeidel_phong(   GTs_geometry *, GTs_light * P_light, GTs_coord const& P_groove, GTs_color const& P_specular, GTs_color const& P_exponent );
      extern GTs_pigment *make_on_p44( GTs_geometry   * P_geometry, GTs_light      * P_light, GTs_color const& P_A, GTs_color const& P_B );
      extern GTs_color   compute_on_p44_A( GTs_color const& P_sigma );
      extern GTs_color   compute_on_p44_B( GTs_color const& P_sigma );

      extern GTs_pigment *make_ward_approx(    GTs_geometry  * P_geometry, GTs_light * P_light, GTs_coord const& P_direction, GTs_color const& P_specular, GTs_color const& P_alphaX, GTs_color const& P_alphaY );
      extern GTs_pigment *make_ward_real(      GTs_geometry  * P_geometry, GTs_light * P_light, GTs_coord const& P_direction, GTs_color const& P_specular, GTs_color const& P_alphaX, GTs_color const& P_alphaY );
      extern GTs_pigment *make_ward_isotropic( GTs_geometry  * P_geometry, GTs_light * P_light, GTs_color const& P_specular, GTs_color const& P_alpha );

     }
   }
 }

