#ifndef Dh_DDMRM_Iceray_material_compute_convert_HPP_
 #define Dh_DDMRM_Iceray_material_compute_convert_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GT_scalar2color


#include "IceRay/material/compute/operation/unary.hpp"
#include "IceRay/utility/convert.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_convert
          {

           template < typename N_result, typename N_input >
            using GT_direct = GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
              <
                GS_DDMRM::S_IceRay::S_utility::S_convert::GC_direct< N_result, N_input >
                ,N_result
                ,N_input
              >;

           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_bool    > GT_bool2bool;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_size    > GT_bool2size;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_integer > GT_bool2integer;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_scalar  > GT_bool2scalar;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_scalar  > GT_bool2color;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_scalar  > GT_bool2Coord2D;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_scalar  > GT_bool2Coord3D;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_bool,   GS_DDMRM::S_IceRay::S_type::GT_scalar  > GT_bool2Coord4D;

           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_bool    > GT_size2bool;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_size    > GT_size2size;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_integer > GT_size2integer;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_scalar  > GT_size2scalar;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_bool    > GT_size2color;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_bool    > GT_size2Coord2D;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_bool    > GT_size2Coord3D;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_size,   GS_DDMRM::S_IceRay::S_type::GT_bool    > GT_size2Coord4D;

           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool   > GT_scalar2bool;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_size   > GT_scalar2size;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_scalar > GT_scalar2scalar;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool   > GT_scalar2color;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool   > GT_scalar2Coord2D;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool   > GT_scalar2Coord3D;

         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool > GT_color2bool;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_size > GT_color2size;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_size > GT_color2scalar;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool > GT_color2color;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool > GT_color2Coord2D;
         //typedef GT_direct< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_bool > GT_color2Coord3D;

           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D, GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D > GT_coord2D2coord2D;
           typedef GT_direct< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D, GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D > GT_coord3D2coord3D;


           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_convert::GC_bool2color
               ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::GT_bool
             > GT_bool2color;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
               GS_DDMRM::S_IceRay::S_utility::S_convert::GC_scalar2color
               ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
             > GT_scalar2color;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_convert::GC_color2bool
               ,GS_DDMRM::S_IceRay::S_type::GT_bool
               ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
             > GT_color2bool;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_convert::GC_color2scalar
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
             > GT_color2scalar;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_convert::GC_color2coord
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
             > GT_color2coord3D;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_convert::GC_coord2color
               ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar
             > GT_coord3D2color;

           // TODO typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
           // TODO   <
           // TODO      GS_DDMRM::S_IceRay::S_utility::S_convert::GC_rgb2hsl
           // TODO     ,GS_DDMRM::S_IceRay::S_type::S_color::GT_rgb
           // TODO     ,GS_DDMRM::S_IceRay::S_type::S_color::GT_hsl
           // TODO   > GT_color2color;

         }
        }
      }
    }
  }

#endif
