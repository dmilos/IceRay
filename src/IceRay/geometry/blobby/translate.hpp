#ifndef _DDMRM_IceRAY_geometry_blobby_translate_HPP_
 #define _DDMRM_IceRAY_geometry_blobby_translate_HPP_

#include "./_element.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_blobby
        {

         class GC_translate
         : public GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar              T_coord;


             typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element        T__element;


           public:
             GC_translate( );
             explicit GC_translate( T_coord const& P_move );
             explicit GC_translate( T__element *P_child );
             GC_translate( T__element *P_child, T_coord const& P_move );
            ~GC_translate( );

           public:
             void          Fv_reset( T_state &P_intersect )const;
             T_size        Fv_weight( )const;
             T_size const& Fv_id( T_state const&P_state )const;

           public:
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray )const;
             void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const;
             T_location  Fv_inside   ( T_coord const& P_point/*, T_intersect &P_intersect*/ )const;

           public:
             bool     Fv_coefficient( T_coefficient::T_typedef & P_coefficient, T_state const& P_state, T_ray const& P_ray )const;
             T_scalar Fv_intensity( T_coord const& P_point )const;

           public:
             T_coord    const& F_move()const
              {
               return M2_2world;
              }
             bool              F_move( T_coord const& P_move );
           private:
             T_coord  M2_2local, M2_2world;

           public:
             bool F_child( T__element *P_child );
           private:
             T__element   *M2_child;

           private:
             struct C_intersect;

          };
        }
      }
    }
  }

#endif
