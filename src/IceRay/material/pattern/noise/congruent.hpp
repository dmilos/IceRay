#ifndef Dh_IceRay_material_pattern_noise_congruen3d_hpp_
 #define Dh_IceRay_material_pattern_noise_congruen3d_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_noise_congruen3d

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
         namespace S_noise
          {

           class GC_congruent1d
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_congruent1d()
                {
                }

               ~GC_congruent1d()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 M2_generator.next( P_result );
                }
             public:
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_congruent1D M2_generator;
            };

           class GC_congruent2d
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord2D
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_congruent2d()
                {
                }

               ~GC_congruent2d()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 M2_generator.next( P_result );
                }
             public:
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_congruent2D M2_generator;
            };

           class GC_congruent3d
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord3D
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_congruent3d()
                {
                }

               ~GC_congruent3d()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 M2_generator.next( P_result );
                }
             public:
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_congruent3D M2_generator;
            };

          }
        }
      }
    }
  }

#endif
