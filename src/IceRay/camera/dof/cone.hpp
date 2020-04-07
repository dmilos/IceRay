#ifndef _DDMRM_IceRAY_camera_cone_HPP_
 #define _DDMRM_IceRAY_camera_cone_HPP_

 // GS_DDMRM::S_IceRa::S_camera::GC_cone

 #include "IceRay/utility/random.hpp"

 #include "IceRay/type/basic/size.hpp"
 #include "IceRay/type/basic/scalar.hpp"
 #include "IceRay/utility/table/hexagon.hpp"

 #include "../_parent.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_camera
      {
       namespace S_dof
        {

         class GC_cone
          : public GS_DDMRM::S_IceRay::S_camera::GC__parent
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size           T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar         T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar      T_gray;

           public:
             GC_cone( );
             GC_cone( T_size const& P_sample, T_scalar const& P_aperture );
             GC_cone( T__pure *P_camera, T_size const& P_sample, T_scalar const& P_aperture );
             GC_cone( T__pure *P_camera, T_size const& P_sample, T_scalar const& P_aperture, T_scalar const& P_gauss );
             ~GC_cone();

           public:
             T_size   Fv_beam( T_beam & P_beam, T_coord2D const& P_uv )const;

           protected:
             void Fv_system( T_affine &P_affine, T_coord2D const& P_uv );

           public:
             bool Fv_size( T_size const& P_size );
           public:
             T_size const& F_sample( )const{ return F_size(); }
             bool          F_sample( T_size const& P_size ){ return this->Fv_size( P_size ); }
           
            private:
            T_size M2_index;
            public:
              T_scalar const&  F_aperture( void )const{ return M2_aperture; }
              bool             F_aperture( T_scalar const& P_aperture );
            private:
              T_scalar M2_aperture;
           
            public:
              T_scalar const&  F_gauss( void )const{ return M2_gauss; }
              bool             F_gauss( T_scalar const& P_gauss );
            private:
              T_scalar M2_gauss;

           private:
             mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard2D  M2_randStandard2D;
             mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol2D     M2_randSobol2D;
             mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_VaLND       M2_randVaLND;
             static  GS_DDMRM::S_IceRay::S_utility::S_table::GC_hexagon      M2s_hexagon;
          };

        }
      }
    }
  }

#endif
