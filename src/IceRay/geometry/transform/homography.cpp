#include   "./homography.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_transform;


struct GC_homography::C_intersect
 {
  bool M_hit;
  T_size M_depth;
  T_size M_index;
  T_affine M_2world;
  T_affine M_2local;
 };

GC_homography::GC_homography()
 {
  ::math::linear::matrix::id( M2_2world      );
  ::math::linear::matrix::id( M2_2local      );

  F_child( nullptr );
 }

GC_homography::GC_homography
 (
   T_geometry    * P_child
 )
 :GC_homography()
 {
  F_child( P_child );
 }

GC_homography::GC_homography
 (
   T_geometry          * P_child
  ,T_homography   const& P_2world
 )
 :GC_homography()
 {
  F_child( P_child );
  F_2world( P_2world );
 }

GC_homography::~GC_homography()
 {
  // empty
 }

void GC_homography::Fv_reset( T_state &P_intersect )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  T_state        I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  I_head.M_hit = false;

  M2_geometry.M2__base->Fv_reset( I_tail );
}

GC_homography::T_size  GC_homography::Fv_weight()const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_geometry.M2__base->Fv_weight();

  return Ir_weigh;
 }

GC_homography::T_size const& GC_homography::Fv_id( T_state const& P_intersect )const
 {
  C_intersect  const &I_head = P_intersect.F_content<C_intersect>();
  T_state             I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  return  M2_geometry.M2__base->Fv_id( I_tail );
 }

GC_homography::T_size const&    GC_homography::Fv_quantity()const
 {
  static T_size Irs_quantity = 1;
  return Irs_quantity;
 }

GC_homography::T__base*         GC_homography::Fv_base( T_size const& P_index )const
 {
  return M2_geometry.M2__base;
 }

bool             GC_homography::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
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

bool GC_homography::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const
 {
  static T_scalar Is_infinity = 1e+12;//!< T_scalar( std::numeric_limits<T_scalar>::???() );
  static T_scalar Is_epsilon  = 1e-12; 

  C_intersect &I_head = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_origin    = P_ray.M_origin;
  T_coord const& I_direction = P_ray.M_direction;

  T_scalar I_move = 0;
  if(false)if( false == math::geometry::interval::in( F_box(), I_origin ) )
   {  //! Other side fix. in progress
    std::tuple<unsigned, T_scalar, unsigned, T_scalar > I_line;

    if( false == ::math::geometry::interval::intersect( I_line, F_box(), { I_origin, I_direction }, Is_epsilon ) )
     {
      return I_head.M_hit = false;
     }

    I_move = std::get<1>( I_line );
    if( ( Is_epsilon < I_move ) && ( I_move < P_lambda ) )
     {
      ::math::linear::vector::combine( I_origin, P_ray.M_origin, I_move, P_ray.M_direction );
     }
    else
     {
      I_move = std::get<3>( I_line );
      if( ( Is_epsilon < I_move ) && ( I_move < P_lambda ) )
       {
        ::math::linear::vector::combine( I_origin, P_ray.M_origin, I_move, P_ray.M_direction );
       }
      else
       {
        return I_head.M_hit = false;
       }
     }
   }

  T_coord I_tip;
  T_ray I_ray;

  ::math::linear::homography::transform( I_ray.M_origin, M2_2local, I_origin );
  ::math::linear::vector::addition( I_tip, I_direction, I_origin );
  ::math::linear::homography::transform( I_ray.M_direction, M2_2local, I_tip );
  ::math::linear::vector::subtraction( I_ray.M_direction, I_ray.M_origin );
  auto I_length = ::math::linear::vector::length( I_ray.M_direction, T_scalar(1) );

  //T_coord I_far;
  //::math::linear::vector::combine( I_tip, I_ray.M_origin, P_lambda, I_ray.M_direction );
  //::math::linear::homography::transform( I_far, M2_2local, I_tip );
  //::math::linear::vector::subtraction( I_far, I_ray.M_origin );

  T_scalar I_lambda = Is_infinity; //I_length * ::math::linear::vector::dot( I_far, I_ray.M_direction  );

  if( false == M2_geometry.M2_intersect->Fv_intersect( I_lambda, I_tail, I_ray ) )
   {
    return I_head.M_hit = false;
   }
  T_scalar I_check = I_lambda / I_length;

  ::math::linear::vector::combine( I_tip, I_ray.M_origin, I_lambda, I_ray.M_direction );
  ::math::linear::homography::transform( I_ray.M_origin, M2_2world, I_tip );
  ::math::linear::vector::subtraction( I_ray.M_origin, P_ray.M_origin );

  I_lambda = I_move + ::math::linear::vector::dot( I_direction, I_ray.M_origin );
  if( P_lambda < I_lambda )
   {
    return I_head.M_hit = false;
   }

  P_lambda = I_lambda;
  return I_head.M_hit = true;
 }

