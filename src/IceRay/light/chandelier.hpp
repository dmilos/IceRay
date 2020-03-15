#ifndef Dh_DDMM_IceRay_LIGHT_chandelier_Ready
 #define Dh_DDMM_IceRay_LIGHT_chandelier_Ready

  #include <memory>

 #include "./type/size.hpp"

 #include "./_pure.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_chandelier
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
         //typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size   T_size;

         //typedef GS_DDMRM::S_IceRay::S_light::GC__pure T__pure;
           typedef T__pure* T_ptr;

           typedef std::vector< T_ptr > T_container;

           GC_chandelier( );
           GC_chandelier( T_container const& P_container );
           ~GC_chandelier();

         public:
          T_size  Fv_swarm( T_swarm & P_swarm,  T_coord const& P_point )const;

         public:
           void F_add( T__pure* P_light );

         public:
           T_size         const& F_size()const{ return M2_size = M2_container.size(); }
         private:
           mutable T_size M2_size;
         public:

           T_container    const& F_container()const{ return M2_container; }
           void                  F_container( T_container const& P_container ){ M2_container = P_container; }
         protected:
           T_container        & F1_container(){ return M2_container; }
         private:
           T_container M2_container;
        };

      }
    }
  }


#endif
