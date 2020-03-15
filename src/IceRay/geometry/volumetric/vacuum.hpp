#ifndef _DDMM_IceRAY_object_vacuum_H_
 #define _DDMM_IceRAY_object_vacuum_H_

#include "../_pure/_base.hpp"
#include "../_pure/cluster.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/uvw.hpp"
#include "../_pure/distance.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/transform.hpp"
//#include "../_pure/pierce.hpp"
 //#include "../_pure/valid.hpp"
#include "../_pure/solid.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {

       class GC_vacuum
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_transform
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_solid
      //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_pierce
      //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_valid
       {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           T__base, T_geometry;

         public:
           GC_vacuum();
           GC_vacuum( T_coord  const& P_lo, T_coord  const& P_hi );
           GC_vacuum( T_box const& P_box );
          ~GC_vacuum();

         public:
           void    Fv_reset( T_state &P_intersect )const;
           T_size  Fv_weight( )const;

         public: // cluster
           T_size    const& Fv_quantity()const{ static T_size Irs_zero = 0; return Irs_zero; }
         public:
           T__base*         Fv_base( T_size const& P_index )const{ return nullptr; }
           bool             Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const{ return false; }

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const;
           T_location  Fv_inside   ( T_coord const& P_point/*, T_state const&P_intersect*/ )const;
           T_scalar    Fv_distance ( T_coord const& P_point )const;
         //bool        Fv_uvw      ( T_coord & P_uvw, T_coord const& P_point, T_state const&P_state )const;

         private:
           struct C_intersect;
        };
      }
    }
  }


#endif
