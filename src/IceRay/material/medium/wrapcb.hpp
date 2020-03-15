#ifndef Dh_DDMRM_Iceray_medium_wrap_cb_HPP_
 #define Dh_DDMRM_Iceray_medium_wrap_cb_HPP_

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_WrapCB
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

            typedef class C_callback
             {
              public:
                         C_callback(){}
                virtual ~C_callback(){}
              public:
                virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const =0;
             } T_callback;

             explicit GC_WrapCB( T_callback * P_callback = &M2s_callback ):M2_callback(P_callback){ ; }
             virtual ~GC_WrapCB(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const
              {
               return M2_callback->Fv_attenuate( P_color, P_deplete, P_start, P_end, P_state );
              }

           public:
             T_callback const& F_callback()const{ return *M2_callback; }
             void              F_callback( T_callback * P_callback ){ M2_callback = P_callback; }
           protected:
             T_callback      & F1_callback(){ return *M2_callback; }
           private:
             T_callback *M2_callback;

           private:
            class C2_callback 
             : public C_callback
             {
              public:
               bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const
                {
                 static T_color Is_black( ::color::constant::black_t{} );
                 static T_color Is_white( ::color::constant::white_t{} );

                 P_color   = Is_black;
                 P_deplete = Is_white;
                 return true;
                }
             };
            static C2_callback M2s_callback;
          };

        }
      }
    }
  }

#endif