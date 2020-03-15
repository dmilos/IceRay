#ifndef Dh_DDMRM_Iceray_render_ray__base_HPP_
 #define Dh_DDMRM_Iceray_render_ray__base_HPP_

 #include "../../type/pointer/dumb.hpp"
 #include "../../geometry/_pure/_base.hpp"
 #include "../../geometry/volumetric/vacuum.hpp"

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {

         class GC__base
          : public GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size      T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar      T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar      T_color;

             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple       T_ray;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base T_geometry;
             typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum         T_vacuum;

           public:
                      GC__base();
             virtual ~GC__base();

           public:
             virtual void Fv_trace( T_color & P_color, T_ray const& )=0;

           public:
             T_size const&  F_depth( )const{ return M2_depth; }
             virtual bool  Fv_depth( T_size const& P_depth ){ M2_depth = P_depth; return true; }
           private:
             T_size M2_depth;

           public:
             T_scalar const&  F_trash( )const{ return M2_trash; }
             virtual bool    Fv_trash( T_scalar const& P_trash ){ M2_trash = P_trash; return true; }
           private:
             T_scalar M2_trash;

           public:
             virtual bool Fv_geometry( T_geometry * P_geometry );
           protected:
             T_geometry *& F1_geometry( ){ return M2_geometry; }
           private:
             T_geometry *M2_geometry; //!< dumb_ptr<>

           protected:
             static T_vacuum & Fs_vacuum();
           private:
          };

       }
     }
   }
 }

#endif
