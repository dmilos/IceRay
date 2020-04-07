#ifndef _b6de903e023044008bd1824ca29fbec4
#define _b6de903e023044008bd1824ca29fbec4

#include "./interval.h"

#include "IceRay/type/math/interval.hpp"

extern GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D c2cpp( IceRayC_TypeInterval1D P_this );
extern GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar2D c2cpp( IceRayC_TypeInterval2D P_this );
extern GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar3D c2cpp( IceRayC_TypeInterval3D P_this );
extern GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar4D c2cpp( IceRayC_TypeInterval4D P_this );

extern IceRayC_TypeInterval1D                              cpp2c(  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D P_this );
extern IceRayC_TypeInterval2D                              cpp2c(  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar2D P_this );
extern IceRayC_TypeInterval3D                              cpp2c(  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar3D P_this );
extern IceRayC_TypeInterval4D                              cpp2c(  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar4D P_this );

#endif
