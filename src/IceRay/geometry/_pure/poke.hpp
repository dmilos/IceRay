#ifndef _DDMRM_Iceray_geometry__pure_poke_hpp_
 #define _DDMRM_Iceray_geometry__pure_poke_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_poke

#include "./_base.hpp"

#include "IceRay/type/basic/scalar.hpp"

#include "../_type/ray.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_poke
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             enum Ee_status{ En_YES, En_miss, En_far, En_behind };

             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_type::GT_ray              T_ray;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T__base;

           public:
                      GC_poke(){}
             virtual ~GC_poke(){}

           public:
             /*
              @param P_lambda is there a hit smaller than and larger then 0 ( epsilon )
             */
             virtual bool        Fv_poke( T_scalar const&P_lambda, T_state const&P_state, T_ray const& P_ray )const=0;
          };

        }
      }
    }
  }

#endif
