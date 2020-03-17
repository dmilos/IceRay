#ifndef Dh_DDMRM_Iceray_material_pigment__base_HPP_
 #define Dh_DDMRM_Iceray_material_pigment__base_HPP_

// GS_DDMRM::S_IceRay::S_material::S_pigment::GC__base

 #include "./_pure.hpp"
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

         class GC__base
          : public virtual GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure T__pure;

                      GC__base(){}
             virtual ~GC__base(){}

           public:
             using T__pure::Fv_color;

           public:
             T_size const& Fv_maxNextRays( )const
              {
               return F_maxRayPerHit();
              }

           public:
             T_size const& F_maxRayPerHit( )const
              {
               return M2_maxRayPerHit;
              }
           protected:
             T_size & F1_maxRayPerHit( )
              {
               return M2_maxRayPerHit;
              }
           private:
             T_size M2_maxRayPerHit=10;
          };

        }
      }
    }
  }

#endif