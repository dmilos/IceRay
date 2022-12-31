#include "./memory.hpp"

using namespace GS_DDMRM::S_IceRay::S_material::S_compute;

GC_memory::GC_memory()
 {
  M2_memory.resize( T_component::En__size, nullptr );
  M2_memory[ T_component::En__begin   ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fake;

  M2_memory[ T_component::En_bool     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_bool   , S_memory::En_Bool__End >();

  M2_memory[ T_component::En_int8     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_int8   , 10 >();
  M2_memory[ T_component::En_uint8    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_uint8  , 10 >();
  M2_memory[ T_component::En_integer  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_integer, 10 >();
  M2_memory[ T_component::En_size     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_size   , S_memory::En_Size__End >();
  M2_memory[ T_component::En_scalar   ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_scalar , S_memory::En_Scalar__End >();

  M2_memory[ T_component::En_color    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_color  , S_memory::En_Color__End >();

  M2_memory[ T_component::En_coord2D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord2D, S_memory::En_Coord2D__End >();
  M2_memory[ T_component::En_coord3D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord3D, S_memory::En_Coord3D__End >();
  M2_memory[ T_component::En_coord4D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord4D, S_memory::En_Coord4D__End >();

  M2_memory[ T_component::En_cell2D   ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell2D, 10 >();
  M2_memory[ T_component::En_cell3D   ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell3D, 10 >();
  M2_memory[ T_component::En_cell4D   ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell4D, 10 >();

  M2_memory[ T_component::En_affine2D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine2D, 10 >();
  M2_memory[ T_component::En_affine3D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine3D, 10 >();
  M2_memory[ T_component::En_affine4D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine4D, 10 >();

  M2_memory[ T_component::En_ray      ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_dynamic< T_ray >();
  M2_memory[ T_component::En_spot     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_dynamic< T_spot >( S_memory::En_Spot__End );
  M2_memory[ T_component::En_light    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_light*,   S_memory::En_Light__End >();

  M2_memory[ T_component::En_chunk             ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometry_Base::T_state, 10 >();
  M2_memory[ T_component::En_geometry_Base     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometry_Base    *, 10 >();
  M2_memory[ T_component::En_geometryNormal    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryNormal   *, 10 >();
  M2_memory[ T_component::En_geometryIntersect ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryIntersect*, 10 >();
  M2_memory[ T_component::En_geometryUVW       ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryUVW      *, 10 >();
  M2_memory[ T_component::En_geometryDistance  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryDistance *, 10 >();
 }
 
// F_initScalar(){ ... }
// F_initColor(){ ... }