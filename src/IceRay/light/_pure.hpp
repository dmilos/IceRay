#ifndef Dh_DDMRM_Iceray_light__pure_HPP_
 #define Dh_DDMRM_Iceray_light__pure_HPP_
 // GS_DDMRM::S_IceRay::S_light::GC__pure

 #include "./type/size.hpp"
 #include "./type/scalar.hpp"
 #include "./type/color.hpp"
 #include "./type/coord.hpp"
 #include "./type/interval.hpp"

 #include "./type/swarm.hpp"
 #include "./type/spot.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC__pure
        {
         public:

          typedef GS_DDMRM::S_IceRay::S_type::GT_report             T_report;
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size      T_size;
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_scalar    T_scalar;
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_coord     T_coord;
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_coord2D   T_coord2D;
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_color     T_color;
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_interval  T_interval;

         public:
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   T_spot;
          typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_swarm  T_swarm;
          
          typedef GS_DDMRM::S_IceRay::S_light::GC__pure T__pure, T_this;


         public:
          explicit GC__pure( T_size     const& P_max = 1 ):M2_max(P_max){ ; }
          explicit GC__pure( T_interval const& P_interval, T_size const& P_max = 1 ):M2_box(P_interval), M2_max(P_max){ ; }
          virtual ~GC__pure( ){ ; }

          virtual T_size  Fv_swarm( T_swarm & P_swarm, T_coord const& P_point )const=0; //!< Push only

         public:
           T_interval const& F_box()const{ return M2_box; }
         protected:
           T_interval      & F1_box(){ return M2_box; }
         private:
           T_interval M2_box;

         public:
           T_size const& F_max()const{ return M2_max; }
         protected:
           T_size      & F1_max(){ return M2_max; }
         private:
           T_size M2_max; //!< Max number of spots that this light can emit

        };
     }
   }
 }



#endif

