#ifndef Dh_DDMRM_Iceray_render_pixel_strategy_random_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_strategy_random_HPP_

//GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_random

 #include "../../../type/basic/size.hpp"
 #include "../../../type/basic/scalar.hpp"

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

           class GC_random
           : public GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;

             public:
               GC_random() 
                :M2_size( 10 ) 
                {
                }
               explicit GC_random( T_size const& P_size ) 
                :M2_size( P_size ) 
                {
                }
               ~GC_random(){}

             public:

               T_size Fv_make()
                {
                 F1_sieve().resize( F_size() );
                 for( T_size  I_index =0; I_index < F_size(); I_index ++)
                  {
                   F1_sieve()[ I_index ][0] = rand()/T_scalar( RAND_MAX );
                   F1_sieve()[ I_index ][1] = rand()/T_scalar( RAND_MAX );
                  }
                 return F_size();
                }

             public:
               T_size const& F_size(){ return M2_size; }
               bool          F_size( T_size const& P_size )
                {
                 M2_size = P_size;
                 return true;
                }
            protected:
               T_size  & F1_size(){ return M2_size; }
             private:
               T_size    M2_size;
            };

          }
        }
      }
    }
  }

#endif
