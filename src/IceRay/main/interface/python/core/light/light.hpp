// TODO In progress

#ifndef Dh_DDMRM_IceRay_main_interface_python_HPP
#define Dh_DDMRM_IceRay_main_interface_python_HPP

#include "../../def_submodule.hpp"

#include "IceRay/light/light.hpp"


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

typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_geometry;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;

typedef GS_DDMRM::S_IceRay::S_light::GC_area           GTs_area;
typedef GS_DDMRM::S_IceRay::S_light::GC_disc           GTs_disc;
typedef GS_DDMRM::S_IceRay::S_light::GC_dark           GTs_dark;
typedef GS_DDMRM::S_IceRay::S_light::GC_line           GTs_line;
typedef GS_DDMRM::S_IceRay::S_light::GC_area           GTs_area;
typedef GS_DDMRM::S_IceRay::S_light::GC_sun            GTs_sun;
typedef GS_DDMRM::S_IceRay::S_light::GC_spline         GTs_spline;
typedef GS_DDMRM::S_IceRay::S_light::GC_sphere         GTs_sphere;
typedef GS_DDMRM::S_IceRay::S_light::GC_reflector      GTs_reflector;
typedef GS_DDMRM::S_IceRay::S_light::GC_point          GTs_point;
typedef GS_DDMRM::S_IceRay::S_light::GC_dark           GTs_dark;
typedef GS_DDMRM::S_IceRay::S_light::GC_circle         GTs_circle;
typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier     GTs_chandelier;
typedef GS_DDMRM::S_IceRay::S_light::GC_obstruct       GTs_obstruct;

  }}}}}