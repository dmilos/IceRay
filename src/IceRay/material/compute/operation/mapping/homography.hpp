#ifndef Dh_IceRay_material_operation_mapping_homography_hpp_
 #define Dh_IceRay_material_operation_mapping_homography_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_operation::S_mapping::GC_homography


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

           class GC_homography
            {
             public:
                typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    T_coord;
                typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    T_homography;

               GC_homography( T_homography const& P_homography )
                : M2_homography( P_homography )
                {
                }

               ~GC_homography()
                {
                }

             public:
               void  Fv_process( T_coord &P_result, T_coord const& P_coord )const
                {
                 // TODO ::math::linear::vector::addition( P_result, M2_homography, P_coord );
                }
             private:
               T_homography M2_homography;
            };

           }
        }
      }
    }
  }

#endif
