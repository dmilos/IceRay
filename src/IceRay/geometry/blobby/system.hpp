#ifndef _DDMM_IceRAY_geometry_complex_blobby_system_H_
 #define _DDMM_IceRAY_geometry_complex_blobby_system_H_

#include <memory>

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../rtss/_pure.hpp"
#include "./_element.hpp"

#include "./type/coefficient.hpp"
 //#include "./type/heap.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_blobby
        {

         class GC_system
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar              T_coord;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T_geometry;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element       T_element;
             typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure            T_rtss;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::S_type::GC_coefficient T_coefficient;
           //typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::S_type::GC_heap  T_heap;

           public:
             GC_system();
            ~GC_system( );

          public:
             void    Fv_reset( T_state &P_intersect )const;
             T_size  Fv_weight( )const;
           public:
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray )const;
             void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
             T_location  Fv_inside( T_coord const& P_point/*, T_state &P_intersect*/ )const;
             T_scalar    Fv_distance( T_coord const& P_point )const;

           public:
             bool F_push( T_element * P_element );
           public:
             bool F_rtss( T_rtss * P_rtss );
           private:
             T_rtss* M2_rtss;

           private:
             typedef std::vector<T_element*> T2_container;

             T2_container M2_element;
             T_size       M2_compartment;

           private:
             struct C_intersect;

          };
        }
      }
    }
  }

#endif

