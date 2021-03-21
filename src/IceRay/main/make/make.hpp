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

      extern GTs_geometry * make_spline213( );

      extern GTs_geometry *make_blobby_system( );
      extern bool        make_blobby_system_rtss( GTs_geometry *P_system, GTs_geometry* P_rtss );
      extern bool        make_blobby_system_add( GTs_geometry *P_system, GTs_geometry* P_element );
      extern GTs_geometry *make_blobby_sphere( GTs_coord const& P_center, GTs_scalar const& P_influence, GTs_scalar const& P_radius );
      extern GTs_geometry *make_blobby_usphere( GTs_scalar const& P_radius );
      extern GTs_geometry *make_blobby_ucylinderZ( GTs_scalar const& P_radius );
      extern GTs_geometry *make_blobby_uwaterZ( GTs_scalar const& P_level);
      extern GTs_geometry *make_blobby_translate( GTs_geometry * P_element, GTs_coord const& P_translate );



     }
   }
 }

