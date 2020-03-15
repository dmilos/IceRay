#ifndef Dh_DDMRM_Iceray_material_type_intersect_HPP_
 #define Dh_DDMRM_Iceray_material_type_intersect_HPP_

#include "IceRay/geometry/_pure/_base.hpp"
#include "IceRay/type/ray/trace.hpp"
#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/math/coord.hpp"







 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {

       class GC_intersect
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace        T_ray;
           typedef GS_DDMRM::S_IceRay::S_type::GT_size                T_size;
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;

           typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state  T_state;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  T_geometry;

           GC_intersect()
            {
             M_intersection.M_geometryID = 0;
            }

         public:
           T_ray       M_incoming;

           struct C_intersection
            {
             T_scalar    M_lambda;
             T_coord     M_point;
             T_coord     M_normal;
             T_state     M_state;
             T_size      M_geometryID;
            };

           C_intersection M_intersection;

           enum Ee_status
           {
             En_statusUsed
            ,En_statusUnUsed
           };

           Ee_status M_status;
       };

      }
    }
  }

#endif
