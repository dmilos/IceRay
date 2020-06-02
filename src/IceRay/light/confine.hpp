#ifndef Dh_DDMM_IceRay_light_confine_HPP_
 #define Dh_DDMM_IceRay_light_confine_HPP_

 #include "./_pure.hpp"

 #include "../geometry/_pure/inside.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_confine  // If spot is inside shell then put in swarm
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
          //typedef GS_DDMRM::S_IceRay::S_light::GC__pure T__pure;

          typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside T_inside;

          GC_confine();
          GC_confine( T__pure *P_child, T_inside * P_hull );

         public:
           T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property hull  hull
           //T__pure    const& F_hull()const{ return M2_hull; }
           bool             F_hull( T_inside * P_hull );
         protected:
        //T__pure        & F1_hull(){ return M2_hull; }
         private:
           T_inside * M2_hull;

         public:  // property child  child
           //T__pure    const& F_child()const{ return M2_child; }
           bool             F_child( T__pure * P_child );
         protected:
        //T__pure        & F1_child(){ return M2_child; }
         private:
             T__pure * M2_child;

         private:
           T_inside::T_location M2_side;
           mutable T_swarm M2_swarm;
        };

      }
    }
  }

#endif

