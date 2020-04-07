#include   "./projective.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_transform;


struct GC_projective::C_intersect
 {
  bool M_hit;
  T_size M_depth;
  T_size M_index;
  T_affine M_2world;
  T_affine M_2local;
};

GC_projective::GC_projective()
 {
  ::math::linear::matrix::id( M2_2world      );
  ::math::linear::matrix::id( M2_2local      );
  ::math::linear::matrix::id( M2_transponate );

  F_child( nullptr );
 }

GC_projective::GC_projective
 (
   T_geometry    * P_child
 )
 :GC_projective()
 {
  F_child( P_child );
 }

GC_projective::GC_projective
 (
   T_geometry          * P_child
  ,T_projective   const& P_2world
 )
 :GC_projective()
 {
  F_child( P_child );
  F_2world( P_2world );
 }

GC_projective::~GC_projective()
 {
  // empty
 }

void GC_projective::Fv_reset( T_state &P_intersect )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  T_state        I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  I_head.M_hit = false;

  M2_geometry.M2__base->Fv_reset( I_tail );
}

GC_projective::T_size  GC_projective::Fv_weight()const
 {
  T_size Ir_weigh = 0;
  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_geometry.M2__base->Fv_weight();

  return Ir_weigh;
 }

GC_projective::T_size const& GC_projective::Fv_id( T_state const& P_intersect )const
 {
  return  M2_geometry.M2__base->Fv_id( P_intersect );
 }

GC_projective::T_size const&    GC_projective::Fv_quantity()const
 {
  static T_size Irs_quantity = 1;
  return Irs_quantity;
 }

GC_projective::T__base*         GC_projective::Fv_base( T_size const& P_index )const
 {
  return M2_geometry.M2__base;
 }

bool             GC_projective::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();

  if( false == I_head.M_hit )
   {
    P_fragment.M_index = 1;
    P_fragment.M__base = nullptr;
    return false;
   }

  ++P_fragment.M_depth;
  P_fragment.M_index = 0;
  P_fragment.M__base = M2_geometry.M2__base;
  P_state.F_tail<C_intersect>( P_fragment.M_state );

  return true;
 }

bool GC_projective::Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray )const
 {
  C_intersect &I_head = P_intersect.F_content<C_intersect>();
  T_state      I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray;

  ::math::linear::vector::addition( I_ray.M_direction,P_ray.M_direction, P_ray.M_origin );

  ::math::linear::homography::transform( I_ray.M_direction, M2_2local );
  ::math::linear::homography::transform( I_ray.M_origin, M2_2local, P_ray.M_origin );

  ::math::linear::vector::subtraction( I_ray.M_direction, I_ray.M_origin );
  ::math::linear::vector::length( I_ray.M_direction, T_scalar(1) );

  T_scalar I_lambda = P_lambda;

  if( false == M2_geometry.M2_intersect->Fv_intersect( I_lambda, I_tail, I_ray ) )
   {
    return I_head.M_hit = false;
   }

  ::math::linear::vector::combine( I_ray.M_origin, I_ray.M_origin, I_lambda, I_ray.M_direction );
  ::math::linear::homography::transform( I_ray.M_origin, M2_2world );
  ::math::linear::vector::subtraction( I_ray.M_origin, P_ray.M_origin );

  I_lambda = ::math::linear::vector::dot( P_ray.M_direction, I_ray.M_origin );

  if(  P_lambda < I_lambda )
   {
    return I_head.M_hit = false;
   }

  P_lambda = I_lambda;

  return I_head.M_hit = true;
 }

