#ifndef Dh_IceRay_material_pattern_wave_hpp_
 #define Dh_IceRay_material_pattern_wave_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_wave

#include "./_pure.hpp"







 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_waveSin
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {
           public:

             GC_waveSin()
              {
              }

           public:
            void  Fv_process( T_result &P_result, T_coord const& P_coord )const
             {
              P_result = ( cos( P_coord[ 0 ]* ::math::constants::PHI + ::math::constants::PHI )+T_scalar(1))/T_scalar(2);
             }

          };

         class GC_waveSaw
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {
           public:

             GC_waveSaw()
              {
              }

           public:
            void  Fv_process( T_result &P_result, T_coord const& P_coord )const
             {
              P_result = ::math::function::wave(P_coord[0]  );
             }

          };


        }
      }
    }
  }

#endif
