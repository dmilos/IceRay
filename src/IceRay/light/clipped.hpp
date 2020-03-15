#ifndef Dh_DDMM_IceRay_light_clipped_HPP_
 #define Dh_DDMM_IceRay_light_clipped_HPP_

 #include "./_pure.hpp"

 #include "../geometry/_pure/inside.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_clipped  // If spot is inside shell do not put in swarm
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
          //typedef GS_DDMRM::S_IceRay::S_light::GC__pure T__pure;

          typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside T_inside;

          GC_clipped();
          GC_clipped( T__pure *P_light, T_inside * P_geometry );

         public:
           T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         private:
           T__pure    * M2_light;
           T_inside   * M2_shell;
           T_inside::T_location M2_side;
           mutable T_swarm M2_swarm;
        };

      }
    }
  }

#endif

