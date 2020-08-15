#ifndef Dh_DDMM_IceRay_type_homography_HPP_
 #define Dh_DDMM_IceRay_type_homography_HPP_

// GS_DDMRM::S_IceRay::S_type::S_homography::GC__model<N_number, N_dimension>
// GS_DDMRM::S_IceRay::S_type::S_homography::GT_homography,
// GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D,
// GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D,
// GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D,
// GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D


 #include "../basic/scalar.hpp"
#include "math/math.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_homography
        {

         template< typename N_scalar, unsigned N_size >
          struct GC__model
           : public S_DDMRM::S_type::GC_nothing
           {
            public:
              typedef ::math::linear::homography::structure< N_scalar, N_size > T_typedef;
           };

         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 1 >::T_typedef GT_scalar1D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 2 >::T_typedef GT_scalar2D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 3 >::T_typedef GT_scalar3D, GT_homography, GT_scalar;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 4 >::T_typedef GT_scalar4D;

        }
      }
    }
  }

  //namespace  GS_DDMRM{namespace S_math{namespace S_LA{namespace S_homography
  // {
  //  template< typename scalar_name , unsigned dimension_number >
  //    using GF_transform = ::math::linear::homography::trasform<scalar_name,dimension_number>; }
  //
  //  } } }


#endif

