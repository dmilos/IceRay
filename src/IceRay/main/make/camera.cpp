#include "IceRay/camera/transform/transform.hpp"
#include "IceRay/camera/sphere/vertical.hpp"
#include "IceRay/camera/invert.hpp"
#include "IceRay/camera/flat/orthogonal.hpp"
#include "IceRay/camera/dof/focus.hpp"
#include "IceRay/camera/dof/cone.hpp"
#include "IceRay/camera/cylinder/vertical.hpp"
#include "IceRay/camera/_pure.hpp"
#include "IceRay/camera/flat/perspective.hpp"



typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar  GTs_coord;
typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D  Gts_affine;
typedef GS_DDMRM::S_IceRay::S_type::GT_size  GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar           GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_camera::GC__pure         GTs_camera;


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {

GTs_camera *make_camera_cone( GTs_camera *P_camera, GTs_size const& P_sample, GTs_scalar const& P_aperture, GTs_scalar const& P_gauss  )
  {
   typedef GS_DDMRM::S_IceRay::S_camera::GC_cone Tf_cone;

   Tf_cone *Ir_cone = new Tf_cone( P_camera, P_sample, P_aperture, P_gauss );

   return Ir_cone;
  }

GTs_camera *make_camera_cylinder( GTs_scalar const& P_angle, GTs_scalar const& P_radius )
  {
   typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_cylinder;

   Tf_cylinder *Ir_cylinder = new Tf_cylinder( P_angle, P_radius );

   return Ir_cylinder;
  }

GTs_camera *make_camera_focus( GTs_camera *P_camera, GTs_size const& P_sample, GTs_scalar const& P_aperture, GTs_scalar const& P_focus, GTs_scalar const& P_gauss  )
  {
   typedef GS_DDMRM::S_IceRay::S_camera::GC_focus Tf_focus;

   Tf_focus *Ir_focus = new Tf_focus
    (
     P_camera,
     P_sample,
     Tf_focus::T_interval1D( P_aperture, P_aperture),
     Tf_focus::T_interval1D( P_focus, P_focus),
     P_gauss
     );

   return Ir_focus;
  }


GTs_camera *make_camera_invert( GTs_camera *P_camera )
  {
   typedef GS_DDMRM::S_IceRay::S_camera::GC_invert Tf_invert;

   Tf_invert *Ir_invert = new Tf_invert();

   Ir_invert->F_child( P_camera );

   return Ir_invert;
  }


GTs_camera *make_camera_lookAt( GTs_camera *P_camera, GTs_coord const& P_eye, GTs_coord const& P_view, GTs_coord const& P_up )
  {
   typedef GS_DDMRM::S_IceRay::S_camera::GC_transform Tf_transform;

   Tf_transform *Ir_transform = new Tf_transform();

   Gts_affine I_world;

   ::math::linear::affine::look_at( I_world, P_eye, P_view, P_up );

   Ir_transform->F_2world( I_world );

   Ir_transform->F_child( P_camera );

   return Ir_transform;
  }

GTs_camera *make_camera_othogonal(  )
  {
   typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal Tf_othogonal;

   Tf_othogonal *Ir_othogonal = new Tf_othogonal();

   return Ir_othogonal;
  }

GTs_camera *make_camera_perspective()
  {
   typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective Tf_perspective;

   Tf_perspective *Ir_perspective = new Tf_perspective( );

   return Ir_perspective;
  }

GTs_camera *make_camera_sphere( GTs_scalar const& P_phi, GTs_scalar const& P_theta )
  {
   typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_sphere;

   Tf_sphere *Ir_sphere = new Tf_sphere( P_phi, P_theta );

   return Ir_sphere;
  }

     }
   }
 }