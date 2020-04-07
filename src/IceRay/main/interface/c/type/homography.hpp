#ifndef be837c2732804372aa3771ff55116ae4
#define be837c2732804372aa3771ff55116ae4

#include "./interval.h"

#include "./homography.h"
#include "IceRay/type/math/homography.hpp"


extern GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D c2cpp( IceRayC_Type_Math_Homography1D P_that );
extern IceRayC_Type_Math_Homography1D                        cpp2c(  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D const& T_this );

extern GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D c2cpp( IceRayC_Type_Math_Homography2D P_that );
extern IceRayC_Type_Math_Homography2D                        cpp2c(  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D const& T_this );

extern GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D c2cpp( IceRayC_Type_Math_Homography3D P_that );
extern IceRayC_Type_Math_Homography3D                        cpp2c(  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D const& T_this );

extern GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D c2cpp( IceRayC_Type_Math_Homography4D P_that );
extern IceRayC_Type_Math_Homography4D                        cpp2c(  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D const& T_this );




#endif
