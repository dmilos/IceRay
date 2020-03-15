#ifndef Dh_DDMRM_Iceray_render_scanner__pure_HPP_
 #define Dh_DDMRM_Iceray_render_scanner__pure_HPP_

 #include <atomic>

 #include "../../type/basic/report.hpp"
 #include "../../type/picture/_pure.hpp"

 #include "../1pixel/_pure.hpp"
 #include "../1pixel/_base.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_scanner
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::GT_report                       T_report;
             typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure            T_picture;
             typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure              T_pixel;

           public:
             GC__pure();
             explicit GC__pure( T_pixel * P_pixel );
             virtual ~GC__pure();

            public:
              virtual void Fv_render( T_picture & P_image );
            private:
              virtual void F1v_render( T_picture & P_image )=0;

            public:
              virtual void Fv_stop(){ M2_work = false; }
                      bool F_work()const{ return M2_work; }

            public:
            //TODO typedef std::atomic<T_scalar> T2_progress;
              typedef volatile T_scalar     T2_progress;
              T2_progress  const& F_progress()const{ return M2_progress; }
            protected:
              T2_progress& F1_progress(){ return M2_progress; }
            private:
              T2_progress M2_progress;

            protected:
            //TODO typedef std::atomic<bool> T2_work;
              typedef volatile bool T2_work;
              T2_work& F1_work(){ return M2_work; }
            private:
              T2_work M2_work;

            public:
              T_pixel  *      F_pixel( ){ return M2_pixel; }
              virtual T_report Fv_pixel( T_pixel * P_pixel );
            protected:
              T_pixel *& F1_pixel(){ return M2_pixel; }

            private:
              T_pixel *M2_pixel; //!< TODO deep_copy__ptr<>

              typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base T2__base;
              static T2__base M2s_pixel;
          };

       }
     }
   }
 }

#endif
