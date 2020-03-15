#ifndef Dh_DDMRM_Iceray_material_pigment__pure_HPP_
 #define Dh_DDMRM_Iceray_material_pigment__pure_HPP_
 
 // GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure

 #include "IceRay/type/basic/size.hpp"
 #include "IceRay/type/color.hpp"
 #include "IceRay/type/ray/trace.hpp"

 #include "../beam.hpp"
 #include "../intersect.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pigment
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                T_size;

             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar     T_color;

             typedef GS_DDMRM::S_IceRay::S_material::GT_beam            T_beam;
             typedef GS_DDMRM::S_IceRay::S_material::GC_intersect       T_intersect, T_incident;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state  T_state;

             // AUX
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace        T_ray;

                      GC__pure(){}
             virtual ~GC__pure(){}

           public:
             virtual bool Fv_color( T_color & P_color, T_beam &P_next, T_incident const& P_incident, T_state const& P_state )const=0;

           public:
             virtual T_size const& Fv_maxNextRays( )const=0;
          };

        }
      }
    }
  }

#endif