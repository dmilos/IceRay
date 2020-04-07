#ifndef _DDMM_IceRAY_geometry_sphere_H_
 #define _DDMM_IceRAY_geometry_sphere_H_

// GS_DDMRM::S_IceRay::S_geometry::GC_sphere


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

       class GC_sphere
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

         public:
           GC_sphere();
           GC_sphere( T_coord const& P_center, T_scalar const& P_radius = T_scalar( 1 ) );
          ~GC_sphere( );

         public:
           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;
           bool    Fv_box( T_box const& P_box );

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location  Fv_inside   ( T_coord const& P_point/*, T_state const& P_state*/ )const;
           T_scalar    Fv_distance ( T_coord const& P_point )const;

         public:  // property coord  center
           T_coord    const& F_center()const{ return M2_center; }
           bool              F_center( T_coord const& P_center );
         protected:
           T_coord        & F1_center(){ return M2_center; }
         private:
           T_coord M2_center;

         public:  // property scalar  radius
           T_scalar const& F_radius()const{ return M2_radius; }
           bool            F_radius( T_scalar const& P_radius );
         protected:
           T_scalar        & F1_radius(){ return M2_radius; }
         private:
           T_scalar M2_radius;

         private:
           T_scalar M1_r2 ;
           T_scalar M1_o_r;

         private:
           struct C_intersect;
        };

      }
    }
  }

#endif
