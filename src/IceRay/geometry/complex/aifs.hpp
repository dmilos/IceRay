#ifndef _DDMM_IceRAY_geometry_IFS_H_
 #define _DDMM_IceRAY_geometry_IFS_H_

#include "../_pure/_base.hpp"
#include "../_pure/cluster.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"
#include "../_pure/uvw.hpp"
#include "../_pure/transform.hpp"

#include "../volumetric/vacuum.hpp"

#include "IceRay/type/math/matrix.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_complex
        {

         class GC_AIFS
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_transform
         {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T_geometry, T__base;

             typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D           T_matrix;
             typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D           T_affine;

           public:
             GC_AIFS();
            ~GC_AIFS( );

           public:
             void    Fv_reset( T_state &P_state )const;
             T_size  Fv_weight( )const;
             T_size const& Fv_id( T_state const&P_state )const;

           public: // intersect, normal, inside, distance, uvw
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const;
             void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
             T_location  Fv_inside   ( T_coord const& P_point/*, T_state const&P_state*/ )const;
             T_scalar    Fv_distance ( T_coord const& P_point )const;
             bool        Fv_uvw      ( T_coord & P_uvw, T_coord const& P_point, T_state const &P_state )const;
             T_affine const&  Fv_2world( T_state const&P_state )const;
             T_affine const&  Fv_2local( T_state const&P_state )const;

           public: // cluster
             T_size    const& Fv_quantity( )const;
           private:
             mutable T_size  M2_size;
           public: // cluster
             T__base*         Fv_base( T_size const& P_index )const;
             bool             Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const;

           public: // max depth to follow
             T_size    const& F_depth( )const;
             bool             F_depth( T_size const& P_depth );
           private:
             T_size    M2_depth;

           public:
             T_size    F_push( T_affine const& P_2world, T_geometry * P_geometry );
             bool      F_erase( T_size const& P_index );

             // TODO size, container, etc.
           private:
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster         T2_cluster;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect       T2_intersect;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal          T2_normal;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside          T2_inside;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance        T2_distance;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw             T2_uvw;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_transform       T2_transform;

             struct C2_geometry
              {
               T_geometry    *M__base = nullptr;
               T2_intersect  *M_intersect = nullptr;
               T2_normal     *M_normal = nullptr;
               T2_inside     *M_inside = nullptr;
               T2_distance   *M_distance = nullptr;
               T2_uvw        *M_uvw = nullptr;
               T2_cluster    *M_cluster= nullptr;
               T2_transform  *M_transform= nullptr;
               T_size         M_weight;

               void F_set( T_geometry * P_geometry )
                {
                 M__base     = P_geometry;
                 M_normal    = dynamic_cast<T2_normal   *> ( P_geometry ); if( nullptr == M_normal   ) M_normal    = &Fs_vacuum();
                 M_intersect = dynamic_cast<T2_intersect*> ( P_geometry ); if( nullptr == M_intersect) M_intersect = &Fs_vacuum();
                 M_inside    = dynamic_cast<T2_inside   *> ( P_geometry ); if( nullptr == M_inside   ) M_inside    = &Fs_vacuum();
                 M_distance  = dynamic_cast<T2_distance *> ( P_geometry ); if( nullptr == M_distance ) M_distance  = &Fs_vacuum();
                 M_uvw       = dynamic_cast<T2_uvw      *> ( P_geometry ); if( nullptr == M_uvw      ) M_uvw       = &Fs_vacuum();
                 M_cluster   = dynamic_cast<T2_cluster  *> ( P_geometry ); if( nullptr == M_cluster  ) M_cluster   = &Fs_vacuum();
                 M_transform = dynamic_cast<T2_transform*> ( P_geometry ); if( nullptr == M_transform) M_transform = &Fs_vacuum();
                 M_weight    = M__base->Fv_weight();
                }
              };

           private:
             struct C2_object
              {
               C2_geometry  M_geometry;
               T_affine M_2world;
              };
             typedef  std::vector<C2_object> T2_level;
             T2_level M2_collection;

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum T_vacuum;
             static T_vacuum & Fs_vacuum();

           private:
             T_size M2_compartment;
           private:
             struct C_intersect;
          };

        }
      }
    }
  }

#endif

