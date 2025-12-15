#ifndef Dh_DDMRM_Iceray_material_type_intersect_HPP_
 #define Dh_DDMRM_Iceray_material_type_intersect_HPP_

 //  GS_DDMRM::S_IceRay::S_material::GC_intersect


#include "IceRay/geometry/_pure/_base.hpp"
#include "IceRay/type/ray/trace.hpp"
#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/string.hpp"
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
           typedef GS_DDMRM::S_IceRay::S_type::GT_string              T_string;
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
             ,En_discard  //!<< not traced     ->(end)
           //,En_skip     //!<< processed but not traced
             ,En_spent    //!<< traced             ->( end )
             ,En_fresh    //!<< Wait to be processed  ->( end, spent )
           //,En_end      //!<< end is end
            };
           static T_string to_string( Ee_consume const& P_consume )
            {
             switch( P_consume  )
              {
                default:
                case( Ee_consume::En__unknown ): return "_unknown";
                case( Ee_consume::En_discard  ): return "discard";
                case( Ee_consume::En_spent    ): return "spent";
                case( Ee_consume::En_fresh    ): return "fresh";
              }
            }

           struct C_intersection
            {
             T_scalar    M_lambda;
             T_coord     M_point;
             T_coord     M_normal;
             T_state     M_state;
             T_size      M_geometryID;
            };

        public:
          void F_clear()
           {
            M_consume = Ee_consume::En__unknown;

            M_intersection.M_lambda = -1;
          //M_intersection.M_point;
          //M_intersection.M_normal;
            M_intersection.M_state.F_clear();
            M_intersection.M_geometryID = -1;
            M_incoming.F_clear();
           }
        public:
          Ee_consume       M_consume;
          T_ray            M_incoming;
          C_intersection   M_intersection;
        };

      }
    }
  }

#endif
