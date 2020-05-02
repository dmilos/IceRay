#ifndef Dh_IceRay_material_operation_mapping_translate_hpp_
 #define Dh_IceRay_material_operation_mapping_translate_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_operation::S_mapping::GC_translate


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

           class GC_translate
            {
             public:
                typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    T_coord;

               GC_translate( T_coord const& P_translate )
                :M2_translate( P_translate )
                {
                }

               ~GC_translate()
                {
                }

             public:
               void  Fv_process( T_coord &P_result, T_coord const& P_coord )const
                {
                 ::math::linear::vector::addition( P_result, M2_translate, P_coord );
                }
             private:
               T_coord M2_translate;
            };

           }
        }
      }
    }
  }

#endif
