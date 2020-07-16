#ifndef Dh_DDMRM_Iceray_medium_quadratic_HPP_
 #define Dh_DDMRM_Iceray_medium_quadratic_HPP_

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_quadratic
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

                      GC_quadratic()
                       {
                        M2_value = ::color::constant::gray_t<1,1>{};
                        M2_a = 0.5 * 0.2;
                        M2_b = 0.5 * 0.002;
                        M2_c = 0.5 * 0.0002;
                      }

                      GC_quadratic( T_color const& P_value, T_scalar const P_c0, T_scalar const& P_c1, T_scalar const& P_c2 )
                       {
                        M2_value = P_value;
                        M2_a = P_c2;
                        M2_b = P_c1;
                        M2_c = P_c0;
                      }

             virtual ~GC_quadratic(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const override
              {
               auto I_distance = ::math::linear::vector::distance( P_start, P_end );
               auto I_deplete =  I_distance*I_distance*this->F_a()+ I_distance*this->F_b() + this->F_c();
               if( T_scalar(1) < I_deplete ) I_deplete = T_scalar(1);
               P_deplete = T_gray( { T_scalar(1) - I_deplete } );
               P_color =  I_deplete * this->F_value();
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
             T_scalar    const& F_a()const{ return M2_a; }
             bool               F_a( T_scalar const& P_a ){ M2_a = P_a; return true; }
           protected:
             T_scalar        & F1_a(){ return M2_a; }
           private:
             T_scalar M2_a;

           public:
             T_scalar    const& F_b()const{ return M2_b; }
             bool               F_b( T_scalar const& P_b ){ M2_b = P_b; return true; }
           protected:
             T_scalar        & F1_b(){ return M2_b; }
          private:
            T_scalar M2_b;

           public:
             T_scalar    const& F_c()const{ return M2_c; }
             bool               F_c( T_scalar const& P_c ){ M2_c = P_c; return true; }
           protected:
             T_scalar        & F1_c(){ return M2_c; }
          private:
            T_scalar M2_c;
          };

        }
      }
    }
  }

#endif
