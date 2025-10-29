#ifndef _DDMRM_Iceray_geometry__pure_pierce_hpp_
#define _DDMRM_Iceray_geometry__pure_pierce_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_pierce

#include "./intersect.hpp"

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

         class GC_pierce
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          {
           public:
             enum Ee_status{ En_YES, En_miss, En_far, En_behind };

             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GT_ray              T_ray;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T__base;

                      GC_pierce(){}
             virtual ~GC_pierce(){}

             // @desc found at least count of intersection along the ray
             // @return number of piercing.
             // @param P_lambda[0] -  bound
             //            New P_lambda[x] must be smaller than supplied
             // @param P_state is in undefined state if return == 0; defined if 0 != return;
             virtual T_size        Fv_pierce( T_size const& P_count, T_scalar* P_lambda, T_state &P_state, T_ray  const& P_ray )const
              {
               T_ray I_ray = P_ray;
               T_scalar I_begin = 0;
               T_scalar I_end = P_lambda[0];
               T_scalar I_lambda;
               T_size Ir_count=0;
               while( true )
                {
                 I_lambda = I_end;
                 if( false == Fv_intersect( I_lambda, P_state, I_ray ) )
                  {
                   break;
                  }
                  P_lambda[Ir_count] = I_lambda + I_begin;

                  ++Ir_count;
                  if( Ir_count == P_count )
                   {
                    break;
                   }

                  ::math::linear::vector::combine( I_ray.M_origin, I_ray.M_origin, I_lambda, I_ray.M_direction );
                  I_end -= I_lambda;
                  I_begin += I_lambda;
                }

                return Ir_count;
              }

          };

        }
      }
    }
  }

#endif
