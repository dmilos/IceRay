#include <cstring>
#include "./uniform.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_RTSS;



struct GC_uniform::C_intersect
 {
  GC_uniform::T_size M_index;
 };


GC_uniform::GC_uniform( )
:M2_compartment( 0 )
 {
  M2_false = 0;
  M2_true = 1;
  F_dimension( ::math::linear::vector::fill( T_size3D{}, 1 ) );
 }


GC_uniform::GC_uniform( T_size3D const& P_dimension )
:M2_compartment( 0 )
 {
  M2_false = 0;
  M2_true = 1;
  F_dimension( P_dimension );
 }

GC_uniform::~GC_uniform( )
 {
 }

bool      GC_uniform::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const
 {
  static T_scalar Is_epsilon = 1e-8;
  static T_scalar Is_infinity= 1e+12;

  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  T_scalar I_min = 0;
  T_coord const& I_lo = F_box().lo();
  T_coord const& I_hi = F_box().hi();
  T_coord const& I_origin = P_ray.M_origin;
  T_coord const& I_direction = P_ray.M_direction;

  std::tuple<unsigned, T_scalar, unsigned, T_scalar > I_interval;
  if( false == ::math::geometry::interval::intersect( I_interval, F_box(), { I_origin, I_direction }, Is_epsilon ) )
   {
    return false;
   }

  T_scalar I_infinum  = std::max<T_scalar>( std::get<1>( I_interval ), Is_epsilon );
  T_scalar I_supremum = std::min<T_scalar>( std::get<3>( I_interval ), P_lambda   );

  T_position I_position;
  {
   T_coord I_point;
   ::math::linear::vector::combine( I_point, I_origin, I_infinum, I_direction );
   ::math::geometry::interval::confine( I_point , F_box() );

   if( false == F_cell( I_point, I_position ) )
    {
     return false; //!< TODO not possible;
    }
  }

  ++M2_false;
  ++M2_true;

  T_cell3D  I_step;
  T_cell3D  I_fence;
  T_cell3D  I_orientation;

  for( T_size I_projection=0; I_projection < T_coord().size(); ++ I_projection )
   {
    if( I_direction[I_projection] < -Is_epsilon )
     {
      I_step[I_projection] = -1;
      I_fence[ I_projection] = -1;
      I_orientation[I_projection] = 0;
      continue;
     }

    if( Is_epsilon < I_direction[I_projection] )
     {
      I_step[I_projection] = +1;
      I_fence[ I_projection] = M2_dimension[I_projection];
      I_orientation[I_projection] = +1;
      continue;
     }

    I_step[I_projection] = 0;
    I_fence[ I_projection] = -1;

    continue;
   }

  T_scalar I_lambda  = I_supremum;
  T_size   I_candidate = Fs_invalid();

  T_state        I_mainHit;     P_state.F_tail<C_intersect>( I_mainHit );
  T_state        I_state_best;    I_mainHit.F_tail(          I_state_best, M2_compartment);
  T_state        I_state_subject; I_state_best.F_tail(         I_state_subject, M2_compartment  );

  while( true )
   {
    T_list const& I_container = M2_volume[I_position[2]][I_position[1]][I_position[0]];
    for( auto const& I_current: I_container )
     {
      C2_geometry const&I_subject = M2_collection[I_current];

      if( M2_true == I_subject.M_check )
       {
        continue;
       }

      I_subject.M_check = M2_true;

      if( I_current == I_intersect.M_index )
       {
        if( true == I_subject.M_intersect->Fv_intersect( I_lambda, I_mainHit, P_ray ) )
         {
          I_candidate = I_current;
          std::memcpy( I_state_best.F_ptr(), I_mainHit.F_ptr(), I_subject.M_intersectSize );
         }
        continue;
       }

      I_subject.M_intersect->Fv_reset( I_state_subject );
      if( true == I_subject.M_intersect->Fv_intersect( I_lambda, I_state_subject, P_ray ) )
       {
        std::memcpy( I_state_best.F_ptr(), I_state_subject.F_ptr(), I_subject.M_intersectSize );
        I_candidate = I_current;
       }
     }

    T_size   I_axis = -1;
    T_scalar I_wall = P_lambda;
    for( T_size I_projection=0; I_projection < T_coord().size(); ++ I_projection )
     {
      T_scalar I_t = ( ( I_position[I_projection] + I_orientation[I_projection] ) * M2_cubic[I_projection] + I_lo[I_projection] - I_origin[I_projection] );
      if( ( -Is_epsilon < I_direction[I_projection] ) && ( I_direction[I_projection] < Is_epsilon ) )
       {
        continue;
       }

      I_t /= I_direction[I_projection];

      T_scalar I_plane = I_t * I_direction[I_projection] + I_origin[I_projection];

      if( I_t < I_wall )
       {
        I_wall = I_t;
        I_axis = I_projection;
       }
     }

    if( I_lambda < I_wall )
     {
      if( I_candidate == Fs_invalid() )
       {
        goto L_false;
       }

      P_lambda = I_lambda;
      I_intersect.M_index = I_candidate;
      std::memcpy( I_mainHit.F_ptr(), I_state_best.F_ptr(), M2_collection[I_intersect.M_index].M_intersectSize );
      return true;
     }

    if( -1 == I_axis )
     {
      goto L_false;
     }

    I_position[ I_axis ] += I_step[ I_axis ];
    if( I_fence[ I_axis ] == I_position[ I_axis ] )
     {
      goto L_false;
     }
   }

  L_false:
   I_intersect.M_index = Fs_invalid();

  return false;
 }

