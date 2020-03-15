#ifndef _DDMM_IceRAY_geometry_intersect_H_
 #define _DDMM_IceRAY_geometry_intersect_H_

#include "../_pure/_base.hpp"
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
         namespace S_CSG
          {

           class GC_intersect
            : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster
            , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
            , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
            , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
            , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_solid
          //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
          //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T_geometry, T__base;

             public:
               GC_intersect();
               GC_intersect( T__base * P_left,  T_location const& P_lo,
                             T__base * P_right, T_location const& P_ro );
              ~GC_intersect( );

             public:
               void    Fv_reset( T_state &P_state )const;
               T_size  Fv_weight( )const;
               T_size const& Fv_id( T_state const&P_state )const;

             public:
               bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const;
               void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
               T_location  Fv_inside   ( T_coord const& P_point/*, T_state &P_state*/ )const;
               T_scalar    Fv_distance ( T_coord const& P_point )const;
               bool        Fv_uvw      ( T_coord & P_uvw, T_coord const& P_point, T_state const &P_state )const;

             public: // cluster
               T_size    const& Fv_quantity( )const;
             public:
               T__base*         Fv_base( T_size const& P_index )const;
               bool             Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const;

             public:
               T_bool           Fv_solid( T_state const& P_state )const;

             public:  // property geometry  left
               T_geometry const*    F_left()const{ return M2_left.M_base; }
               bool                 F_left( T_geometry * P_left );
               bool                 F_left( T_geometry * P_left, T_location const& P_orientation );

             public:  // property geometry  left
               T_geometry const*    F_right()const{ return M2_right.M_base; }
               bool                 F_right( T_geometry * P_right );
               bool                 F_right( T_geometry * P_right, T_location const& P_orientation );

             private:
               enum Ee_side{ En_left, En_right, En_none };

               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster         T2_cluster;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect       T2_intersect;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal          T2_normal;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside          T2_inside;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance        T2_distance;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw             T2_uvw;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_solid           T2_solid;

               struct C2_object
                {
                 T_geometry    *M_base = nullptr;
                 T2_intersect  *M_intersect = nullptr;
                 T2_normal     *M_normal = nullptr;
                 T2_inside     *M_inside = nullptr;
                 T2_distance   *M_distance = nullptr;
                 T2_uvw        *M_uvw = nullptr;
                 T2_cluster    *M_cluster= nullptr;
                 T2_solid      *M_solid= nullptr;

                 T_size         M_tempSize = 0;
                 T_location M_orientation = T_location::En_in;

                 void F_set( T_geometry * P_geometry, T_location const& P_orientation )
                  {
                   M_base      = P_geometry;
                   M_normal    = dynamic_cast<T2_normal   *> ( P_geometry ); if( nullptr == M_intersect) M_normal    = &Fs_vacuum();
                   M_intersect = dynamic_cast<T2_intersect*> ( P_geometry ); if( nullptr == M_normal   ) M_intersect = &Fs_vacuum();
                   M_inside    = dynamic_cast<T2_inside   *> ( P_geometry ); if( nullptr == M_inside   ) M_inside    = &Fs_vacuum();
                   M_distance  = dynamic_cast<T2_distance *> ( P_geometry ); if( nullptr == M_distance ) M_distance  = &Fs_vacuum();
                   M_uvw       = dynamic_cast<T2_uvw      *> ( P_geometry ); if( nullptr == M_uvw      ) M_uvw       = &Fs_vacuum();
                   M_cluster   = dynamic_cast<T2_cluster  *> ( P_geometry ); if( nullptr == M_cluster  ) M_cluster   = &Fs_vacuum();
                   M_solid     = dynamic_cast<T2_solid    *> ( P_geometry ); if( nullptr == M_solid    ) M_solid     = &Fs_vacuum();
                   M_tempSize  = M_base->Fv_weight();
                   M_orientation = P_orientation;
                  }
                };

               T_size        M_intersecMainSize;
               T_size        M_offsetMain;
               T_size        M_offsetLeft;
               T_size        M_offsetRight;

               C2_object M2_left;
               C2_object M2_right;

               void F2_recalc();

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum T_vacuum;
             static T_vacuum & Fs_vacuum();

           public:
             struct C_intersect;

            };
          }
        }
      }
    }
  }

#endif

