#ifndef Dh_DDMRM_Iceray_render_pixel_filter_const_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_filter_const_HPP_

// GS_DDMRM::S_IceRay::S_render::S_pixe::S_filter::GC_const

 #include "../../../type/color.hpp"
 #include "../../../type/math/coord.hpp"

 #include "./_pure.hpp"


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
           class GC_const
            : public  GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_UV;

               using GC__pure::Ee_action;

               GC_const():M2_value( Ee_action::En_process ){}
               virtual ~GC_const(){}

               void Fv_reset(){ }
               Ee_action Fv_check( T_color & P_color, T_UV const& P_UV, T_size const& P_index )
                {
                 return M2_value;
                }

             public:
               Ee_action const& F_value( ){ return M2_value; }
             protected:
               Ee_action  & F1_value(){ return M2_value; }
             private:
               Ee_action    M2_value;

            };
         }
       }
     }
   }
 }

#endif
