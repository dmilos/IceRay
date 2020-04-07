#include "./hfield.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_hfield;


struct GC_system::C_intersect
 {
  bool M_hit;
  T_size M_x;
  T_size M_y;
 };


GC_system::GC_system()
 :GC_system( &Fs_theone(), &Fs_vacuum() )
 {
 }

GC_system::GC_system( T_generator* P_generator, T_object* P_object )
 :M2_generator(  &Fs_theone() )
 ,M2_object( P_object )
 {
  T_coord I_lo; ::math::linear::vector::fill( I_lo, 0 );
  T_coord I_hi; ::math::linear::vector::fill( I_hi, 1 );
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
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  static T_scalar Is_infinity= 1e+12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;

  auto const& I_lo = F_box().lo();
  auto const& I_hi = F_box().hi();
  auto const& I_size = M2_generator->F_size();

  T_ray I_ray;
  I_ray.M_direction = P_ray.M_direction;
  I_ray.M_direction[0] *= M2_area[1][0]*( I_hi[0] - I_lo[0] );
  I_ray.M_direction[1] *= M2_area[1][1]*( I_hi[1] - I_lo[1] );
  I_ray.M_direction[2] *= M2_area[1][2]*( I_hi[2] - I_lo[2] );
  T_scalar I_length = ::math::linear::vector::length( I_ray.M_direction );

  I_ray.M_origin = P_ray.M_origin;
  I_ray.M_origin [0] -= I_lo[0];
  I_ray.M_origin [1] -= I_lo[1];
  I_ray.M_origin [2] -= I_lo[2];

  I_ray.M_origin [0] *= M2_area[1][0]*( I_hi[0] - I_lo[0] );
  I_ray.M_origin [1] *= M2_area[1][1]*( I_hi[1] - I_lo[1] );
  I_ray.M_origin [2] *= M2_area[1][2]*( I_hi[2] - I_lo[2] );

  auto const& I_origin = I_ray.M_origin;
  auto const& I_direction = I_ray.M_direction;

  std::tuple<unsigned, T_scalar, unsigned, T_scalar > I_interval;
  if( false == ::math::geometry::interval::intersect( I_interval, M2_area, { I_origin, I_direction }, Is_epsilon ) )
   {
    return false;
   }

  T_scalar I_infinum  = std::max<T_scalar>( std::get<1>( I_interval ), Is_epsilon );
  T_scalar I_supremum = std::min<T_scalar>( std::get<3>( I_interval ), P_lambda*I_length );

  T_cell3D I_cell;
  I_cell[2] = 0;

  switch( I_intersect.M_hit )
   {
    default:
     return false;

    case( true ):
     {
      I_cell[0] = I_origin[0]; // I_intersect.M_x
      I_cell[1] = I_origin[1]; // I_intersect.M_y
     }break;

    case( false ):
     {
      for( T_size I_projection=0; I_projection < 2; ++I_projection )
       {
        T_scalar I_value = I_origin[I_projection]  +  I_infinum * I_direction[I_projection];

        I_cell[I_projection] = (int)I_value;

        if( I_cell[I_projection]              <         0 )
         {
          I_cell[I_projection] = 0;
          continue;
         }
        if( I_cell[I_projection] +1 < I_size[I_projection] )
         {
          continue;
         }

         I_cell[I_projection] = I_size[I_projection] -2;
       }
     }break;
   }

  T_coord I_step;
  T_coord I_plane;

  T_cell3D     I_fence;
  T_cell3D     I_move;

  for( T_size I_projection=0; I_projection < 3; ++I_projection )
   {
    if( Is_epsilon < I_ray.M_direction[I_projection] )
     {
      I_plane[I_projection] = I_cell[I_projection] - I_ray.M_origin[I_projection] + 1;
      I_step[I_projection] = +1;
      I_move[I_projection] = +1;
      I_fence[I_projection] = ( 2 != I_projection ? I_size[I_projection] -1 : 1 );
      I_ray.M_origin[I_projection] -= I_plane[I_projection];
      continue;
     }

    if( I_ray.M_direction[I_projection] < -Is_epsilon )
     {
      I_plane[I_projection] = I_cell[I_projection] - I_ray.M_origin[I_projection];
      I_step[I_projection]  = -1;
      I_move[I_projection]  = -1;
      I_fence[I_projection] = -1;
      I_ray.M_origin[I_projection] -= I_plane[I_projection];
      continue;
    }

    I_plane[I_projection] = 0;
    I_step[I_projection]  = 0;
    I_move[I_projection]  = 0;
    I_fence[I_projection] = 0;
    I_ray.M_origin[I_projection] -= I_plane[I_projection];
   }

  T_scalar I_behind = I_infinum;
  while( true )
   {
    T_scalar I_lambda = I_supremum;
    bool I_hit = M2_object->Fv_intersect( I_lambda,
                             M2_generator->Fv_value( I_cell[1] + 0, I_cell[0] + 0), M2_generator->Fv_value( I_cell[1] + 0, I_cell[0] + 1 ),
                             M2_generator->Fv_value( I_cell[1] + 1, I_cell[0] + 0), M2_generator->Fv_value( I_cell[1] + 1, I_cell[0] + 1 ),
                             I_ray
     );

    int I_axis = -1;
    T_scalar I_wall = I_supremum;
    for( T_size I_projection=0; I_projection < 3; ++I_projection )
     {
      // TODO near zero I_direction[I_projection]
      if( I_plane[I_projection]/I_direction[I_projection] < I_wall )
       {
        I_axis = I_projection;
        I_wall = I_plane[I_projection]/I_direction[I_projection];
       }
     }

    if( true == I_hit )
     {
      //if( I_lambda < I_wall ) //!< Double protection
       {
        I_intersect.M_hit = true;
        I_intersect.M_x = I_cell[0];
        I_intersect.M_y = I_cell[1];
        P_lambda = ( I_lambda + I_behind ) / I_length;
        return true;
       }
     }
    if( -1 == I_axis )
     {
      break;
     }

    I_behind += I_wall;
    I_supremum -= I_wall;
    I_cell[I_axis]  += I_move[I_axis];
    if( I_cell[I_axis] == I_fence[I_axis] ) break;
    I_plane[I_axis] += I_step[I_axis];
    I_ray.M_origin[I_axis] -= I_step[I_axis];
   }

  I_intersect.M_hit = false;
  return false;
 }

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

  T_scalar I_x = ( M2_generator->F_size()[0] - 1 )* ( P_point[0] - I_lo[0] )/ ( I_hi[0] - I_lo[0]);
  T_scalar I_y = ( M2_generator->F_size()[0] - 1 )* ( P_point[1] - I_lo[1] )/ ( I_hi[1] - I_lo[1]);

  int I_cell_x = static_cast<T_size >( I_x );  // I_intersect.M_x;
  int I_cell_y = static_cast<T_size >( I_y );  // I_intersect.M_y;

  I_x -= I_cell_x;
  I_y -= I_cell_y;

  T_scalar I_00 = M2_generator->Fv_value( I_cell_y + 0, I_cell_x + 0  );
  T_scalar I_01 = M2_generator->Fv_value( I_cell_y + 0, I_cell_x + 1  );
  T_scalar I_10 = M2_generator->Fv_value( I_cell_y + 1, I_cell_x + 0  );
  T_scalar I_11 = M2_generator->Fv_value( I_cell_y + 1, I_cell_x + 1  );

  M2_object->Fv_normal( P_normal, I_00, I_01, I_10, I_11, I_x, I_y );
 }

