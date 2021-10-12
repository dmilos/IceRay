#ifndef _DDMM_IceRAY_geometry_ellipsoid_H_
 #define _DDMM_IceRAY_geometry_ellipsoid_H_
 // GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/math/coord.hpp"
#include "IceRay/type/math/matrix.hpp"
#include "IceRay/type/math/affine.hpp"

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

       class GC_ellipsoid
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

           typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_affine             T_affine;
           typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D           T_matrix;

          public:
          GC_ellipsoid( );
          GC_ellipsoid( T_coord const&  P_center, T_coord const& P_radius );
          GC_ellipsoid( T_coord const&  P_center, T_coord const& P_eX, T_coord const& P_eY, T_coord const& P_eZ );

          ~GC_ellipsoid( );
         public:
           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;
           bool    Fv_box( T_box const& P_box );

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location  Fv_inside   ( T_coord const& P_point/*, T_state const& P_state*/ )const;
           T_scalar    Fv_distance ( T_coord const& P_point )const;

         public:
           T_affine    const& F_2world()const{ return M2_2world; }
         private:
           T_affine M2_2world;

         public:
           T_affine    const& F_2local()const{ return M2_2local; }
         private:
           T_affine M2_2local;
         private:
           T_matrix M2_transpose;

         public:
           bool F_radius( T_scalar const& P_radius );
           bool F_radius( T_coord const& P_radius );
           bool F_center( T_coord const& P_center );
           bool F_system( T_coord const& P_eX, T_coord const& P_eY, T_coord const& P_eZ );
           bool F_load( T_coord const& P_center, T_coord const& P_eX, T_coord const& P_eY, T_coord const& P_eZ );

         private:
           struct C_intersect;
        };

      }
    }
  }

#endif

