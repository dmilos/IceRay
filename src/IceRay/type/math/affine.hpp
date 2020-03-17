#ifndef Dh_DDMM_IceRay_type_affine_HPP_
 #define Dh_DDMM_IceRay_type_affine_HPP_
// GS_DDMRM::S_IceRay::S_type::S_affine::GC__model<N_number, N_dimension>
// GT_scalar1D,
// GT_scalar2D,
// GT_scalar3D,
// GT_scalar4D


 #include "../basic/report.hpp"
 #include "../basic/scalar.hpp"
#include "math/math.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_affine
        {

         template< typename N_number, unsigned N_size >
          struct GC__model
           : public S_DDMRM::S_type::GC_nothing
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_report T_report;

              typedef ::math::linear::affine::structure< N_number, N_size > T_typedef;
           };

         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 1 >::T_typedef GT_scalar1D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 2 >::T_typedef GT_scalar2D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 3 >::T_typedef GT_scalar3D, GT_affine, GT_scalar;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar, 4 >::T_typedef GT_scalar4D;

        }
      }
    }
  }

  //namespace  GS_DDMRM{namespace S_math{namespace S_LA{namespace S_matrix 
  // {
  //  template< typename scalar_name , unsigned dimension_number > 
  //    using GF_transform = ::math::linear::affine::trasform<scalar_name,dimension_number>; } 
  //
  //  } } } 


#endif

