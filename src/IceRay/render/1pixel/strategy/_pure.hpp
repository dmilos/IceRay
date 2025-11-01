#ifndef Dh_DDMRM_Iceray_render_pixel_strategy__pure_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_strategy__pure_HPP_

 // GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure

 #include <vector>
 #include "../../../type/basic/size.hpp"
 #include "../../../type/math/coord.hpp"


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

           class GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_UV;

               typedef std::vector<T_UV> T_sieve;

               typedef GC__pure T__pure, T_this;

             public:
               /*
                make array of coords [0-1,0-1]x[0-1,0-1]
               */
               virtual T_size Fv_make()=0;

             public:
               T_sieve const& F_sieve( ){ return M2_sieve; }
             protected:
               T_sieve  & F1_sieve(){ return M2_sieve; }
             private:
               T_sieve    M2_sieve;
            };

          }
        }
      }
    }
  }

#endif
