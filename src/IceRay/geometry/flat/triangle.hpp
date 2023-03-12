#ifndef _DDMM_IceRAY_geometry_triangle_H_
 #define _DDMM_IceRAY_geometry_triangle_H_

#include "IceRay/type/math/matrix.hpp"

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"
#include "../_pure/uvw.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {

       class GC_triangle
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;
           typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_matrix             T_matrix;
         public:
           GC_triangle();
           GC_triangle( T_coord const& P_v1, T_coord const& P_v2, T_coord const& P_v3 );
          ~GC_triangle();

         public:
           void    Fv_reset( T_state &P_intersect )const;
           T_size  Fv_weight( )const;

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_intersect )const;
           T_location  Fv_inside( T_coord const& P_point/*, T_state &P_intersect*/ )const;
           T_scalar    Fv_distance( T_coord const& P_point )const;
           bool        Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const&P_intersect )const;

         public:
           T_coord    const& F_origin()const{ return M2_origin; }
           bool              F_origin( T_coord const& P_origin ){ M2_origin = P_origin; return bool( true ); }
         protected:
           T_coord        & F1_origin(){ return M2_origin; }
         private:
           T_coord M2_origin;

         public:  // property coord  e0
           T_coord    const& F_eX()const{ return M1_eX; }
           bool              F_eX( T_coord const& P_e0 );
           bool              F_pX( T_coord const& P_pX );
         protected:
           T_coord         & F1_eX(){ return M1_eX; }
         private:
           T_coord M1_eX;

         public:  // property coord  e1
           T_coord    const& F_eY()const{ return M1_eY; }
           bool              F_eY( T_coord const& P_e1 );
           bool              F_pY( T_coord const& P_pY );
         protected:
           T_coord         & F1_eY(){ return M1_eY; }
         private:
           T_coord M1_eY;

         public:  // property coord  normal
           T_coord    const& F_normal()const{ return M1_normal; }
         protected:
           T_coord  M1_normal;
         private:
           bool F2_setP( T_coord const& P_v1, T_coord const& P_v2, T_coord const& P_v3 );
           bool F2_setV( T_coord const& P_o, T_coord const& P_eX, T_coord const& P_eY );
         private:
           T_coord M2_u, M2_v, M2_w;
         private:
           struct C_intersect;
        };

      }
    }
  }

#endif
