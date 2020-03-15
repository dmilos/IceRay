#ifndef Dh_DDMRM_Iceray_render_image_parallel_HPP_
 #define Dh_DDMRM_Iceray_render_image_parallel_HPP_

 #include <vector>
 #include <thread>

 #include "./_pure.hpp"
 #include "./block.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_scanner
        {

         class GC_parallel
          : public GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                 T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_size2D   T_range;

             typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block   T_scanner;

             GC_parallel();
             ~GC_parallel();

           public:
             T_report Fv_pixel( T_pixel * P_pixel );
             T_report F_pixel( T_size const& P_index,T_pixel * P_pixel );
          protected:
             void F1v_render( T_picture & P_image );

           public:
              void Fv_stop();

           public:
             T_range const& F_range()const{ return M2_range; }
             T_report       F_range( T_range const& P_range );
           private:
             T_range M2_range;

           public:
             T_size const&  F_threads()const{ return M2_threads = M2_render.size(); }
             T_report       F_threads( T_size const& P_count );
           private:
             mutable T_size M2_threads;

           private:
             struct C_job
              {
               T_scanner   M_scanner;
               std::shared_ptr<std::thread> M_thread;
              };

             std::vector< C_job > M2_render;
           private:
             static T_pixel & F2s_pixel();

          };

       }
     }
   }
 }

#endif
