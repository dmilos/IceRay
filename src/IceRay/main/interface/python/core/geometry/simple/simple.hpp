#include <boost/python.hpp>
#include "../../../def_submodule.hpp"

#include "IceRay/geometry/_pure/_base.hpp"
#include "IceRay/type/basic/basic.hpp"
#include "IceRay/type/math/coord.hpp"
#include "IceRay/type/math/matrix.hpp"
#include "IceRay/type/math/affine.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              GTs_scalar;

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D   GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D   GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D   GTs_coord4D;

typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D  GTs_matrix2D;
typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D  GTs_matrix3D;
typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D  GTs_matrix4D;

typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar2D  GTs_affine2D;
typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D  GTs_affine3D;
//typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar4D  GTs_affine4D;


typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base    GTs__base;


