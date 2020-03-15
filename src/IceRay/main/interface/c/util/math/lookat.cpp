

IceRayC_TypeAffine3D
IceRayC_UtilMathLinearAffineLookAt
 (
   IceRayC_TypeCoord3D const& P_eye
  ,IceRayC_TypeCoord3D const& P_view
  ,IceRayC_TypeCoord3D const& P_up
 )
 {
  IceRayC_TypeAffine3D Ir_world;
  ::math::linear::affine::look_at( Ir_world, P_eye, P_view, P_up );

  return Ir_world;
 }
