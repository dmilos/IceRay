#ifndef _DDMM_IceRAY_geometry_hfield_object__pure_H_
 #define _DDMM_IceRAY_geometry_hfield_object__pure_H_

//GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/math/coord.hpp"
#include "IceRay/type/ray/line.hpp"

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
            /*!
             It is expected that object is allays situate in box [0,0,0]x[1,1,1]
            */
           class GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar   T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar            T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_line       T_ray;

             public:
                        GC__pure(){}
               virtual ~GC__pure(){}

             public:
               /*
                at corners [0,0], [0,1], [1,0] ,[1,1]
               */
               virtual bool Fv_intersect( T_scalar &P_lambda, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_ray const& P_ray )const=0;
               /*
                 0 < P_x, P_y < 1
               */
               virtual void Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const=0;
               virtual void Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const=0;
            };


            typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure* GT_pointer;

          }
        }
      }
    }
  }

#endif
