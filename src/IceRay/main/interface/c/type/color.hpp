#ifndef _d8653089084c4167a40c0bf10f8bb6d0
#define _d8653089084c4167a40c0bf10f8bb6d0

#include "./color.h"

#include "IceRay/type/color.hpp"

extern GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar c2cpp( IceRayC_Type_Color_Gray const&  );
extern GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar         c2cpp( IceRayC_Type_Color_RGB  const&  );
extern GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_scalar  c2cpp( IceRayC_Type_Color_HSL  const&  );
//extern GS_DDMRM::S_IceRay::S_type::S_color::GT_size4D c2cpp( IceRayC_Type_Color_RGBA const&  );

extern IceRayC_Type_Color_Gray cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar const& );
extern IceRayC_Type_Color_RGB  cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar         const& );
extern IceRayC_Type_Color_HSL  cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_scalar  const& );
//extern IceRayC_Type_Color_RGBA cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D const& );

#endif


