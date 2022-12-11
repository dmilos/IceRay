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

         public:
           GC_intersect()
            {
             M_intersection.M_geometryID = 0;
             M_consume = Ee_consume::En__unknown;
            }

         public:
           enum class Ee_consume
            {
              En__unknown //!<< not traced
             ,En_discard  //!<< not traced     ->()
           //,En_skip     //!<< processed but not traced
             ,En_spent    //!<< traced             ->( discard )
             ,En_fresh    //!<< Wait to be processed  ->( discard, spent )
            };

           struct C_intersection
            {
             T_scalar    M_lambda;
             T_coord     M_point;
             T_coord     M_normal;
             T_state     M_state;
             T_size      M_geometryID;
            };

         public:
           T_ray          M_incoming;
           C_intersection M_intersection;
           Ee_consume     M_consume;
        };

      }
    }
  }

#endif
