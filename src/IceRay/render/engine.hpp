#ifndef Dh_DDMRM_IceRay_render_world_HPP_
 #define Dh_DDMRM_IceRay_render_world_HPP_


#include "./0scanner/_pure.hpp"
#include "./0scanner/block.hpp"

#include "./1pixel/_pure.hpp"
#include "./1pixel/_base.hpp"

#include "./2pierce/_pure.hpp"
#include "./2pierce/_base.hpp"
#include "./2pierce/uv.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {

       class GC_engine
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar               T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure     T_picture;

           typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure   T_scanner;
           typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure     T_pixel;
           typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure    T_pierce;

           GC_engine();
          ~GC_engine();

         public:
           void     F_do( T_picture & P_picture );
           bool     F_work();
           void     F_stop();
           T_scalar F_progress()const;

         public:
           void           F_scanner( T_scanner * P_scanner   );
           T_scanner   *& F_scanner(){ return M2_scanner;  }
         private:
           T_scanner     *M2_scanner; // deep_copy_pointer;
         private:
           typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block T2_scanner;
           static T2_scanner  M2s_scanner;

         public: 
           void           F_pixel( T_pixel   * P_pixel     );
           T_pixel     *& F_pixel(){ return M2_pixel;    }
         private:
           T_pixel       *M2_pixel;
         private:
           typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base T2_pixel;
           static T2_pixel M2s_pixel;

         public: 
           void           F_pierce( T_pierce  * P_pierce    );
           T_pierce    *& F_pierce(){ return M2_pierce;   }
         private:
           T_pierce      *M2_pierce;
         private:
         //typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__base  T2_pierce;
           typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV  T2_pierce;
           static T2_pierce M2s_pierce;
        };

      }
    }
  }




#endif
