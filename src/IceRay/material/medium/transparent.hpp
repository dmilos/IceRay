#ifndef Dh_DDMRM_Iceray_medium_transparent_HPP_
 #define Dh_DDMRM_Iceray_medium_transparent_HPP_

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_transparent
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

                      GC_transparent()
                       {
                        M2_black =::color::constant::black_t{};
                        M2_white =::color::constant::white_t{};
                       }
             virtual ~GC_transparent(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const
              {
               P_color   = M2_black;
               P_deplete = M2_white;
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
