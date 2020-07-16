#ifndef Dh_DDMRM_Iceray_medium_solid_HPP_
 #define Dh_DDMRM_Iceray_medium_solid_HPP_

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_solid
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

                      GC_solid()
                       {
                        M2_black =::color::constant::black_t{};
                        M2_white =::color::constant::white_t{};
                       }
             virtual ~GC_solid(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const override
              {
               P_color   = M2_white;
               P_deplete = M2_black;
               return true;
              }

           private:
             T_color M2_black;
             T_color M2_white;
          };

        }
      }
    }
  }

#endif
