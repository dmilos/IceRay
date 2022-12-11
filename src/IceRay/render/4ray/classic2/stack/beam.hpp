#ifndef Dh_DDMRM_Iceray_render_ray_classic2_stack__beam_HPP_
 #define Dh_DDMRM_Iceray_render_ray_classic2_stack__beam_HPP_

 #include "./input.hpp"
 #include "./output.hpp"

 #include "IceRay/material/medium/jurisdiction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {
         namespace S_classic2
          {
           namespace S_stack
            {

             class GC__beam
              : public GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__input
              , public GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__output
              {
               public:
                 typedef GC__input   T__input;
                 typedef GC__output  T__output;

               public:
                 typedef GS_DDMRM::S_IceRay::S_material::S_medium::GT_jurisdiction T_jurisdiction;

               public:
                          GC__beam(){}
                 virtual ~GC__beam(){}

               public:
                 //using T__input::Fv_state;
                 //using T__output::Fv_state;

               public:
                 T_jurisdiction const& F_jurisdiction()const{ return M2_jurisdiction; }
                 T_jurisdiction      & F_jurisdiction()     { return M2_jurisdiction; }
               protected:
                 T_jurisdiction      & F1_jurisdiction(){ return M2_jurisdiction; }
               private:
                 T_jurisdiction M2_jurisdiction;
              };

            }
          }
        }
      }
    }
  }

#endif