void GC_homography::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  C_intersect const &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_coord I_point;

  ::math::linear::homography::transform( I_point, M2_2local, P_point );

  T_coord I_normal;
  M2_geometry.M2_normal->Fv_normal( I_normal, I_point, I_tail );

  T_matrix J;  ::math::linear::homography::jacobian( J, F_2local(), I_point );
  ::math::linear::matrix::transpose( J );

  ::math::linear::matrix::transform( P_normal, J, I_normal );
  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_homography::T_location GC_homography::Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const
 {
  //C_intersect const& I_head = P_state.F_content<C_intersect>();
  //T_state            I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point;
  ::math::linear::homography::transform( I_point, F_2local(), P_point );

  return M2_geometry.M2_inside->Fv_inside( I_point/*, P_intersect */ );
 }

GC_homography::T_scalar GC_homography::Fv_distance( T_coord const& P_point )const
 { // TODO
  T_coord I_point;
  ::math::linear::homography::transform( I_point, M2_2local, P_point );
  auto d = M2_geometry.M2_distance->Fv_distance( I_point );
  return d;
 }

bool GC_homography::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const & P_state )const
 {
  C_intersect const& I_head = P_state.F_content<C_intersect>();
  T_state            I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point;
  ::math::linear::homography::transform( I_point, M2_2local, P_point );
  return M2_geometry.M2_uvw->Fv_uvw( P_uvw, I_point, I_tail );
 }

GC_homography::T_affine const&  GC_homography::Fv_2world( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );

  return I_intersect.M_2world;
 }

GC_homography::T_affine const&  GC_homography::Fv_2local( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  return I_intersect.M_2local;
 }

bool GC_homography::F_2world( T_homography const& P_2world )
 {
  M2_2world = P_2world;

  ::math::linear::matrix::invert( M2_2local, M2_2world );

  T_interval I_box;
  T_interval const& I_base = M2_geometry.M2__base->F_box();

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

bool GC_homography::F_2local( T_homography const& P_2local )
 {
  ::math::linear::matrix::invert( M2_2world, P_2local );
  return F_2world( M2_2world );
 }

bool GC_homography::F_child( T_geometry *P_child )
 {
  M2_geometry.M2__base = ( ( nullptr == P_child ) ? &Fs_vacuum() : P_child );

  M2_geometry.M2_intersect = dynamic_cast<T2_intersect*>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_intersect) M2_geometry.M2_intersect = & Fs_vacuum();
  M2_geometry.M2_normal    = dynamic_cast<T2_normal   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_normal   ) M2_geometry.M2_normal    = & Fs_vacuum();
  M2_geometry.M2_inside    = dynamic_cast<T2_inside   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_inside   ) M2_geometry.M2_inside    = & Fs_vacuum();
  M2_geometry.M2_distance  = dynamic_cast<T2_distance *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_distance ) M2_geometry.M2_distance  = & Fs_vacuum();
  M2_geometry.M2_uvw       = dynamic_cast<T2_uvw      *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_uvw      ) M2_geometry.M2_uvw       = & Fs_vacuum();

  return F_2world( M2_2world );
 }

GC_homography::T_vacuum & GC_homography::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }

