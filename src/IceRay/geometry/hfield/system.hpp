#ifndef _DDMM_IceRAY_geometry_hfield_H_
 #define _DDMM_IceRAY_geometry_hfield_H_

#include <memory>

#include "IceRay/type/basic/scalar.hpp"

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"

#include "../volumetric/vacuum.hpp"

#include "./generator/_pure.hpp"
#include "./object/_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_hfield
        {

         class GC_system
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                              T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                            T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::GT_int                               T_integer;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D                 T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D                   T_size2D;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_cell2D                   T_cell2D;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_cell3D                   T_cell3D;

             typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure T_generator;
             typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure    T_object;

           public:
             GC_system();
             GC_system( T_generator* P_generator, T_object* P_object );
            ~GC_system( );

           public:
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray  )const;
             void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const;
             T_location  Fv_inside( T_coord const& P_point/*, T_state &P_intersect*/ )const;
           //T_scalar    Fv_distance( T_coord const& P_point )const;

             void    Fv_reset( T_state &P_intersect )const;
             T_size  Fv_weight( )const;
             bool Fv_box( T_box const& P_box );

           public:
             T_generator const& F_generator(  )const;
             bool F_generator( T_generator* P_generator );
           private:
             T_generator* M2_generator;
             T_box M2_area;
             T_coord M2_step;

           public:
             bool F_object( T_object* P_object );
           private:
             T_object*    M2_object;
           private:
            T_scalar F2_world2local( T_scalar const& P_value, T_size const& P_projection )const;
            T_coord  F2_world2local( T_coord const& P_value )const;
            T_coord  F2_local2world( T_coord const& P_value )const;

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_flat T_flat;
             static T_flat & Fs_flat();

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_quad T_quad;
             static T_quad & Fs_quad();

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_vacuum T_vacuum;
             static T_vacuum & Fs_vacuum();

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_theone T_theone;
             static T_theone & Fs_theone();

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table T_table;
             static T_table & Fs_table();
           private:
             struct C_intersect;
          };

        }
      }
    }
  }

#endif

