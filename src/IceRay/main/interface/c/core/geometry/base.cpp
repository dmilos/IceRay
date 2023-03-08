#include "../../type/interval.hpp"

#include "IceRay/geometry/_pure/_pure.hpp"

#include "./handle.hpp"
#include "./base.h"
#include "./base.hpp"


IceRayC_Type_Bool IceRayC_Geometry__Base_Box_Get( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D* P_box )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;

  auto I_this =  c2cpp( P_this );
  if( nullptr == I_this )
   {
    return 0;
   }

  *P_box = cpp2c( I_this->F_box(  ) );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Geometry__Base_Box_Set( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D* P_box )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;

  auto I_this =  c2cpp( P_this );
  if( nullptr == I_this )
   {
    return 0;
   }

  return I_this->Fv_box( c2cpp( *P_box ) )? 1: 0;
 }