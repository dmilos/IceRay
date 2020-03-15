#ifndef Dh_DDMRM_Iceray_medium_wrap_cptr_HPP_
 #define Dh_DDMRM_Iceray_medium_wrap_cptr_HPP_

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_WrapCPtr
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

            typedef bool (*T_pointer)( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state );

             explicit GC_WrapCPtr( T_pointer const& P_pointer = &GC_WrapCPtr::F2s_nothing ):M2_pointer(P_pointer){ ; }
             virtual ~GC_WrapCPtr(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const
              {
               return M2_pointer( P_color, P_deplete, P_start, P_end, P_state );
              }

           public:
             T_pointer const& F_pointer()const{ return M2_pointer; }
             void             F_pointer( T_pointer const& P_pointer ){ M2_pointer = P_pointer; }
           protected:
             T_pointer      & F1_pointer(){ return M2_pointer; }
           private:
             T_pointer M2_pointer;

           private:
             static bool F2s_nothing( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )
              {
               static const T_color Is_black( ::color::constant::black_t{} );
               static const T_color Is_white( ::color::constant::white_t{} );

               P_color = Is_black;
               P_deplete = Is_white;
               return true;
              }
          };

        }
      }
    }
  }

#endif