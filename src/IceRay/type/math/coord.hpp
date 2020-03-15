#ifndef Dh_DDMM_IceRay_type_coord_HPP_
 #define Dh_DDMM_IceRay_type_coord_HPP_
// GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, N_dimension>
// GT_size2D, GT_scalar2D,
// GT_size3D, GT_size, GT_scalar3D, GT_scalar,
// GT_size4D, GT_scalar4D,

// using namespace S_DDMRM::S_IceRay::S_geometry;

#include "IceRay/type/nothing.hpp"
#include "math/math.hpp"


 //#include "container/vector/array.hpp"
 #include "../basic/scalar.hpp"
 #include "../basic/size.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_coord
        {

         template < typename N_number, unsigned N_dimension >
          struct GC__model
           : S_DDMRM::S_type::GC_nothing
           {
            public:
              typedef N_number T_number;
              typedef ::math::linear::vector::vector<N_number, N_dimension>  T_typedef;
           };

          template< unsigned N_dimension >
           using GT_sizeND = typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_size ,N_dimension >::T_typedef;

          //template< unsigned N_dimension >
          // using GT_intND = GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_int,N_dimension >::T_typedef;
          //
          template< unsigned N_dimension >
           using GT_scalarND = typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar ,N_dimension >::T_typedef;


          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_size   ,1 >::T_typedef GT_size1D;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_int    ,1 >::T_typedef GT_int1D, GT_cell1D;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar ,1 >::T_typedef GT_scalar1D;

          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_size   ,2 >::T_typedef GT_size2D;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_int    ,2 >::T_typedef GT_int2D, GT_cell2D;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar ,2 >::T_typedef GT_scalar2D;

          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_size   ,3 >::T_typedef GT_size3D,   GT_size;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_int    ,3 >::T_typedef GT_int3D,    GT_cell3D, GT_int;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar ,3 >::T_typedef GT_scalar3D, GT_scalar;

          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_size   ,4 >::T_typedef GT_size4D;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_int    ,4 >::T_typedef GT_int4D,   GT_cell4D;
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar ,4 >::T_typedef GT_scalar4D;


          //namespace GS_DDMRM{ namespace S_math { namespace S_LA {  auto GF_length = ::math::linear::vector::length; }}}
        }
      }
    }
  }

#endif
