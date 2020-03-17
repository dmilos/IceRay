#ifndef Dh_DDMRM_Iceray_material_pigment_simple_HPP_
 #define Dh_DDMRM_Iceray_material_pigment_simple_HPP_

// GS_DDMRM::S_IceRay::S_material::S_pigment::GC_simple

#include "./_base.hpp"
#include "IceRay/type/color.hpp"
#include "IceRay/type/basic/size.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pigment
        {

         class GC_simple
          : public virtual GS_DDMRM::S_IceRay::S_material::S_pigment::GC__base
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__base T__base;

                      GC_simple(){}
             virtual ~GC_simple(){}

           public:
             bool Fv_color( T_color & P_color, T_beam &P_next, T_incident const& P_incident, T_state const& P_state )const
              {
               P_color = T_color( ::color::constant::black_t{} );
               return true;
              }

           public:
             using T__base::Fv_maxNextRays;
           public:
             using T__base::F_maxRayPerHit;
           protected:
             using T__base::F1_maxRayPerHit;
          };

        }
      }
    }
  }

#endif