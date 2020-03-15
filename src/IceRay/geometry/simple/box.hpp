#ifndef _DDMM_IceRAY_geometry_box_HPP_
 #define _DDMM_IceRAY_geometry_box_HPP_

// GS_DDMRM::S_IceRay::S_geometry::GC_box

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {

       class GC_box
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base T__base;

         public:
                    GC_box( );
                    GC_box( T_coord const& P_lo, T_coord const& P_hi );
           explicit GC_box( T_box const& P_interval );
                   ~GC_box( ){}

         public:
           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location  Fv_inside   ( T_coord const& P_point/*, T_state const& P_state*/ )const;
           T_scalar    Fv_distance ( T_coord const& P_point )const;

         public:
           bool    F_load( T_box const& P_box );
           bool    F_load( T_coord const& P_lo, T_coord const& P_hi );
         public:
           T_coord    const& F_lo()const{ return F_box().lo(); }
           bool              F_lo( T_coord const& P_lo ){ F_box( P_lo, F_box().hi() ); return true; }

         public:
           T_coord    const& F_hi()const{ return F_box().hi(); }
           bool              F_hi( T_coord const& P_hi ){ F_box( F_box().lo(), P_hi ); return true; }

         public:
           using T__base::F_box;

           static bool      Fs_valid( T_state const&P_intersect );
           static int       Fs_side(  T_state const&P_intersect );
           static T_scalar  Fs_min(   T_state const&P_intersect );
           static T_scalar  Fs_max(   T_state const&P_intersect );

         private:
           struct C_intersect;

        };

      }
    }
  }


#endif
