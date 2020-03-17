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
          GC_clipped( T__pure *P_child, T_inside * P_shell );

         public:
           T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property shell  shell
           //T__pure    const& F_shell()const{ return M2_shell; }
           bool             F_shell( T_inside * P_shell ){ M2_shell = P_shell; return bool( true ); }
         protected:
        //T__pure        & F1_shell(){ return M2_shell; }
         private:
           T_inside * M2_shell;

         public:  // property child  child
           //T__pure    const& F_child()const{ return M2_child; }
           bool             F_child( T__pure * P_child ){ M2_child = P_child; return bool( true ); }
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

