#ifndef Dh_DDMRM_Iceray_render_pixel_strategy_grid_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_strategy_grid_HPP_

// GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_grid

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

           class GC_grid
           : public GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type:: GT_scalar T_scalar;


             public:
               GC_grid()
                :M2_size( 10 )
                {
                }
               explicit GC_grid( T_size const& P_size )
                :M2_size( P_size )
                {
                }
               ~GC_grid(){}

             public:
               T_size Fv_make()
                {
                 T_size I_index = 0;
                 for( T_size  I_u = 0; I_u < F_size(); I_u ++ )
                  {
                   for( T_size  I_v =0; I_v < F_size(); I_v ++ )
                    {
                     F1_sieve()[ I_index ][0] = ( I_u + T_scalar(0.5) ) / F_size();
                     F1_sieve()[ I_index ][1] = ( I_v + T_scalar(0.5) ) / F_size();
                     ++I_index;
                    }
                  }

                 return F1_sieve().size();
                }

             public:
               T_size const& F_size()const
                {
                 return M2_size;
                }

               bool          F_size( T_size const& P_size )
                {
                 M2_size = P_size;

                 F1_sieve().resize( F_size() * F_size() );
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