void GC_projective::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  C_intersect const &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_coord I_point;

  T_matrix m3;
  T_projective m4;

  m4 = M2_2world;
  ::math::linear::homography::transform( I_point, M2_2local, P_point );

  T_coord I_normal;
  M2_geometry.M2_normal->Fv_normal( I_normal, I_point, I_tail );

  T_scalar d3 =  m4[3][0]*I_point[0]
       +m4[3][1]*I_point[1]
       +m4[3][2]*I_point[2]
       +m4[3][3];

  T_scalar det =1.0/(d3*d3);

  T_scalar d0 =  m4[0][0]*I_point[0]
       +m4[0][1]*I_point[1]
       +m4[0][2]*I_point[2]
       +m4[0][3];
  m3[0][0] = ( m4[0][0] * d3  +  m4[3][0] * d0 ) * det;
  m3[0][1] = ( m4[1][0] * d3  +  m4[3][0] * d0 ) * det;
  m3[0][2] = ( m4[2][0] * d3  +  m4[3][0] * d0 ) * det;

  T_scalar d1 =  m4[1][0]*I_point[0]
      + m4[1][1]*I_point[1]
      + m4[1][2]*I_point[2]
      + m4[1][3] ;
  m3[1][0] = ( m4[0][1] * d3  +  m4[3][1] * d1 ) * det;
  m3[1][1] = ( m4[1][1] * d3  +  m4[3][1] * d1 ) * det;
  m3[1][2] = ( m4[2][1] * d3  +  m4[3][1] * d1 ) * det;

  T_scalar d2 =  m4[2][0]*I_point[0]
      + m4[2][1]*I_point[1]
      + m4[2][2]*I_point[2]
      + m4[2][3];
  m3[2][0] = ( m4[0][2] * d3  +  m4[3][2] * d2 ) * det;
  m3[2][1] = ( m4[1][2] * d3  +  m4[3][2] * d2 ) * det;
  m3[2][2] = ( m4[2][2] * d3  +  m4[3][2] * d2 ) * det;

  ::math::linear::matrix::transform( P_normal, m3, I_normal );

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_projective::T_location GC_projective::Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const
 {
  //C_intersect const& I_head = P_state.F_content<C_intersect>();
  //T_state            I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point;
  ::math::linear::homography::transform( I_point, F_2local(), P_point );

  return M2_geometry.M2_inside->Fv_inside( I_point/*, P_intersect */ );
 }

GC_projective::T_scalar GC_projective::Fv_distance( T_coord const& P_point )const
 {
  T_coord I_point;
  ::math::linear::homography::transform( I_point, M2_2local, P_point );
  auto d = M2_geometry.M2_distance->Fv_distance( I_point );
  return d;
 }

bool GC_projective::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const & P_state )const
 {
  C_intersect const &I_head = P_state.F_content<C_intersect>();
  T_state            I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point;
  ::math::linear::homography::transform( I_point, M2_2local, P_point );
  return M2_geometry.M2_uvw->Fv_uvw( P_uvw, I_point, I_tail );
 }


GC_projective::T_affine const&  GC_projective::Fv_2world( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );

  return I_intersect.M_2world;
}

GC_projective::T_affine const&  GC_projective::Fv_2local( T_state const&P_state )const
{
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  return I_intersect.M_2local;
}

bool GC_projective::F_2world( T_projective const& P_2world )
 {
  M2_2world = P_2world;

  ::math::linear::matrix::invert( M2_2local, M2_2world );

  T_interval I_box;
  T_interval I_base = M2_geometry.M2__base->F_box();

  ::math::linear::homography::transform( I_box[0], M2_2world, I_base[0] );
  I_box[1] = I_box[0];

  for( int x=0; x < 2; x++)
   {
    for( int y=0; y < 2; y++)
     {
      for( int z=0; z < 2; z++)
       {
        T_coord a, b;
        a[0] = I_base[x][0];
        a[1] = I_base[y][1];
        a[2] = I_base[z][2];
        ::math::linear::homography::transform( b, M2_2world, a );
        ::math::geometry::interval::extend( I_box, b );
       }
     }
   }

  F1_box( I_box );
  return true;
 }

bool GC_projective::F_2local( T_projective const& P_2local )
 {
  ::math::linear::matrix::invert( M2_2world, P_2local );
  return F_2world( M2_2world );
}

bool GC_projective::F_child( T_geometry *P_child )
 {
  M2_geometry.M2__base = ( ( nullptr == P_child ) ? &Fs_vacuum() : P_child );

  M2_geometry.M2_intersect = dynamic_cast<T2_intersect*>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_intersect) M2_geometry.M2_intersect = & Fs_vacuum();
  M2_geometry.M2_normal    = dynamic_cast<T2_normal   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_normal   ) M2_geometry.M2_normal    = & Fs_vacuum();
  M2_geometry.M2_inside    = dynamic_cast<T2_inside   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_inside   ) M2_geometry.M2_inside    = & Fs_vacuum();
  M2_geometry.M2_distance  = dynamic_cast<T2_distance *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_distance ) M2_geometry.M2_distance  = & Fs_vacuum();
  M2_geometry.M2_uvw       = dynamic_cast<T2_uvw      *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_uvw      ) M2_geometry.M2_uvw       = & Fs_vacuum();

  return F_2world( M2_2world );
}

GC_projective::T_vacuum & GC_projective::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }

