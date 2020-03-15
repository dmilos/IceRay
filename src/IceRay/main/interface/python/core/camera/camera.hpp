#ifndef Dh_DDMRM_IceRay_main_interface_python_HPP
#define Dh_DDMRM_IceRay_main_interface_python_HPP

#include "../../def_submodule.hpp"

#include "IceRay/camera/camera.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_main
      {
       namespace S_interface
        {
         namespace S_python
          {

typedef GS_DDMRM::S_IceRay::S_type::GT_size                   GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                 GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D      GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D      GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D   GTs_interval1D;
typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D     GTs_matrix3D;
typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D     GTs_affine3D;

typedef GS_DDMRM::S_IceRay::S_camera::GC__pure       GTs__pure;
typedef GS_DDMRM::S_IceRay::S_camera::GC__parent     GTs__parent;

typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus              GTs_focus;
typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone               GTs_cone;
typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal        GTs_orthogonal;
typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective       GTs_perspective;


  }}}}}

#endif

