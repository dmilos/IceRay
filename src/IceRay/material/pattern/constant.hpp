#ifndef Dh_IceRay_material_pattern_constant_hpp_
 #define Dh_IceRay_material_pattern_constant_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<N_type>


#include "./_pure.hpp"






 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         template< typename N_type >
          class GC_constant
           : public GS_DDMRM::S_IceRay::S_material::S_pattern::GC__special< N_type >
           { // DONE
            public:
             typedef N_type T_type, T_result;

              explicit GC_constant( T_type const& P_result )
               :M2_result( P_result )
               {
               }

            public:
              void  Fv_process( T_result &P_result, T_coord const& P_coord )const
               {
                P_result = M2_result;
               }

            private:
              T_type M2_result;
           };

         namespace S_constant
          {
           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::GT_size              > GT_size;
           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::GT_scalar            > GT_scalar;
           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar   > GT_color;

           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D > GT_coord2D;
           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D > GT_coord3D;
           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D > GT_coord4D;

           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D > GT_cell2D;
           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D > GT_cell3D;
           typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_constant<GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D > GT_cell4D;


          }

        }
      }
    }
  }

#endif
