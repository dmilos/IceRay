#ifndef Dh_DDMRM_Iceray_render_beam__pure_HPP_
 #define Dh_DDMRM_Iceray_render_beam__pure_HPP_

 #include "..\..\type\color.hpp"
 #include "..\..\type\ray\beam.hpp"
 #include "..\ray\_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_beam
        {       
                
         class GC__pure
          {
           public:
             
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GT_beam        T_beam;
             typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure     T_ray;

             typedef GC__pure T__pure, T_this;

             GC__pure();
             virtual ~GC__pure();

             virtual void Fv_do( T_color & P_color, T_beam const& )=0;

           public:
             virtual void Fv_ray( T_ray * P_ray ){ M2_ray = P_ray; }
           protected:
             T_ray * & F1v_ray(){ return M2_ray; }
           private:
             T_ray * M2_ray; //!< dumb_ptr<>
             
          };

       } 
     }  
   }
 }

#endif
