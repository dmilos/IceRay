#ifndef _c109f44545374dabbf416f933e950c21
#define _c109f44545374dabbf416f933e950c21


#include "./light.h"
#include "IceRay/light/_pure.hpp"

extern GS_DDMRM::S_IceRay::S_light::S_type::GC_spot c2cpp( IceRayC_TypeSpot P_that );
extern IceRayC_TypeSpot                             cpp2c(  GS_DDMRM::S_IceRay::S_light::S_type::GC_spot P_this );

extern IceRayC_Light_Handle                    cpp2c( GS_DDMRM::S_IceRay::S_light::GC__pure* P_this );
extern GS_DDMRM::S_IceRay::S_light::GC__pure * c2cpp( IceRayC_Light_Handle P_that );


#endif

#include "./transform.hpp"