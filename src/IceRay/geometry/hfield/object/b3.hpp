#ifndef _DDMM_IceRAY_geometry_hfield_object_b3_H_
 #define _DDMM_IceRAY_geometry_hfield_object_b3_H_

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

           class GC_b3
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure
            {
             public:
               bool Fv_intersect( T_scalar &lambda, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_ray const& P_ray )const;
               void Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const;
               void Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const;
            };

          }
        }
      }
    }
  }

#endif
