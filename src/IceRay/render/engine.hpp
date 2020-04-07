#ifndef Dh_DDMRM_IceRay_render_world_HPP_
 #define Dh_DDMRM_IceRay_render_world_HPP_


#include "./0scanner/_pure.hpp"
#include "./1pixel/_pure.hpp"
#include "./2pierce/_pure.hpp"
#include "./3sheaf/_pure.hpp"
#include "./4ray/_pure.hpp"

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
           typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure     T_sheaf;
           typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure       T_ray;

           GC_engine();
          ~GC_engine();

         public:
           void     F_do( T_picture & P_picture );
           bool     F_work()const;
           void     F_stop();
           T_scalar F_progress()const;

         public:
           void           F_scanner( T_scanner * P_scanner   );
           T_scanner    & F_scanner()const{ return *M2_scanner;  }
        private:
           T_scanner     *M2_scanner;
         private:
           static T_scanner & Fs_scanner();

         public:
           void           F_pixel( T_pixel   * P_pixel     );
           T_pixel     *& F_pixel(){ return M2_pixel;    }
         private:
           T_pixel       *M2_pixel;
         public:
           static T_pixel & Fs_pixel();

         public:
           void           F_pierce( T_pierce  * P_pierce    );
           T_pierce    *& F_pierce(){ return M2_pierce;   }
         private:
           T_pierce      *M2_pierce;
         public:
           static T_pierce & Fs_pierce();

         public:
           void         F_sheaf( T_sheaf  * P_sheaf    );
           T_sheaf    *& F_sheaf(){ return M2_sheaf;   }
         private:
           T_sheaf      *M2_sheaf;
         public:
           static T_sheaf & Fs_sheaf();

         public:
           void        F_ray( T_ray  * P_ray    );
           T_ray    *& F_ray(){ return M2_ray;   }
         private:
           T_ray     *M2_ray;
         public:
           static T_ray & Fs_ray();
       };

      }
    }
  }




#endif
