#ifndef Dh_IceRay_material_pattern_side_cube_hpp_
 #define Dh_IceRay_material_pattern_side_cube_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_side_cube

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

           class GC_cube
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_cube()
                {
                }

               ~GC_cube()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 switch( ::math::linear::vector::dominant( P_coord ).first )
                  {
                   case(0): if( P_coord[0] < 0 ) P_result += 4; break;
                   case(1): if( P_coord[1] < 0 ) P_result += 4; break;
                   case(2): if( P_coord[2] < 0 ) P_result += 4; break;
                  }
                }

            };

           }
        }
      }
    }
  }

#endif
