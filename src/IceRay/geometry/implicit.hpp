#ifndef _DDMM_IceRAY_geometry_implicit_H_
 #define _DDMM_IceRAY_geometry_cone_H_

#include "IceRay/type/basic/string.hpp"
#include "IceRay/type/math/interval.hpp"

#include "./_pure/_base.hpp"
#include "./_pure/intersect.hpp"
#include "./_pure/normal.hpp"
#include "./_pure/inside.hpp"
#include "./_pure/distance.hpp"

#include "IceRay/utility/expression/expression.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {

       class GC_implicit
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;
           typedef GS_DDMRM::S_IceRay::S_type::GT_string                        T_string;

           typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program   T_program;
           typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory    T_memory;

         public:
           GC_implicit();
          ~GC_implicit( );

         public:
           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;
         public:
           virtual bool Fv_box( T_box const& P_box );

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const;
           T_location  Fv_inside( T_coord const& P_point/*, T_state const& P_state*/ )const;
           T_scalar    Fv_distance( T_coord const& P_point )const;

         public:  // property expression  expression
            T_interval    const& F_interval()const{ return M2_interval; }
           virtual bool          F_interval( T_interval const& P_interval ){ M2_interval = P_interval; return bool( true ); }
         protected:
           T_interval& F1_interval(){ return M2_interval; }
         private:
           T_interval M2_interval;

         public:  // property expression  expression
           T_scalar    const& F_delta()const{ return M2_delta; }
           virtual bool       F_delta( T_scalar const& P_delta ){ M2_delta = P_delta; return bool( true ); }
         private:
           T_scalar M2_delta;

         public:  // property expression  expression
                   T_string    const& F_expression()const{ return M2_expression; }
           virtual bool               F_expression( T_string const& P_expression );
         protected:
           T_string        & F1_expression(){ return M2_expression; }
         private:
           T_string M2_expression;
         private:
           T_program M2_program;
           mutable T_memory  M2_memory;
           T_size M2_x, M2_y, M2_z, M2_result;
           T_scalar F2_value( T_coord const& P_coord )const;
         private:
           struct C_intersect;
        };

      }
    }
  }

#endif

