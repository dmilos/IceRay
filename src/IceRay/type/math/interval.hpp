#ifndef Dh_DDMM_IceRay_type_interval_HPP_
 #define Dh_DDMM_IceRay_type_interval_HPP_
// GS_DDMRM::S_IceRay::S_type::S_interval::GC__model<N_number, N_dimension>
// GT_scalar1D, GT_size1D
// GT_size2D, GT_scalar2D,
// GT_size3D, GT_size, GT_scalar3D, GT_scalar,
// GT_size4D, GT_scalar4D,

 #include "IceRay/type/nothing.hpp"
 #include "math/math.hpp"


 #include "../basic/size.hpp"
 #include "../basic/integer.hpp"
 #include "../basic/scalar.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_interval
        {

         template< typename N_number, unsigned N_dimension >
          struct GC__model
           : public S_DDMRM::S_type::GC_nothing
           {
            public:
              typedef N_number T_number;

              typedef ::math::geometry::interval::structure<T_number, N_dimension > T_typedef;
           };

         template< typename N_number >
          struct GC__model< N_number, 1 >
           : public S_DDMRM::S_type::GC_nothing
           {
            public:
              typedef N_number T_number;

              typedef ::math::geometry::interval::structure<T_number, 1 > T_typedef;
           };


         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar,  1 >::T_typedef GT_scalar1D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_size,    1 >::T_typedef GT_size1D;
         typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_integer, 1 >::T_typedef GT_int1D;

         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_scalar,   2 >::T_typedef GT_scalar2D;
         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_size,     2 >::T_typedef GT_size2D;
         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_integer,  2 >::T_typedef GT_int2D;

         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_scalar,   3 >::T_typedef GT_scalar3D, GT_scalar;
         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_size,     3 >::T_typedef GT_size3D,   GT_size;
         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_integer,  3 >::T_typedef GT_int3D,    GT_int;

         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_scalar,   4 >::T_typedef GT_scalar4D;
         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_size,     4 >::T_typedef GT_size4D;
         typedef GC__model<GS_DDMRM::S_IceRay::S_type::GT_integer,  4 >::T_typedef GT_int4D;

        }
      }
    }
  }


#endif
