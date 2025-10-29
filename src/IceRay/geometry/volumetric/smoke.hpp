#ifndef _DDMM_IceRAY_geometry_smoke_H_
 #define _DDMM_IceRAY_geometry_smoke_H_

#include <functional>

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"
#include "../volumetric/vacuum.hpp"
#include "IceRay/type/basic/string.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {

       class GC_smoke
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect        T_hull;

           typedef GS_DDMRM::S_IceRay::S_type::GT_string   T_string;

         public:
           GC_smoke();
         //GC_smoke( T_hull * P_hull );
          ~GC_smoke( );

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location  Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const;
           T_scalar    Fv_distance( T_coord const& P_point )const;

           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;

         public:
           T_string    const& F_density()const{ return M2_density; }
           bool               F_density( T_string const& P_density );
         protected:
           T_string        & F1_density(){ return M2_density; }
         private:
           T_string M2_density;

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
            T_hull const& F_hull( )const;
            void F_hull( T_hull * P_hull  );
         private:
            T_hull *M2_hull;

         private:
           struct C_intersect;

        };

      }
    }
  }

#endif
