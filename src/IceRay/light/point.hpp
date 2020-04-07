#ifndef Dh_DDMM_IceRay_LIGHT_point_H_nDIM_Ready
 #define Dh_DDMM_IceRay_LIGHT_point_H_nDIM_Ready

 // GS_DDMRM::S_IceRay::S_light::GC_point

 #include "./_pure.hpp"
 #include "../type/basic/report.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_point
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:

           //typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;

         public:
                    GC_point( );
           explicit GC_point( T_coord const& P_center );
                    GC_point( T_coord const& P_center, T_color const& P_0, T_color const& P_1, T_color const& P_2 );
           explicit GC_point( T_spot const& P_spot );
           ~GC_point();

         public:
           T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property spot  spot
           T_spot    const& F_spot()const{ return M2_spot; }
           bool             F_spot( T_spot const& P_spot )
            {
             M2_spot = P_spot; 
             return bool( true ); 
            }
         protected:
           T_spot        & F1_spot(){ return M2_spot; }
         private:
           T_spot M2_spot;

         public: // property coord3d center
            T_coord const& F_center()const{ return M2_spot.F_center(); }
            T_coord      & F_center()     { return M2_spot.F_center(); }
            bool           F_center( T_coord const& P_center ){ M2_spot.F_center( P_center ); return true; }
        };

       }
     }
   }

#endif
