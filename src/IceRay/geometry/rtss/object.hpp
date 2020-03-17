#ifndef _DDMM_IceRAY_geometry_rtss_object_H_
 #define _DDMM_IceRAY_geometry_rtss_object_H_

//  GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object

#include <vector>

#include "./_pure.hpp"
#include "./list.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_RTSS
        {

         class GC_object
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_pierce
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_valid
          {
           public: // Not a RTSS!!!

             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base     T__base;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure      T_rtss;

           public:
              GC_object( );
              GC_object( T_rtss *P_rtss );
             ~GC_object( );

           public: // base
             void    Fv_reset( T_state &P_state )const;
             T_size  Fv_weight( )const;
             T_size const& Fv_id( T_state const&P_state )const;

           public: // Other elements
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
             void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const;
             T_location  Fv_inside(    T_coord const& P_point/*, T_state &P_state */ )const;
             T_scalar    Fv_distance(  T_coord const& P_point )const;
             bool        Fv_uvw(       T_coord & P_uvw, T_coord const& P_point, T_state const& P_state)const;

          public: // cluster
             T_size    const& Fv_quantity( )const;
           private:
             mutable T_size       M2_cdwewewews;
           public:
             T__base*         Fv_base( T_size const& P_index )const;
             bool             Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const;

           public:
             T_size F_push( T__base * P_object );
             void   F_erase( T__base  * P_object );
             void   F_clear();
             void   F_optimize();
           public:
             T_rtss *    F_rtss();
             bool        F_rtss( T_rtss *P_rtss );
           private:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_list T2_list;
             T_rtss    *M2_rtss;
             T2_list   M2_list;

           private:
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect    T2_intersect;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal       T2_normal;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside       T2_inside;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance     T2_distance;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw          T2_uvw;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster      T2_cluster;

             struct C2_geometry
              {
               T__base      *M__base;
               T2_intersect *M_intersect;
               T2_normal    *M_normal;
               T2_inside    *M_inside;
               T2_distance  *M_distance;
               T2_uvw       *M_uvw;
               T2_cluster   *M_cluster;
             //T2_piearce   *M_pierce;
             //T2_valid     *M_valid;
               T_size        M_intersectSize;
              };

             typedef  std::vector<C2_geometry> T2_container;

           public:
             T2_container    const& F_container()const{ return M2_container; }
           protected:
             T2_container        & F1_container(){ return M2_container; }
           private:
             T2_container M2_container;

           private:
             struct C_intersect;
         };

       }
     }
   }
 }

#endif
