#ifndef _DDMM_IceRAY_geometry_complex_identity_H_
 #define _DDMM_IceRAY_geometry_complex_identity_H_

#include "../../type/basic/scalar.hpp"
#include "../../type/math/coord.hpp"




#include "../_pure/_base.hpp"
#include "../_pure/cluster.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"
#include "../_pure/uvw.hpp"


#include "../volumetric/vacuum.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_complex
        {

         class GC_enclose
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_matrix    T_matrix;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  T_geometry, T__base;

           public:
             GC_enclose( );
             explicit GC_enclose( T__base *P_child, T__base *P_hull = nullptr );
            ~GC_enclose( );

           public:
             void    Fv_reset( T_state &P_state )const;
             T_size  Fv_weight( )const;
             T_size const& Fv_id( T_state const&P_state )const;

           public:
             T_size const&    Fv_quantity()const;
             T__base*         Fv_base( T_size const& P_index )const;
             bool             Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const;
             bool             Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
             void             Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const;
             T_location       Fv_inside( T_coord const& P_point/*, T_state const&P_state*/ )const;
             T_scalar         Fv_distance( T_coord const& P_point )const;
             bool             Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const& P_state)const;

          private:
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect    T2_intersect;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal       T2_normal;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside       T2_inside;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance     T2_distance;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw          T2_uvw;
          public:
              T__base const& F_hull( )const;
              bool F_hull( T__base * P_hull  );
           private:
             struct C2_hull
              {
               T_size        M_weight;
               T__base      *M__base;
               T2_intersect *M_intersect;
               T2_inside    *M_inside;
               T2_distance  *M_distance;
              };
             C2_hull  M2_hull;

           public:
               T__base const& F_child( )const;
               bool  F_child( T__base *P_child );

           private:
             struct C2_child
              {
               T_size        M_weight;
               T__base      *M__base;
               T2_intersect *M_intersect;
               T2_inside    *M_inside;
               T2_distance  *M_distance;
              };
             C2_child  M2_child;

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum T_vacuum;
             static T_vacuum & Fs_vacuum();
           private:
             struct C_intersect;
          };

        }
      }
    }
  }

#endif
