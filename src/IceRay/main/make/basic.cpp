

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"
#include "IceRay/type/color.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_size                   GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar        GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar        GTs_coord;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                 GTs_scalar;

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size          GTs_dimension;

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {

GTs_color make_color( GTs_scalar P_r, GTs_scalar P_g, GTs_scalar P_b )
{
 GTs_color Ir_color;
 Ir_color.container( { P_r,P_g, P_b } );
 Ir_color.set( 0, P_r );
 Ir_color.set( 1, P_g );
 Ir_color.set( 2, P_b );
 return Ir_color;
}

GTs_coord make_coord3( GTs_scalar P_x, GTs_scalar P_y, GTs_scalar P_z )
{
 GTs_coord Ir_coord;
 Ir_coord[0] = P_x; Ir_coord[1] = P_y; Ir_coord[2] = P_z;
 return Ir_coord;
}

GTs_coord make_coord3_unit( GTs_scalar P_x, GTs_scalar P_y, GTs_scalar P_z )
{
 GTs_coord Ir_coord;
 Ir_coord[0] = P_x; Ir_coord[1] = P_y; Ir_coord[2] = P_z;

 ::math::linear::vector::length( Ir_coord, GTs_scalar(1) );

 return Ir_coord;
}

GTs_dimension make_dimension( GTs_size P_x,GTs_size P_y,GTs_size P_z )
{
 GTs_dimension Ir_dimension;
 Ir_dimension[0] = P_x; Ir_dimension[1] = P_y; Ir_dimension[2] = P_z;
 return Ir_dimension;
}


     }
   }
 }