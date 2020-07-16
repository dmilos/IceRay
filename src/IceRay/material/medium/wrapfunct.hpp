#ifndef Dh_DDMRM_Iceray_medium_wrap_function_HPP_
 #define Dh_DDMRM_Iceray_medium_wrap_function_HPP_

 #include <functional>
 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_WrapFunctt
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar     T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;

            typedef std::function< bool (*)( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state ) > T_function;

             explicit GC_WrapFunctt( T_function const& P_function = GC_WrapFunctt::Fs_nothing ):M2_function(P_function){ ; }
             virtual ~GC_WrapFunctt(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const override
              {
               return M2_function( P_color, P_deplete, P_start, P_end, P_state );
              }

           public:
             T_function const& F_function()const{ return M2_function; }
             void             F_function( T_function const& P_function ){ M2_function = P_function; }
           protected:
             T_function      & F1_function(){ return M2_function; }
           private:
             T_function M2_function;

            private static void Fs_nothing( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end )
             {
               static T_color Is_black( 0 );
               static T_color Is_white( 1 );

               P_color = Is_black;
               P_deplete = Is_white;
             }
          };

        }
      }
    }
  }

#endif