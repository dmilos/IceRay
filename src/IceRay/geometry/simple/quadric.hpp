#ifndef Dh_DDMRM_IceRAY_geometry_simple_quadric_H_
 #define Dh_DDMRM_IceRAY_geometry_simple_quadric_H_

// GS_DDMRM::S_IceRay::S_geometr::GC_quadric

#include "../../type/basic/scalar.hpp"
#include "../../type/math/coord.hpp"
#include "../../type/math/matrix.hpp"

#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
 //#include "../_pure/distance.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {

       class GC_quadric  //   p ( M(p) + v ) + s = 0; N-dimensional ready
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        //, public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        { 
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;
           typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D  T_matrix;

         public:
           GC_quadric( );
           GC_quadric( T_matrix const& P_matrix, T_coord const& P_coord, T_scalar const& P_scalar );
           ~GC_quadric( ){}

         public:
           void    Fv_reset( T_state &P_state )const;
           T_size  Fv_weight( )const;

         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
           T_location  Fv_inside( T_coord const& P_point/*, T_state const& P_state*/ )const;
         //T_scalar    Fv_distance( T_coord const& P_point )const;

         public:  // property matrix  matrix
           T_matrix    const& F_matrix()const{ return M2_matrix; }
           bool                 F_matrix( T_matrix const& P_matrix );
         protected:
           T_matrix        & F1_matrix(){ return M2_matrix; }
         private:
           T_matrix M2_matrix;

         public:  // property coord  coord
           T_coord    const& F_coord()const{ return M2_coord; }
           bool              F_coord( T_coord const& P_coord );
         protected:
           T_coord        & F1_coord(){ return M2_coord; }
         private:
           T_coord M2_coord;

         public:  // property scalar  scalar
           T_scalar    const& F_scalar()const{ return M2_scalar; }
           bool               F_scalar( T_scalar const& P_scalar );
         protected:
           T_scalar        & F1_scalar(){ return M2_scalar; }
         private:
           T_scalar M2_scalar;

         private:
           struct C_intersect;
        };

      }
    }
  }

#endif
