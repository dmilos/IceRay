#ifndef _DDMRM_Iceray_geometry__pure_intersect_hpp_
 #define _DDMRM_Iceray_geometry__pure_intersect_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect

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
 
         class GC_intersect
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             enum Ee_status{ En_YES, En_miss, En_far, En_behind };

             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_type::GT_ray              T_ray;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T__base;

           public:
                      GC_intersect(){}
             virtual ~GC_intersect(){}

           public:
             /*
              @param P_lambda -  intact if false == return 
                         New P_lambda must be smaller than supplied
              @param P_state is in undefined state if false; defined if true;
             */
             virtual bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray  const& P_ray )const=0;
          };

        }
      }
    }
  }

#endif
