#ifndef _DDMRM_IceRAY_geometry_blobby__element_HPP_
 #define _DDMRM_IceRAY_geometry_blobby__element_HPP_

  //GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element

#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"

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

         class GC_system;

         class GC__element
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance //!< Actualy density
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar              T_coord;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T_geometry;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::S_type::GC_coefficient T_coefficient;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system        T_system;
           //typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::S_type::GC_heap  T_heap;

           public:
             GC__element(){}
            ~GC__element(){}

             virtual bool     Fv_coefficient( T_coefficient::T_typedef & P_coefficient, T_state const& P_state, T_ray const& P_ray )const=0;
             virtual T_scalar Fv_intensity( T_coord const& P_poin )const=0;

          };
        }
      }
    }
  }

#endif

