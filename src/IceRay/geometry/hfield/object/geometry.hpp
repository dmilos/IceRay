#ifndef _DDMM_IceRAY_geometry_hfield_object_geometry_H_
 #define _DDMM_IceRAY_geometry_hfield_object_geometry_H_

#include "Iceray/geometry/_pure/_pure.hpp"

#include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_hfield
        {
         namespace S_object
          {

           class GC_geometry
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base T_geometry;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base T_intersect;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base T_normal;

               bool Fv_intersect( T_scalar &lambda, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_ray const& P_ray )const;
               void Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const;
               void Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const;

             public:
               bool F_geometry( T_geometry * P_geometry );

              public:
                T_intersect *M2_intersect;
                T_normal    *M2_normal;
            };

          }
        }
      }
    }
  }

#endif
