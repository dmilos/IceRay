#ifndef Dh_DDMRM_Iceray_medium_constant_HPP_
 #define Dh_DDMRM_Iceray_medium_constant_HPP_

// GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_constant
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

                      GC_constant()
                       {
                        M2_value =::color::constant::black_t{};
                        M2_deplete =::color::constant::white_t{};
                       }
                      GC_constant( T_color const& P_value, T_color const& P_deplete )
                       :M2_value(P_value),M2_deplete(P_deplete)
                       {
                        ;
                       }

             virtual ~GC_constant(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const
              {
               P_deplete = F_deplete();
               ::color::operation::multiply( P_color, P_deplete, this->F_value() );
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
            T_color    const& F_deplete()const{ return M2_deplete; }
            bool              F_deplete( T_color const& P_deplete ){ M2_deplete = P_deplete; return true; }
          protected:
            T_color        & F1_deplete(){ return M2_deplete; }
          private:
            T_color M2_deplete;
          };

        }
      }
    }
  }

#endif
