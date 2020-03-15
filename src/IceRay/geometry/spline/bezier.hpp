#ifndef _DDMM_IceRAY_geometry_bezier_H_
 #define _DDMM_IceRAY_geometry_bezier_H_

#include <array>

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"
#include "../_pure/uvw.hpp"

#include "../../util/bound/box.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_spline
        {

        class GC_bezier
         : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
         , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
         , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
         , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
         , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

          public:
            GC_spline();
            GC_spline( T_struct const& P_struct );
           ~GC_spline( );

          public:
            void    Fv_reset( T_state &P_intersect )const;
            T_size  Fv_weight( )const;

          public:
            bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
            void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
            T_location  Fv_inside   ( T_coord const& P_point/*, T_state &P_state*/ )const;
            T_scalar    Fv_distance ( T_coord const& P_point )const;
            bool        Fv_uvw      ( T_coord & P_uvw, T_coord const& P_point, T_state const&P_state )const;

          private:
            typedef TODO  T_struct;

            typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar2D         T2_interval;

            struct C2_item
             {
              T_struct         M_struct;
              T_interval2D     M_interval2D;
              T_interval3D     M_box;
              bool             M_used;
              bool             M_hit;
              T_scalar         M_lambda;
             };

            T_struct M2_struct;
            mutable std::vector< C2_item  > M2_stack;
          private:
            static bool F2s_smal( T_interval const& P_interval );
         };

      }
    }
  }

#endif
