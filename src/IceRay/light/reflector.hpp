#ifndef Dh_DDMM_IceRay_LIGHT_reflector_H_nDIM_Ready
 #define Dh_DDMM_IceRay_LIGHT_reflector_H_nDIM_Ready

 #include "./_pure.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_reflector
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
           GC_reflector( );
           GC_reflector( T_coord  const& P_position, T_coord  const& P_dir, T_scalar const& P_in=0, T_scalar const& P_out=1 );
           GC_reflector( T_spot   const& P_spot,     T_coord  const& P_dir, T_scalar const& P_in=0, T_scalar const& P_out=1 );

         public:
           T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property spot  spot
           T_spot    const& F_spot()const{ return M2_spot; }
           bool             F_spot( T_spot const& P_spot ){ M2_spot = P_spot; return bool( true ); }
         protected:
           T_spot        & F1_spot(){ return M2_spot; }
         private:
           T_spot M2_spot;

         public:  // property spot  spot
           T_coord   const& F_center()const{ return M2_spot.F_center(); }
           bool             F_center( T_coord const& P_center ){ return M2_spot.F_center( P_center ); }

         public:  // property coord  direction
           T_coord    const& F_direction()const{ return M2_direction; }
           bool              F_direction( T_coord const& P_direction ){ M2_direction = P_direction; return bool( true ); }
         protected:
           T_coord        & F1_direction(){ return M2_direction; }
         private:
           T_coord M2_direction;

         public:  // property coord  innner
           T_scalar    const& F_inner()const{ return M2_inner; }
           bool               F_inner( T_scalar const& P_innner ){ M2_inner = P_innner; return bool( true ); }
         protected:
           T_scalar        & F1_inner(){ return M2_inner; }
         private:
           T_scalar M2_inner;

         public:  // property coord  outter
           T_scalar    const& F_outter()const{ return M2_outter; }
           bool               F_outter( T_scalar const& P_outter ){ M2_outter = P_outter; return bool( true ); }
         protected:
           T_scalar        & F1_outter(){ return M2_outter; }
         private:
           T_scalar M2_outter;
         };

      }
    }
  }


#endif
