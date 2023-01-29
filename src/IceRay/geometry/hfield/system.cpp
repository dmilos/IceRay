#include "./hfield.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_hfield;


struct GC_system::C_intersect
 {
  bool M_hit;
  T_size M_x;
  T_size M_y;
 };


GC_system::GC_system()
 :GC_system( &Fs_table(), &Fs_quad() )
 {
 }

GC_system::GC_system( T_generator* P_generator, T_object* P_object )
 :M2_generator( &Fs_theone() )
 ,M2_object( P_object )
 {
  T_coord I_lo; ::math::linear::vector::fill( I_lo, -1 );
  T_coord I_hi; ::math::linear::vector::fill( I_hi, +1 );
  F1_box( T_box{ I_lo, I_hi } );
  F_generator( P_generator );
 }

GC_system::~GC_system( )
 {
 }

bool GC_system::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_intersect
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  static T_scalar Is_infinity= 1e+12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;

  auto const& I_size = F_generator().F_size();

  auto const& I_origin    = P_ray.M_origin;
  auto const& I_direction = P_ray.M_direction;

  std::tuple<unsigned, T_scalar, unsigned, T_scalar > I_intervalW;
  auto const I_world = ::math::geometry::interval::intersect( I_intervalW, F_box(), { P_ray.M_origin, P_ray.M_direction }, Is_epsilon );
  if( false == I_world )
   {
    return false;
   }
#if defined( _DEBUG )
  T_coord I_enterW; ::math::linear::vector::combine( I_enterW,  P_ray.M_origin, std::get<1>( I_intervalW ), P_ray.M_direction );
  T_coord I_exitW;  ::math::linear::vector::combine( I_exitW,   P_ray.M_origin, std::get<3>( I_intervalW ), P_ray.M_direction );
