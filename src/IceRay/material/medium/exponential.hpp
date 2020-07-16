#ifndef Dh_DDMRM_Iceray_medium_exponentisl_HPP_
 #define Dh_DDMRM_Iceray_medium_exponentisl_HPP_

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_exponential
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

                      GC_exponential( )
                       {
                        M2_value =::color::constant::gray_t<1,1>{};
                        M2_half =  297.0/360.0;
                       }

                      GC_exponential( T_color const& P_value, T_scalar const& P_half )
                       {
                        M2_value = P_value;
                        M2_half = P_half;
                       }

             virtual ~GC_exponential(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const override
              {
               auto I_distance = ::math::linear::vector::distance( P_start, P_end );

               P_deplete[0] = T_scalar( 1 ) - pow( T_scalar( 0.5 ), I_distance / this->F_half() );
               P_deplete[1] = T_scalar( 1 ) - pow( T_scalar( 0.5 ), I_distance / this->F_half() );
               P_deplete[2] = T_scalar( 1 ) - pow( T_scalar( 0.5 ), I_distance / this->F_half() );

               ::color::operation::multiply( P_color, P_deplete, this->F_value() );
               ::color::operation::invert( P_deplete );
               return true;
              }

           public:
             T_color    const& F_value()const{ return M2_value; }
             bool              F_value( T_color const& P_value ){ M2_value = P_value; return true; }
           protected:
             T_color        & F1_value(){ return M2_value; }
           private:
             T_color M2_value;

           public:
             T_scalar    const& F_half()const{ return M2_half; }
             bool               F_half( T_scalar const& P_half ){ M2_half = P_half; return true; }
           protected:
             T_scalar        & F1_half(){ return M2_half; }
           private:
             T_scalar M2_half;
          };

        }
      }
    }
  }

#endif
