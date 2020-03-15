#ifndef _DDMRM_IceRAY_geometry_blobby_affine_HPP_
 #define _DDMRM_IceRAY_geometry_blobby_affine_HPP_

#include "./_element.hpp"
#include "./vacuum.hpp"
#include "IceRay/type/math/affine.hpp"
#include "IceRay/type/math/matrix.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_blobby
        {

         class GC_affine
         : public GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar              T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D           T_matrix;
             typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D           T_affine;

             typedef   GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element     T__element;

           public:
             GC_affine( );
             GC_affine( T__element *P_element );
             GC_affine( T__element *P_element, T_affine const& P_2world );
             GC_affine( T__element *P_element, T_matrix const& P_linear,T_coord const& P_center );
            ~GC_affine( );

           public:
             void   Fv_reset( T_state &P_state )const;
             T_size Fv_weight( )const;
             T_size const& Fv_id( T_state const& P_state )const;

           public:
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const;
             void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
             T_location  Fv_inside   ( T_coord const& P_point/*, T_state const&P_state*/ )const;

           public:
             bool     Fv_coefficient( T_coefficient::T_typedef & P_coefficient, T_state const& P_state, T_ray const& P_ray )const;
             T_scalar Fv_intensity( T_coord const& P_point )const;


           public:
             T_affine    const& F_2world()const{ return M2_2world; }
             bool               F_2world( T_affine const& P_affine );
           private:
             T_affine M2_2world;

           public:
             T_affine    const& F_2local()const{ return M2_2local; }
             bool               F_2local( T_affine const& P_affine );
           private:
             T_affine M2_2local;
           private:
             T_matrix M2_transpose;

           public:
             bool F_child( T__element *P_child );
           private:
             T__element   *M2_child;

           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_vacuum T_vacuum;
             static T_vacuum & Fs_vacuum();
           private:
             struct C_intersect;

          };

        }
      }
    }
  }

#endif