#endif
  T_scalar I_exit = std::min<T_scalar>( std::get<3>( I_intervalW ), P_lambda /* / I_length */ );
  if( I_exit < T_scalar(0) )
   {
    return false;
   }
  T_scalar I_enter  = std::get<1>( I_intervalW );
  if( P_lambda < I_enter )
   {
    return false;
   }

  T_ray I_ray;
  I_ray.M_direction = P_ray.M_direction;
  I_ray.M_origin = P_ray.M_origin;

  T_coord I_scale;
  I_scale[0] = ( I_size[0] - 1 )/ ( F_box().hi()[0] - F_box().lo()[0]);
  I_scale[1] = ( I_size[1] - 1 )/ ( F_box().hi()[1] - F_box().lo()[1]);
  I_scale[2] = ( I_size[2] - 1 )/ ( F_box().hi()[2] - F_box().lo()[2]);
  ::math::linear::vector::multiply( I_ray.M_direction, I_scale );

  T_scalar I_length = ::math::linear::vector::length( I_ray.M_direction );

  T_cell3D I_cell;
  I_cell[2] = 0;  //!< alwas 0
  if( I_enter < T_scalar(0) )
   { //! We are in
    I_cell[0] = T_integer( F2_world2local( I_origin[0], 0 ) ); // I_intersect.M_x
    I_cell[1] = T_integer( F2_world2local( I_origin[1], 1 ) ); // I_intersect.M_y
    I_enter = T_scalar(0);
   }
  else
   {
    for( T_size I_projection=0; I_projection < 2; ++I_projection )
     {
      T_scalar I_value = I_origin[I_projection]  +  I_enter * I_direction[I_projection];

      I_cell[I_projection] = (int)F2_world2local( I_value, I_projection ); //!< this will work in theory

      if( I_cell[I_projection]              <         0 )
       {
        I_cell[I_projection] = 0;
        continue;
       }
      if( T_integer(I_size[I_projection]) < I_cell[I_projection] + 2 )
       {
        I_cell[I_projection] = I_size[I_projection] - 2;
        continue;
       }
       // no ned for correction
     }
   }
  T_coord    I_step;
  T_coord    I_plane;
  T_cell3D   I_fence;
  T_cell3D   I_move;

  for( T_size I_projection=0; I_projection < 3; ++I_projection )
   {
    auto const& I_lo = F_box().lo();

    if( Is_epsilon < P_ray.M_direction[I_projection] )
     {
      I_plane[I_projection] = ( I_cell[I_projection] + 1 ) * M2_step[I_projection] + I_lo[I_projection];
      I_step[I_projection]  = +1 * M2_step[I_projection];
      I_move[I_projection]  = +1;
      I_fence[I_projection] = I_size[I_projection] - 1;
      continue;
     }

    if( P_ray.M_direction[I_projection] < -Is_epsilon )
     {
      I_plane[I_projection] = ( I_cell[I_projection] + 0 )*M2_step[I_projection] + I_lo[I_projection];
      I_step[I_projection]  = -1 * M2_step[I_projection];
      I_move[I_projection]  = -1;
      I_fence[I_projection] = -1;
      continue;
     }

    I_plane[I_projection] = ( I_cell[I_projection] + 0 )*M2_step[I_projection] + I_lo[I_projection];
    I_step[I_projection]  = 0 * M2_step[I_projection]; //!< irrelevant
    I_move[I_projection]  = 0;
    I_fence[I_projection] = 0;
   }

  T_scalar I_behind;
  T_scalar I_front  = I_enter;
  while( true )
   {
    int I_axis = -1;
    I_behind = I_front;
    I_front = Is_infinity;
    for( T_size I_projection=0; I_projection < 3; ++I_projection )
     { // find which plane we hit
      if( fabs( I_direction[I_projection] ) < Is_epsilon )
       {
        continue;
       }
      T_scalar I_l = ( I_plane[I_projection] - I_origin[I_projection] ) / I_direction[I_projection];
      if( I_l < I_front )
       {
        I_axis = I_projection;
        I_front = I_l;
       }
     }
    if( -1 == I_axis )
     {  //!< Internal protection
      break;
     }

#if defined( _DEBUG )
    T_coord I_frontW; ::math::linear::vector::combine( I_frontW, P_ray.M_origin, I_front, P_ray.M_direction );
#endif

    T_scalar I_lambda = I_front + 1e-6;
    bool I_hit;
    {
     auto I_00 = F_generator().Fv_value( I_cell[0] + 0, I_cell[1] + 0 );
     auto I_10 = F_generator().Fv_value( I_cell[0] + 1, I_cell[1] + 0 );
     auto I_01 = F_generator().Fv_value( I_cell[0] + 0, I_cell[1] + 1 );
     auto I_11 = F_generator().Fv_value( I_cell[0] + 1, I_cell[1] + 1 );
     {
      I_ray.M_origin = F2_world2local( P_ray.M_origin );
      I_ray.M_origin[0] -= I_cell[0]; I_ray.M_origin[1] -= I_cell[1]; I_ray.M_origin[2] -= I_cell[2];
     }
#if defined( _DEBUG )
     T_coord I_frontL; ::math::linear::vector::combine( I_frontL, I_ray.M_origin, I_front, I_ray.M_direction );
#endif
     I_hit = M2_object->Fv_intersect( I_lambda, I_00, I_10, I_01, I_11, I_ray );
    }

    if( true == I_hit )
     {
      //T_coord I_point; ::math::linear::vector::combine( I_point, I_origin, I_lambda, I_direction );
      //I_point = F2_world2local( I_point );
      //
      //if(      ( ( I_behind < I_lambda ) && ( I_lambda < I_front ) )
      //      && (     ( T_size(I_point[0]) == I_cell[0] ) 
      //            && ( T_size(I_point[1]) == I_cell[1] ) 
      //            && ( T_size(I_point[2]) == I_cell[2] ) ) 
      //  ) //!< Double protection
       {
        I_intersect.M_hit = true;
        I_intersect.M_x = I_cell[0];
        I_intersect.M_y = I_cell[1];
        P_lambda = I_lambda;
        return true;
       }
      //else
       {
#if defined( _DEBUG )
        P_lambda = P_lambda;
#endif
       }
     }

    if( P_lambda < I_front )
     {
      break;
     }
    I_cell[I_axis] += I_move[I_axis];
    if( I_cell[I_axis] == I_fence[I_axis] ) 
     { //!< this is step outside
      break;
     }
    I_plane[I_axis]        += I_step[I_axis];
   }

  I_intersect.M_hit = false;
  return false;
 } //!< end of Fv_intersect

