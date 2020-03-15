#ifndef _DDMM_IceRAY_geometry_rtss__pure_H_
 #define _DDMM_IceRAY_geometry_rtss__pure_H_
// GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/cluster.hpp"
#include "../../type/math/coord.hpp"

#include "../volumetric/vacuum.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_RTSS
        {

         class GC__pure
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  T__base;

             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar       T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                  T_size;

             typedef std::vector<T_size>    T_list; //!< TODO change name
           //typedef std::vector<T__base*>  T_container;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect  T_intersect;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster    T_cluster;

           public:
                      GC__pure( );
             virtual ~GC__pure( );

           public:
             virtual T_size const& Fv_quantity()const=0;
             virtual T_size        Fv_push( T__base * P_object )=0;
             virtual void          Fv_erase( T__base * P_object )=0;
             virtual void          Fv_clear()=0;
             virtual void          Fv_optimize()=0;

             virtual T_list      const& Fv_owners( T_coord const& P_point )const=0;
             virtual void               Fv_prepare( T_coord const& P_point, T_state & P_state )const=0;

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum T_vacuum;
             static T_vacuum & Fs_vacuum();
          };

       }
     }
   }
 }
#endif