GC_system::T_location GC_system::Fv_inside
 (
  T_coord const& P_point
 )const
 {
    static T_scalar Is_epsilon = 1e-6;

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

  T_scalar I_x = ( M2_generator->F_size()[0] - 1 )* ( P_point[0] - I_lo[0] )/ ( I_hi[0] - I_lo[0]);
  T_scalar I_y = ( M2_generator->F_size()[0] - 1 )* ( P_point[1] - I_lo[1] )/ ( I_hi[1] - I_lo[1]);

  int I_cell_x = static_cast<T_size >( I_x );
  int I_cell_y = static_cast<T_size >( I_y );

  I_x -= I_cell_x;
  I_y -= I_cell_y;

  T_scalar I_00 = M2_generator->Fv_value( I_cell_y + 0, I_cell_x + 0  );
  T_scalar I_01 = M2_generator->Fv_value( I_cell_y + 0, I_cell_x + 1  );
  T_scalar I_10 = M2_generator->Fv_value( I_cell_y + 1, I_cell_x + 0  );
  T_scalar I_11 = M2_generator->Fv_value( I_cell_y + 1, I_cell_x + 1  );

  T_scalar I_height;
  M2_object->Fv_height( I_height, I_00, I_01, I_10, I_11, I_x, I_y );

  T_scalar I_altitude = P_point[2] - I_height;

  if( I_altitude < -Is_epsilon ) return En_in;
  if( Is_epsilon < I_altitude )  return En_out;

  return En_out;
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
  I_intersect.M_x = -1; //!< Only debug
  I_intersect.M_y = -1; //!< Only debug
  return;
 }

GC_system::T_size
GC_system::Fv_weight( )const
 {
  return sizeof( C_intersect );
 }


bool GC_system::F_generator( T_generator* P_generator )
 {
  M2_generator = P_generator;
  ::math::linear::vector::fill( M2_area[0], 0 );

  M2_area[1][0] = P_generator->F_size()[0] -1;
  M2_area[1][1] = P_generator->F_size()[1] -1;
  M2_area[1][2] = 1;
  return true;
 }

bool GC_system::F_object( T_object*  P_object )
 {
  M2_object = P_object;
  return true;
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
