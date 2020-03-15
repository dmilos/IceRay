/********************************** plane_sys.hpp **********************************/
#ifndef _DDMM_IceRAY_object_plane_system_H_
 #define _DDMM_IceRAY_object_plane_system_H_

#include "../main/rt_object.hpp"

 namespace S_DDMRM
  {
   namespace S_IceRay
    {
     class GC_RTplane_system: public GC_RTobject
      {
       public:
       /* TODO
         typedef struct PLANE
          {
           VECTOR3  point, normal;
           TEXTURE  texture;
          } PLANE;
         typedef enum PLANES__TYPE
          {
           PLANES__tAND,
           PLANES__tXOR
          }PLANES__TYPE;
       
       */

         GC_RTplane_system( );
        ~GC_RTplane_system( );

        bool      Fv_fint  ( T_coord const& P_dir, T_coord const&  P_pos, T_scalar *P_lambda, C_intersect *P_intersect )const;
        bool      Fv_sint  ( T_coord const& P_dir, T_coord const&  P_pos, T_scalar *P_lambda, C_intersect *P_intersect )const;
        void      Fv_norm  ( T_coord const& P_pnt, T_coord *P_nrm, C_intersect *P_intersect  )const;
        bool      Fv_io    ( T_coord const& P_pnt )const;
      //T_scalar  Fv_dist  ( T_coord const& P_pnt )const;

       protected:
        
    
      };

    }
  }

#endif

