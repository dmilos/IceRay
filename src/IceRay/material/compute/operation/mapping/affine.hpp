#ifndef Dh_IceRay_material_operation_mapping_affine_hpp_
 #define Dh_IceRay_material_operation_mapping_affine_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_operation::S_mapping::GC_affine



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_operation
        {
         namespace S_mapping
          {

           class GC_affine
            {
             public:
                typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    T_coord;
                typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    T_affine;

               GC_affine( T_affine const& P_affine )
               :M2_affine( P_affine )
                {
                }

               ~GC_affine()
                {
                }

             public:
               void  Fv_process( T_coord &P_result, T_coord const& P_coord )const
                {
                 //::math::linear::affine::transform( P_result, M2_affine, P_coord );
                }
             private:
               T_affine M2_affine;
            };

           }
        }
      }
    }
  }

#endif
