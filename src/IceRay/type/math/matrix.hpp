#ifndef Dh_DDMM_IceRay_type_matrix_HPP_
 #define Dh_DDMM_IceRay_type_matrix_HPP_
// GS_DDMRM::S_IceRay::S_type::S_matrix::GC__model<N_number, N_dimension>
// GT_scalar1D,
// GT_scalar2D,
// GT_scalar3D,
// GT_scalar4D

 #include "IceRay/type/nothing.hpp"

 #include "../basic/report.hpp"
 #include "../basic/scalar.hpp"
 #include "math/math.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_matrix
        {

         template< typename N_number, unsigned N_width, unsigned N_height >
          struct GC__model
           : public S_DDMRM::S_type::GC_nothing
           {
            public:

              typedef ::math::linear::matrix::structure<N_number, N_width, N_height > T_typedef;
           };

         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar,  1, 1 >::T_typedef GT_scalar1D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar,  2, 2 >::T_typedef GT_scalar2D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar,  3, 3 >::T_typedef GT_scalar3D, GT_matrix;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar,  4, 4 >::T_typedef GT_scalar4D;

        }
      }
    }
  }


#endif

