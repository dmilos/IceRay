#ifndef _DDMM_IceRAY_geometry_hyper_H_
 #define _DDMM_IceRAY_geometry_hyper_H_

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {

       class GC_hyperboloid
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
      //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

         public:
           GC_hyperboloid();
           GC_hyperboloid( T_scalar const& P_core );
          ~GC_hyperboloid( );

         public:
           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location  Fv_inside( T_coord const& P_point/*, T_state const& P_state*/ )const;
         //T_scalar    Fv_distance( T_coord const& P_point )const;

         public:  // property scalar  core
           T_scalar  const& F_core()const{ return M2_core; }
           bool             F_core( T_scalar const& P_core );
         protected:
           T_scalar       & F1_core(){ return M2_core; }
         private:
           T_scalar M2_core;

         private:
           struct C_intersect;
           T_scalar  M2_a, M2_b, M2_c;
        };

      }
    }
  }

#endif

