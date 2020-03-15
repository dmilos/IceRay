#ifndef Dh_IceRay_material_pattern_onion_hpp_
 #define Dh_IceRay_material_pattern_onion_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_onion

#include "./_pure.hpp"







 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_onion
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {// DONE
           public:
             explicit GC_onion( T_coord const& P_center = ::math::linear::vector::fill( T_coord{}, 0 ) )
              :M2_center( P_center )
              {
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               P_result = ::math::linear::vector::distance( M2_center, P_coord );
              }

           private:
             T_coord M2_center;
          };

        }
      }
    }
  }

#endif
