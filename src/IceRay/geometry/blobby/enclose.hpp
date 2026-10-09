#ifndef _DDMRM_IceRAY_geometry_blobby_enclose_HPP_
 #define _DDMRM_IceRAY_geometry_blobby_enclose_HPP_

#include "./_element.hpp"
#include "./vacuum.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_blobby
        {

         class GC_enclose
         : public GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar              T_coord;

             typedef   GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element     T__element;

           public:
             GC_enclose( );
             GC_enclose( T__element *P_element );
             GC_enclose( T__element *P_element, T_geometry * P_hull );
            ~GC_enclose( );

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
             bool F_child( T__element *P_child );
           private:
             T__element   *M2_child;

           public:
             bool F_hull( T_geometry* P_hull );
           private:
             T_geometry* M2_hull;

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