void    GC_uniform::Fv_reset( T_state & P_state )const
 {
  C_intersect &I_state = P_state.F_content<C_intersect>();
  I_state.M_index = Fs_invalid();
 }

GC_uniform::T_size
GC_uniform::Fv_weight( )const
 {
  T_size Ir_size = 0;

  Ir_size += sizeof( C_intersect );
  Ir_size += M2_compartment; // hit
  Ir_size += M2_compartment; // candidate
  Ir_size += M2_compartment; // test subject

  return Ir_size;
}

GC_uniform::T_size const& GC_uniform::Fv_id( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  if( I_intersect.M_index == Fs_invalid() )
   {
    return Fs_invalid();
   }
  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );

  return M2_collection[I_intersect.M_index].M__base->Fv_id( I_mainHit );
 }

GC_uniform::T_size
GC_uniform::Fv_push( T__base * P_object )
 {
  C2_geometry I_geometry;

   I_geometry.M__base = P_object;
   I_geometry.M_intersect      = dynamic_cast<T_intersect*>(I_geometry.M__base); if( nullptr == I_geometry.M_intersect) I_geometry.M_intersect = & Fs_vacuum();
   I_geometry.M_intersectSize  = I_geometry.M__base->Fv_weight();
   I_geometry.M_check = 0;

  M2_collection.push_back( I_geometry );

  M2_compartment = std::max( M2_compartment, I_geometry.M__base->Fv_weight() );

  if( 1 == M2_collection.size() )
   {
    Fv_box( P_object->F_box() );
   }
  else
   {
    T_box I_box = F_box();
    // TODO ::math::geometry::interval::inflate( I_box, I_scale, I_box );
    ::math::geometry::interval::extend( I_box, P_object->F_box() );
    Fv_box( I_box );
   }

  return M2_collection.size()-1;
 }

void GC_uniform::Fv_erase( T__base  * P_object )
 {
  // TODO
 }

void GC_uniform::Fv_clear()
 {
  // TODO
  M2_collection.clear();
  M2_volume.clear();
 }

