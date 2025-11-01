#ifndef _DDMM_IceRAY_geometry_mist_H_
 #define _DDMM_IceRAY_geometry_mist_H_

#include <functional>

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"
#include "../_pure/pierce.hpp"

#include "../volumetric/vacuum.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_volumetric
        {

         class GC_mist
          : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                         T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base      T_geometry, T__base;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect  T_intersect;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_pierce     T_pierce;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside     T_inside;

           public:
             GC_mist();
             GC_mist( T_scalar const& P_density, T_scalar const& P_precision = 0.01 );
            ~GC_mist( );

           public:
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
             void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
             T_location  Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const;
             T_scalar    Fv_distance( T_coord const& P_point )const;

             void    Fv_reset( T_state &P_state )const;
             T_size  Fv_weight( )const;

           public:
             T_size    const& F_seed()const{ return M2_seed; }
             bool               F_seed( T_size const& P_seed );
           protected:
             T_size        & F1_seed(){ return M2_seed; }
           private:
             T_size         M2_seed;

           public:
             T_scalar    const& F_density()const{ return M2_density; }
             bool               F_density( T_scalar const& P_density );
           protected:
             T_scalar        & F1_density(){ return M2_density; }
           private:
             T_scalar M2_density;

           public:
              T_scalar    const& F_precision()const{ return M2_precision; }
              bool               F_precision( T_scalar const& P_precision );
           protected:
             T_scalar        & F1_precision(){ return M2_precision; }
           private:
             T_scalar M2_precision;

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum T_vacuum;
             static T_vacuum & Fs_vacuum();

           public:
              T__base const& F_hull( )const;
              bool           F_hull( T__base * P_hull );
           private:
              typedef struct C2_hull
               {
                T__base      *M__base;
                T_intersect  *M_intersect;
                T_inside     *M_inside;
                T_pierce     *M_pierce;
              }T2_hull;
              T2_hull M2_hull;

           private:
             struct C_intersect;
          };

        }
      }
    }
  }

#endif
