#ifndef Dh_IceRay_material_pattern__pure_hpp_
 #define Dh_IceRay_material_pattern__pure_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure
//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special<N_result>
//! GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size;
//! GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar;
//! GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color;
//! GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord2D;
//! GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord3D, GT__coord;
//! GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord4D;

#include "../../type/basic/size.hpp"
#include "../../type/basic/scalar.hpp"
#include "../../type/color.hpp"
#include "../../type/math/coord.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         namespace S_type
          {
           typedef GS_DDMRM::S_IceRay::S_type::GT_size                 GT_size;
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar               GT_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar      GT_color;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D    GT_coord2D;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    GT_coord3D,GT_coord;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D    GT_coord4D;
          }

          class GC__pure //! Just be a main non-tempplate base
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_scalar  T_scalar;
              typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_color   T_color;
              typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
            public:
              virtual ~GC__pure(){}

            public:
           };

         template< typename N_result >
          class GC__special  //! Take point in space return what-ever
           : public GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure
           {
            public:
              typedef N_result       T_result;

            public:
              virtual void Fv_process( T_result &P_result, T_coord const& P_coord )const=0;
           };


         typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special< GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_size    > GT__size;
         typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special< GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_scalar  > GT__scalar;
         typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special< GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_color   > GT__color;
         typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special< GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord2D > GT__coord2D;
         typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special< GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D > GT__coord3D, GT__coord;
         typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special< GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord4D > GT__coord4D;

        }
      }
    }
  }

#endif
