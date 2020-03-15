#ifndef Dh_IceRay_material_pattern_side_octahedron_hpp_
 #define Dh_IceRay_material_pattern_side_octahedron_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_side_octahedron

#include "../_pure.hpp"

#include <iostream>
#include <iomanip>





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {
         namespace S_side
          {

           class GC_octahedron
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_octahedron()
                {
                }

               ~GC_octahedron()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 P_result = 0;
                 P_result = P_result | ( 0 < P_coord[0] ? 1: 0 );
                 P_result = P_result | ( 0 < P_coord[1] ? 2: 0 );
                 P_result = P_result | ( 0 < P_coord[2] ? 4: 0 );
                }

            };

           }
        }
      }
    }
  }

#endif
