#ifndef _DDMM_IceRAY_geometry_simple_disc_H_
 #define _DDMM_IceRAY_geometry_simple_disc_H_

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

       class GC_disc
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

         public:
           GC_disc();
           GC_disc( T_coord  const& P_center, T_coord const& P_normal, T_scalar const& P_radius );
          ~GC_disc( ){}

         public:
           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;

         public:
           bool          Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void          Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location    Fv_inside( T_coord const& P_point/*, T_state const& P_state*/ )const;
           T_scalar      Fv_distance( T_coord const& P_point )const;

         public:  // property scalar  radius
           T_scalar    const& F_radius()const{ return M2_radius; }
           bool               F_radius( T_scalar const& P_radius );
         protected:
           T_scalar        & F1_radius(){ return M2_radius; }
         private:
           T_scalar M2_radius;

         public:  // property coord  normal
           T_coord    const& F_normal()const{ return M2_normal; }
           bool              F_normal( T_coord const& P_normal );
         protected:
           T_coord        & F1_normal(){ return M2_normal; }
         private:
           T_coord M2_normal;

         public:  // property coord  center
           T_coord    const& F_center()const{ return M2_center; }
           bool              F_center( T_coord const& P_center );
         protected:
           T_coord        & F1_center(){ return M2_center; }
         private:
           T_coord M2_center;

        private:
         struct C_intersect;

        };

      }
    }
  }

#endif