void GC_system::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state  const& P_intersect
 )const
 {
  C_intersect const &I_intersect = P_intersect.F_content<C_intersect>();

  if( false == ::math::geometry::interval::in( F_box(), P_point ) )
   {
    ::math::linear::vector::fill( P_normal, 0 );
    P_normal[2] = 1;
    return;
   }

  auto const& I_lo = F_box().lo();
  auto const& I_hi = F_box().hi();

  T_scalar I_x = F2_world2local( P_point[0], 0 ); 
  T_scalar I_y = F2_world2local( P_point[1], 1 ); 

  int I_cell_x = static_cast<T_size >( I_x );  // I_intersect.M_x;
  int I_cell_y = static_cast<T_size >( I_y );  // I_intersect.M_y;

  T_scalar I_00 = F_generator().Fv_value( I_cell_x + 0, I_cell_y + 0  );
  T_scalar I_10 = F_generator().Fv_value( I_cell_x + 1, I_cell_y + 0  );
  T_scalar I_01 = F_generator().Fv_value( I_cell_x + 0, I_cell_y + 1  );
  T_scalar I_11 = F_generator().Fv_value( I_cell_x + 1, I_cell_y + 1  );

  I_x -= I_cell_x;
  I_y -= I_cell_y;

  M2_object->Fv_normal( P_normal, I_00, I_10, I_01, I_11, I_x, I_y );

  T_coord I_scale;
  I_scale[0] = ( F_generator().F_size()[0] - 1 )/ ( F_box().hi()[0] - F_box().lo()[0]);
  I_scale[1] = ( F_generator().F_size()[1] - 1 )/ ( F_box().hi()[1] - F_box().lo()[1]);
  I_scale[2] = ( F_generator().F_size()[2] - 1 )/ ( F_box().hi()[2] - F_box().lo()[2]);
  ::math::linear::vector::multiply( P_normal, I_scale );
  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_system::T_location GC_system::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  static T_scalar Is_epsilon = 1e-7;

  if( false == ::math::geometry::interval::in( F_box(), P_point ) )
   {
    T_scalar M2_zero = 0;

    T_scalar I_altitude = P_point[2] - M2_zero;
    if( I_altitude < - Is_epsilon ) return En_in;
    if( Is_epsilon < I_altitude )  return En_out;

    return En_out;
   }

  auto const& I_lo = F_box().lo();
  auto const& I_hi = F_box().hi();

  T_scalar I_x = F2_world2local( P_point[0], 0 );
  T_scalar I_y = F2_world2local( P_point[1], 1 );

  int I_cell_x = static_cast<T_size >( I_x );
  int I_cell_y = static_cast<T_size >( I_y );

  T_scalar I_00 = F_generator().Fv_value( I_cell_x + 0, I_cell_y + 0  );
  T_scalar I_10 = F_generator().Fv_value( I_cell_x + 1, I_cell_y + 0  );
  T_scalar I_01 = F_generator().Fv_value( I_cell_x + 0, I_cell_y + 1  );
  T_scalar I_11 = F_generator().Fv_value( I_cell_x + 1, I_cell_y + 1  );

  I_x -= I_cell_x;
  I_y -= I_cell_y;

  T_scalar I_height;
  M2_object->Fv_height( I_height, I_00, I_10, I_01, I_11, I_x, I_y );

  T_scalar I_delta = P_point[2] - I_height;

  if( I_delta < -Is_epsilon ) return En_in;
  if( Is_epsilon < I_delta )  return En_out;

  return En_surface;
 }

