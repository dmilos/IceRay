// TODO In Progress!!

#include <boost/python.hpp>
#include "../../def_submodule.hpp"
#include "IceRay/type/picture/memory.hpp"
#include "IceRay/render/engine.hpp"
#include "IceRay/render/2pierce/uv.hpp"
#include "IceRay/render/2pierce/_pure.hpp"
#include "IceRay/render/2pierce/_base.hpp"
#include "IceRay/render/1pixel/uv.hpp"
#include "IceRay/render/1pixel/_pure.hpp"
#include "IceRay/render/1pixel/_base.hpp"
#include "IceRay/render/0scanner/block.hpp"
#include "IceRay/render/0scanner/_pure.hpp"

typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure   GTs_picture;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D    GTs_cell2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure     GTs_ray;
typedef GS_DDMRM::S_IceRay::S_render::GC_engine           GFs_engine;
typedef GS_DDMRM::S_IceRay::S_camera::GC__pure            GTs_camera;
