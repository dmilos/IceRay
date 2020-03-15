#ifndef Dh_DDMRM_Iceray_render_pixel_strategy_sobol_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_strategy_sobol_HPP_

 #include "IceRay/type/basic/size.hpp"
 #include "IceRay/type/basic/scalar.hpp"
 #include "IceRay/utility/random.hpp"


 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {
         namespace S_strategy
          {
           class GC_sobol
           : public GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;


              GC_sobol():M2_size( 10 ){}
              ~GC_sobol(){}

             public:

               T_size Fv_make()
                {
                 F1_sieve().resize( F_size() );
                 for( T_size  I_index =0; I_index < F_size(); I_index ++)
                  {
                   M2_randSobol2D.next( F1_sieve()[ I_index ][0], F1_sieve()[ I_index ][1] );
                  }
                 return F_size();
                }

             public:
               T_size const& F_size(){ return M2_size; }
             protected:
               T_size  & F1_size(){ return M2_size; }
             private:
               T_size    M2_size;
             private:
               mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol2D     M2_randSobol2D;

            };

          }
        }
      }
    }
  }

#endif
