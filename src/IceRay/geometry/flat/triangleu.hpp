#ifndef _DDMM_IceRAY_geometry_triangleU_H_
 #define _DDMM_IceRAY_geometry_triangleU_H_

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

       class GC_triangleU
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
           GC_triangleU();
          ~GC_triangleU();

         public:
           void    Fv_reset( T_state &P_intersect )const;
           T_size  Fv_weight( )const;

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_intersect )const;
           T_location  Fv_inside( T_coord const& P_point/*, T_state &P_intersect*/ )const;
           T_scalar    Fv_distance( T_coord const& P_point )const;
           bool        Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const&P_intersect )const;

         private:
           struct C_intersect;
        };

      }
    }
  }

#endif
