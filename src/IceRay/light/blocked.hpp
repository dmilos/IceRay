#ifndef Dh_DDMM_IceRay_light_blocked_HPP_
 #define Dh_DDMM_IceRay_light_blocked_HPP_

 #include "./_pure.hpp"

#include "../geometry/_pure/intersect.hpp"
//#include "system/allocator/chunk/managed.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_blocked
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
          typedef GS_DDMRM::S_IceRay::S_light::GC__pure T__pure;

          typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect T_barrier;
        public:
          GC_blocked(  );
          GC_blocked( T__pure *P_light, T_barrier * P_geometry );

         public:
           T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property
           bool                 F_light( T__pure * P_ligh );
         protected:
         private:
           T__pure* M2_light;

         public:  // property
           bool        F_barrier( T_barrier * P_blocker );
         protected:
         private:
           T_barrier* M2_barrier;

         private:
           typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T2_state;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GT_ray        T2_ray;

         private:
           mutable T2_state M2_stateInstance;
           mutable std::vector<std::uint8_t> M2_stateMemory;
           mutable T_swarm M2_swarm;

         private:
        };

      }
    }
  }

#endif

