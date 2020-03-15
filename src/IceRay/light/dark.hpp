#ifndef Dh_DDMM_IceRay_LIGHT_dark_H_nDIM_Ready
 #define Dh_DDMM_IceRay_LIGHT_dark_H_nDIM_Ready

 #include "./_pure.hpp"

 
 
 
 
 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_dark 
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:

           //using GC__pure::T_swarm T_swarm;
           //using GC__pure::T_coord T_coord;

           GC_dark( );
           ~GC_dark();
     
           T_size  Fv_swarm( T_swarm &P_swarm,  T_coord const& P_point )const;

        };

       }
     }
   }

#endif

