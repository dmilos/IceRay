#ifndef Dh_DDMRM_Iceray_render_pixel_filter___pure_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_filter___pure_HPP_

// GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure

 #include "../../../type/color.hpp"
 #include "../../../type/math/coord.hpp"
 #include "../../../type/basic/size.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {
         namespace S_filter
          {

           class GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar      T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D    T_UV;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size                 T_size;

               enum class Ee_action{ En_skip, En_break, En_process  };

             public:
               GC__pure(){}
               virtual ~GC__pure(){}

             public:
               virtual void Fv_reset()=0;
               virtual Ee_action Fv_check( T_color & P_color, T_UV const& P_UV, T_size const& P_index )=0;
            };

         }
       }
     }
   }
 }

#endif
