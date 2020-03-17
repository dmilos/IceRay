#ifndef Dh_DDMRM_Iceray_material_compute_mapping_HPP_
 #define Dh_DDMRM_Iceray_material_compute_mapping_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GT_ramp
// GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GT_saw
// GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GT_wave


#include "IceRay/material/compute/operation/unary.hpp"
#include "IceRay/utility/mapping.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_mapping
          {

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_identity
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_identity;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2cylindric
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2cylindric;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2package
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2package;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2spherical
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2spherical;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2torus
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2torus;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
               GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2tablecloth
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2tablecloth;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
              GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2woodX
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2woodX;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
              GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2woodY
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2woodY;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
              GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2woodZ
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2woodZ;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cylindric2cartesian
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cylindric2cartesian;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cylindric2spherical
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cylindric2spherical;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_spherical2cartesian
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_spherical2cartesian;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_spherical2cylindric
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_spherical2cylindric;


           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_euclid2max
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_euclid2max;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_max2euclid
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_max2euclid;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
              GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2fisheye
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_cartesian2fisheye;

          }
        }
      }
    }
  }

#endif
