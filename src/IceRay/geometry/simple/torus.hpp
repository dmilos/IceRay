#ifndef _DDMM_IceRAY_geometry_torus_H_
 #define _DDMM_IceRAY_geometry_torus_H_

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

       class GC_torus
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

         public:
           GC_torus();
           GC_torus( T_scalar const& P_minor );
          ~GC_torus( );

         public:
           void    Fv_reset( T_state &P_intersect )const;
           T_size  Fv_weight( )const;

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location  Fv_inside( T_coord const& P_point/*, T_state const& P_state*/ )const;
           T_scalar    Fv_distance( T_coord const& P_point )const;

         public:  // property scalar  minor
           T_scalar  const& F_minor()const{ return M2_minor; }
           bool             F_minor( T_scalar const& P_minor );
         protected:
           T_scalar       & F1_minor(){ return M2_minor; }
         private:
           T_scalar M2_minor;
         
         private:
           T_scalar M1_pv;
         
         private:
           struct C_intersect;
           static T_scalar M2s_worst;

        };

      }
    }
  }

#endif

