#ifndef Dh_IceRay_material_pattern_side_dodecahedron_hpp_
 #define Dh_IceRay_material_pattern_side_dodecahedron_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_side_dodecahedron

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

           class GC_dodecahedron
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_dodecahedron()
                {
                }

               ~GC_dodecahedron()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 //for( P_result = 0; P_result < M2_pyramid.size(); ++P_result )
                 // {
                 //  if( true == M2_pyramid.Fv_process( P_coord ) )
                 //   {
                 //    return;
                 //   }
                 // }
                 P_result = 0;
                }
             public:
              //std::array<T_pyramid, 12*3> M2_pyramid;
            };

           }
        }
      }
    }
  }

#endif
