#ifndef Dh_DDMRM_Iceray_utility_clamp_HPP_
 #define Dh_DDMRM_Iceray_utility_clamp_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_ramp
 // GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_saw
 // GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_wave

#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_clamp
        {

         class GC_ramp
          {
           public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
            T_scalar   operator()( T_scalar const&P_value )const
             {
              return ::math::function::ramp(P_value);
             }
          };

         class GC_saw
          {
           public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
            T_scalar   operator()( T_scalar const&P_value )const
             {
              return ::math::function::saw(P_value);
             }
          };

         class GC_wave
          {
           public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
            T_scalar   operator()( T_scalar const&P_value )const
             {
              return ::math::function::wave(P_value);
             }
          };

        }
      }
    }
  }

#endif