/*
GC_system::T_scalar GC_system::Fv_distance( T_coord const& P_point )const
 {
  return 0;
 }
*/

void
GC_system::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  I_intersect.M_x = -1;
  I_intersect.M_y = -1;
  return;
 }

GC_system::T_size
GC_system::Fv_weight( )const
 {
  return sizeof( C_intersect );
 }

bool GC_system::Fv_box( T_box const& P_box )
 {
  F1_box( P_box );
  auto const& I_lo = F_box().lo();
  auto const& I_hi = F_box().hi();
  auto const& I_size = F_generator().F_size();
  M2_step[0] = ( I_hi[0] - I_lo[0] ) / ( I_size[0] - 1 );
  M2_step[1] = ( I_hi[1] - I_lo[1] ) / ( I_size[1] - 1 );
  M2_step[2] = ( I_hi[2] - I_lo[2] );

  return true;
 }

GC_system::T_generator const& GC_system::F_generator(  )const
 {
  return *M2_generator;
 }

bool GC_system::F_generator( T_generator* P_generator )
 {
  M2_generator = P_generator;
  ::math::linear::vector::fill( M2_area[0], 0 );

  M2_area[1][0] = P_generator->F_size()[0] -1;
  M2_area[1][1] = P_generator->F_size()[1] -1;
  M2_area[1][2] = 1;

  auto const& I_lo = F_box().lo();
  auto const& I_hi = F_box().hi();
  auto const& I_size = F_generator().F_size();

  M2_step[0] = ( I_hi[0] - I_lo[0] ) / ( I_size[0] - 1 );
  M2_step[1] = ( I_hi[1] - I_lo[1] ) / ( I_size[1] - 1 );
  M2_step[2] = ( I_hi[2] - I_lo[2] );

  return true;
 }

bool GC_system::F_object( T_object*  P_object )
 {
  M2_object = P_object;
  return true;
 }

GC_system::T_scalar GC_system::F2_world2local( T_scalar const& P_value, T_size const& P_projection )const
 {
  auto const& I_lo = F_box().lo();
  auto const& I_hi = F_box().hi();
  auto const& I_size = F_generator().F_size();

  return ( I_size[P_projection] - 1 ) * (P_value - I_lo[P_projection] )/ ( I_hi[P_projection] - I_lo[P_projection]);
 }

GC_system::T_coord GC_system::F2_world2local( T_coord const& P_value )const
 {
  T_coord Ir_result;
  Ir_result[0] = F2_world2local( P_value[0], 0 );
  Ir_result[1] = F2_world2local( P_value[1], 1 );
  Ir_result[2] = F2_world2local( P_value[2], 2 );
  return Ir_result;
 }

GC_system::T_coord  GC_system::F2_local2world( T_coord const& P_value )const
 {
  auto const& I_lo = F_box().lo();
  auto const& I_hi = F_box().hi();
  T_coord Ir_result;
  Ir_result[0] = P_value[0]*( I_hi[0] - I_lo[0] ) + I_lo[0];
  Ir_result[1] = P_value[1]*( I_hi[1] - I_lo[1] ) + I_lo[1];
  Ir_result[2] = P_value[2]*( I_hi[2] - I_lo[2] ) + I_lo[2];
  return Ir_result;
 }

GC_system::T_flat & GC_system::Fs_flat()
 {
  static T_flat Is_flat;
  return Is_flat;
 }

GC_system::T_quad & GC_system::Fs_quad()
 {
  static T_quad Is_quad;
  return Is_quad;
 }

GC_system::T_vacuum & GC_system::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }

GC_system::T_theone & GC_system::Fs_theone()
{
  static T_theone Is_theone;
  return Is_theone;
}

GC_system::T_table & GC_system::Fs_table()
{
  static T_table Is_table;
  return Is_table;
}
