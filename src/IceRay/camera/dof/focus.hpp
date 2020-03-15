#ifndef _DDMRM_IceRAY_camera_focus_HPP_
 #define _DDMRM_IceRAY_camera_focus_HPP_
 // GS_DDMRM::S_IceRa::S_camera::GC_focus

 #include "IceRay/utility/random.hpp"

  #include "../type/scalar.hpp"
  #include "../type/interval.hpp"

  #include "../_parent.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_dof
         {

          class GC_focus
           : public GS_DDMRM::S_IceRay::S_camera::GC__parent
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D     T_interval1D;
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar         T_scalar;
              typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar      T_gray;

            public:
              GC_focus ();
              GC_focus( T__pure *P_camera, T_size const& P_sample, T_interval1D const& P_aperture, T_interval1D const& P_focus, T_scalar const& P_gauss );
             ~GC_focus (){}

            public:
              T_size  Fv_beam( T_beam & P_beam, T_coord2D const& P_uv )const;

            public:
              T_interval1D const& F_aperture( void  )const{ return M2_aperture;  }
              bool                F_aperture( T_interval1D const& P_aperture );
            private:
              T_interval1D  M2_aperture;

            public:
              T_interval1D const& F_focus( void )const{ return M2_focus; }
              bool                F_focus( T_interval1D  const&  P_near );
            private:
              T_interval1D  M2_focus;

            public:
              T_size const& F_sample( )const{ return F_size(); }
              bool          F_sample( T_size const& P_size ){ return Fv_size( P_size ); }

            public:
              T_scalar  const& F_gauss( void )const{ return M2_gauss; }
             bool              F_gauss( T_scalar const& P_gauss );
            private:
              T_scalar M2_gauss;

            private:
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_gold1D        M2_randGold1D;
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol1D       M2_randSobol1D;
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol2D       M2_randSobol2D;
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_vdc2          M2_randVDC;
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard1D    M2_randStandard1D;
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard2D    M2_randStandard2D;
           };

         }
       }
     }
   }

#endif
