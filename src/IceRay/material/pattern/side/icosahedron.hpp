#ifndef Dh_IceRay_material_pattern_side_icosahedron_hpp_
 #define Dh_IceRay_material_pattern_side_icosahedron_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_side_icosahedron

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

           class GC_icosahedron
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_icosahedron()
                {
                }

               ~GC_icosahedron()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 // TODO
                 P_result = rand()/ (T_scalar)RAND_MAX;
                }

            };

           }
        }
      }
    }
  }

#endif
