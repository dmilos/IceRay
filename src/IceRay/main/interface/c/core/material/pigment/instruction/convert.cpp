#include "IceRay/material/compute/convert/convert.hpp"

#include "./convert.hpp"

#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Convert_##D_P
#define P(D_P) IceRayC_##D_P
#define S(D_P) IceRayC_Type_Size P_##D_P
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle
#define E IceRayC__EXPORT
#define D IceRayC__DECLSPEC

H F( Bool2Bool0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2bool    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Bool2Integer0      )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2integer    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Bool2Size0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2size    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Bool2Scalar0       )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2scalar    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Bool2Color0        )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2color    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Bool2Coord2D0     )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2coord2D    Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr; // TODO
 }

H F( Bool2Coord3D0      )( S( result ), S( left ) )
 {
  // typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2coord3D    Tf_this;
  // auto Ir_result = new Tf_this{ P_result, P_left  };
  // return cpp2c( Ir_result );
  return nullptr;// TODO
 }


H F( Integer2Bool0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_integer2bool    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Integer2Integer0      )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_integer2integer    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Integer2Size0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_integer2size    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Integer2Scalar0       )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_integer2scalar   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Integer2Color0        )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_integer2color   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Integer2Coord2D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_integer2coord2D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Integer2Coord3D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_integer2coord3D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }


H F( Size2Bool0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2bool   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Size2Integer0      )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2integer   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Size2Size0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2size   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Size2Scalar0       )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2scalar   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Size2Color0        )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2color   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Size2Coord2D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2coord2D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Size2Coord3D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2coord3D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }


H F( Scalar2Bool0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2bool   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Scalar2Integer0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2integer   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Scalar2Size0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2size   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Scalar2Scalar0       )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2scalar   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Scalar2Color0        )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2color    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Scalar2Coord2D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2color2D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Scalar2Coord3D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2color3D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }


H F( Color2Bool0         )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2bool   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Color2Integer0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2integer   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Color2Size0         )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2size   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Color2Scalar0       )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2scalar   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Color2Color0        )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2color   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Color2Coord2D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2coord2D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Color2Coord3D0      )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2coord3D   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
  return nullptr;
 }


H F( Coord2D2Bool0         )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2D2bool   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord2D2Integer0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2D2integer   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord2D2Size0         )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2D2size   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord2D2Scalar0       )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2D2scalar   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord2D2Color0        )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2D2color   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord2D2Coord2D0      )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2D2coord2D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Coord2D2Coord3D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2D2coor3D    Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }


H F( Coord3D2Bool0         )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord3D2bool    Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord3D2Integer0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord3D2integer    Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord3D2Size0         )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord3D2size    Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord3D2Scalar0       )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord3D2scalar    Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord3D2Color0        )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord3D2color   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }

H F( Coord3D2Coord2D0      )( S( result ), S( left ) )
 {
  //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord3D2coord2D   Tf_this;
  //auto Ir_result = new Tf_this{ P_result, P_left  };
  //return cpp2c( Ir_result );
  return nullptr;// TODO
 }

H F( Coord3D2Coord3D0      )( S( result ), S( left ) )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord3D2coord3D   Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left  };
  return cpp2c( Ir_result );
 }


#undef D
#undef E
#undef H
#undef S
#undef P
#undef F