void   GC_uniform::Fv_optimize()
 {
  M2_volume.clear();

  M2_volume.resize( M2_dimension[2] );
  for( auto & I_area: M2_volume )
   {
    I_area.resize( M2_dimension[1] );
     for( auto & I_row : I_area )
      {
       I_row.resize( M2_dimension[0] );
       for( auto & I_container : I_row )
        {
         // Nothing
         //I_container.clear( );
        }
      }
   }

   T_size I_index = 0;
   for( auto & I_item : M2_collection )
    {
     T_size3D I_lo; F_cell( I_item.M__base->F_box().lo(), I_lo );
     T_size3D I_hi; F_cell( I_item.M__base->F_box().hi(), I_hi );
     T_size3D I_cell;
     for( I_cell[2]=I_lo[2]; I_cell[2] <= I_hi[2]; ++I_cell[2] )
      for( I_cell[1]=I_lo[1]; I_cell[1] <= I_hi[1]; ++I_cell[1] )
       for( I_cell[0]=I_lo[0]; I_cell[0] <= I_hi[0]; ++I_cell[0] )
         {
          M2_volume[ I_cell[2] ][I_cell[1]][I_cell[0]].push_back( I_index );
         }
     ++I_index;
    }

   for( T_size I_projection=0; I_projection < T_coord().size(); ++ I_projection )
    {
     M2_cubic[I_projection] =  ( F_box().hi()[I_projection] -  F_box().lo()[I_projection] ) / M2_dimension[I_projection];
    }

 }

GC_uniform::T_list const&
GC_uniform::Fv_owners( T_coord const& P_point )const
 {
  static T_list Ir_empty;

  T_position I_cell;

  if( false == ::math::geometry::interval::in( F_box(), P_point ) )
   {
    return Ir_empty;
   }

  if( false == F_cell( P_point, I_cell ) )
   {
    return Ir_empty;
   }

  return M2_volume[I_cell[2]][I_cell[1]][I_cell[0]];
 }

void  GC_uniform::Fv_prepare( T_coord const& P_point, T_state & P_state )const
 {
  Fv_reset( P_state );
 }

GC_uniform::T_size const&
GC_uniform::Fv_quantity()const
 {
  return M2_cdwewewews = M2_collection.size();
 }

GC_uniform::T__base*
GC_uniform::Fv_base( T_size const& P_index )const
 {
  if( P_index < M2_collection.size())
   {
    return M2_collection[P_index].M__base;
   }
  return &Fs_vacuum();
 }

bool GC_uniform::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();

  P_fragment.M__base = nullptr;

  if( Fs_invalid() == I_head.M_index )
   {
    P_fragment.M_index = I_head.M_index;
    return false;
   }

  ++P_fragment.M_depth;
  P_fragment.M_index = I_head.M_index;
  P_fragment.M__base = M2_collection[P_fragment.M_index].M__base;
  P_state.F_tail<C_intersect>( P_fragment.M_state );

  return true;
 }

GC_uniform::T_size3D const&
GC_uniform::F_dimension()const
 {
  return M2_dimension;
 }

bool
GC_uniform::F_dimension( T_size3D const& P_dimension )
 {
  M2_dimension = P_dimension;
  Fv_optimize();
  return true;
 }

bool  GC_uniform::F_cell( T_coord const & P_point, T_size3D & P_cell )const
 {
  T_scalar I_value;

  T_coord const& I_lo = F_box().lo();
  T_coord const& I_hi = F_box().hi();

  for( T_size I_index =0; I_index < T_coord().size(); ++I_index )
   {
    if( P_point[I_index] < I_lo[I_index] )
     {
      return false;
     }
    if( I_hi[I_index] < P_point[I_index] )
     {
      return false;
     }

    I_value = (P_point[I_index] - I_lo[I_index] ) /( I_hi[I_index] - I_lo[I_index] );

    if( I_value < T_scalar( 0 ) )
     {
      P_cell[I_index] = 0;
      continue;
     }

    P_cell[I_index] = T_size( F_dimension()[I_index] * I_value );

    if( P_cell[I_index] < F_dimension()[I_index] )
     {
      continue;
     }

    P_cell[I_index] = F_dimension()[I_index] -1;
   }

  return true;
 }
