#include   "./orthogonal.hpp"


using namespace GS_DDMRM::S_IceRay::S_camera::S_flat;


GC_orthogonal::GC_orthogonal()
 : GC_orthogonal( 1, 1 )
 {

 }

GC_orthogonal::GC_orthogonal( T_scalar const& P_aspect )
 :GC_orthogonal( 1, P_aspect )
 {
 }

GC_orthogonal::GC_orthogonal(  T_scalar const& P_width, T_scalar const& P_height )
 {
  F_width( P_width );
  F_height( P_height );
 }

GC_orthogonal::~GC_orthogonal()
 {

 }

GC_orthogonal::T_size
GC_orthogonal::Fv_beam
 (
   T_beam         &  P_beam
  ,T_coord2D const&  P_uv
 )const
 {
  T_coord & I_origin = P_beam[0].M_origin;

  I_origin[0] = P_uv[0] * M2_width2;
  I_origin[1] =       0;
  I_origin[2] = P_uv[1] * M2_height2;

  T_coord & I_direction = P_beam[0].M_direction;

  I_direction[0] = 0;
  I_direction[1] = 1;
  I_direction[2] = 0;

  return 1;
 }

void
GC_orthogonal::Fv_system( T_affine &P_matrix, T_coord2D const& P_uv )const
 {
  ::math::linear::affine::one( P_matrix );

  P_matrix.vector()[ 0 ] = P_uv[0]*M2_width2;
  P_matrix.vector()[ 1 ] =       0;
  P_matrix.vector()[ 2 ] = P_uv[1]*M2_height2;
 }

bool               GC_orthogonal::F_width( T_scalar const& P_width )
 {
  M2_width1  = P_width;
  M2_width2  = M2_width1/2;
  M2_aspect = M2_width1/ M2_height1;
  return bool( true );
 }

bool               GC_orthogonal::F_height( T_scalar const& P_height )
 {
  M2_height1 = P_height;
  M2_height2 = M2_height1/2;
  M2_aspect = M2_width1/ M2_height1;

  return bool( true );
 }

bool  GC_orthogonal::F_aspect( T_scalar const& P_aspect )
 {
  M2_aspect = P_aspect;
  M2_height1 = M2_aspect * M2_width1;
  M2_height2 = M2_height1/2;
  return bool( true );
 }


