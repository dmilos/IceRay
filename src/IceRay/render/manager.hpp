#ifndef Dh_DDMRM_IceRay_render_class_HPP_
 #define Dh_DDMRM_IceRay_render_class_HPP_

#include "image\_pure.hpp"
#include "beam\_pure.hpp"
#include "pixel\_pure.hpp"
#include "ray\_pure.hpp"

#include "..\camera\_pure.hpp"
#include "..\geometry\_pure.hpp"
#include "..\type\picture.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {

       class GC_manager
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::S_picture::GT__pure T_picture;
           typedef GS_DDMRM::S_IceRay::S_render::S_image::GC__pure T_image;
           typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure T_pixel;
           typedef GS_DDMRM::S_IceRay::S_render::S_beam::GC__pure  T_beam;
           typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure   T_ray;
           
           typedef GS_DDMRM::S_IceRay::S_camera::GC__pure   T_camera;
           typedef GS_DDMRM::S_IceRay::S_geometry::GC__pure T_geometry;

           GC_manager();
           ~GC_manager();
           
           void F_do( T_picture & P_image );
           bool F_work();
       
 
         public: void F_image   (T_image   * P_image     );  T_image     *& F_image   (){ return M2_image;    } private: T_image       *M2_image;
         public: void F_pixel   (T_pixel   * P_pixel     );  T_pixel     *& F_pixel   (){ return M2_pixel;    } private: T_pixel       *M2_pixel;
         public: void F_beam    (T_beam    * P_beam      );  T_beam      *& F_beam    (){ return M2_beam ;    } private: T_beam        *M2_beam ;
         public: void F_ray     (T_ray     * P_ray       );  T_ray       *& F_ray     (){ return M2_ray;      } private: T_ray         *M2_ray;
         public: void F_camera  (T_camera  * P_camera    );  T_camera    *& F_camera  (){ return M2_camera;   } private: T_camera      *M2_camera;
         // izbaciti
         public: void F_geometry(T_geometry* P_geometry  );  T_geometry  *& F_geometry(){ return M2_geometry; } private: T_geometry    *M2_geometry;

        };

      }
    }
  }




#endif

