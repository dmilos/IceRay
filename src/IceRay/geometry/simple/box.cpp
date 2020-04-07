#include  <limits>
#include  "math/math.hpp"
#include  "./box.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_box::C_intersect
 {
  int M_side;
  GC_box::T_scalar M_min, M_max;
 };

GC_box::GC_box(  )
 :GC_box
   (
     ::math::linear::vector::fill( T_coord{}, -1 )
    ,::math::linear::vector::fill( T_coord{}, +1 )
   )
 {
 }


GC_box::GC_box( T_coord const& P_lo, T_coord const& P_hi )
 : GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base( T_box( P_lo, P_hi ) )
 {
 }

GC_box::GC_box( T_box const& P_box )
 : GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base( P_box )
 {
 }

bool GC_box::F_load( T_box const& P_box )
 {
  this->Fv_box( P_box );
  return true;
 }

bool    GC_box::F_load( T_coord const& P_lo, T_coord const& P_hi )
 {
    F1_box( T_box{  P_lo, P_hi } );
  return true;
 }

bool GC_box::Fv_intersect
 (
   T_scalar         & P_lambda
  ,T_state          & P_state
  ,T_ray       const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  std::tuple<unsigned, T_scalar, unsigned, T_scalar > intersect;

  if( false == ::math::geometry::interval::intersect( intersect, F_box(), {P_ray.M_origin, P_ray.M_direction}, Is_epsilon ) )
   {
    return false;
   }

  if( ( Is_epsilon < std::get<1>( intersect ) ) && ( std::get<1>( intersect ) < P_lambda ) )
   {
    P_lambda = std::get<1>( intersect );
    I_intersect.M_min  = std::get<1>( intersect );
    I_intersect.M_max  = std::get<3>( intersect );
    I_intersect.M_side = std::get<0>( intersect );
    return true;
   }

  if( ( Is_epsilon <  std::get<3>( intersect ) ) && (  std::get<3>( intersect ) < P_lambda ) )
   {
    P_lambda = std::get<3>( intersect );
    I_intersect.M_min = std::get<1>( intersect );
    I_intersect.M_max = std::get<3>( intersect );
    I_intersect.M_side = std::get<2>( intersect );
    return true;
   }

  return false;
 }

/*
bool GC_box::Fv_sint
 (
  T_coord const&   P_dir,
  T_coord const&   P_pos,
  T_scalar        *P_lambda,
  T_state         *P_state
 )const
 {
  C_intersect *I_intersect = dynamic_cast<C_intersect*>(P_state);
  if( NULL == I_intersect ) return false;


  if( 1 == (I_intersect->M_side % 2) )
   {
    if( P_dir[ ( I_intersect->M_side - 1 ) / 2] <  std::numeric_limits<T_scalar>::epsilon() ) return false;
   }
  else
   {
    if( P_dir[ ( I_intersect->M_side - 1 ) / 2] > -std::numeric_limits<T_scalar>::epsilon() ) return false;
   }


  T_size   I_side = 0;
  T_scalar I_inf, I_tinf;


  T_coord I_lo( F_box().F_lo() - P_pos );
  T_coord I_hi( F_box().F_hi() - P_pos );

  I_inf = std::numeric_limits<T_scalar>::max();

  for( T_size I_dim=0; I_dim < T_coord::dimension(); I_dim++ )
   {
    if( std::numeric_limits<T_scalar>::epsilon() < P_dir[ I_dim ] )
     {
      if( std::numeric_limits<T_scalar>::epsilon() < I_hi[ I_dim ] ) continue;

      I_tinf = I_hi[ I_dim ] / P_dir[ I_dim ];
      if( I_tinf < I_inf )
       {
        I_side = 2 * I_dim + 2;
        I_inf = I_tinf;
       }

       continue;
      }

    if( P_dir[ I_dim ] < -std::numeric_limits<T_scalar>::epsilon() )
     {
      if( I_lo[ I_dim ] < -std::numeric_limits<T_scalar>::epsilon() ) continue;
      I_tinf = I_lo[ I_dim ] / P_dir[ I_dim ];
      if( I_tinf < I_inf )
       {
        I_side = 2 * I_dim + 1;
        I_inf = I_tinf;
       }
     }

   }

  I_intersect->M_side = I_side;
  return (I_side==0)?false:true;
 }
*/

void GC_box::Fv_normal
 (
   T_coord      & P_normal
  ,T_coord const& P_point
  ,T_state const& P_state
 )const
 {
  C_intersect const& I_intersect = P_state.F_content<C_intersect const>();

  ::math::linear::vector::fill( P_normal, 0 );

  P_normal[ (I_intersect.M_side-1) / 2 ] = ( ( I_intersect.M_side % 2) ? T_scalar( -1 ) : T_scalar( 1 ) );
 }

GC_box::T_location GC_box::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  if( true == ::math::geometry::interval::in( F_box(),  P_point ) )
   {
    return En_in;
   }
  return En_out;
 }

GC_box::T_scalar   GC_box::Fv_distance( T_coord const& P_pnt )const
 {
  // TODO there is 27 sides, for cube,
  return 0;
 }

void
GC_box::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_side = -1;
  I_intersect.M_min = +1;
  I_intersect.M_max = -1;
  return;
 }

GC_box::T_size
GC_box::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool
GC_box::Fv_box( T_box const& P_box )
 {
  F1_box( P_box );
  return true;
 }

bool               GC_box::Fs_valid( T_state const&P_state )
 {
  C_intersect const &I_intersect = P_state.F_content<C_intersect const>();
  return true;
 }

int               GC_box::Fs_side( T_state const&P_state )
 {
  C_intersect const &I_intersect = P_state.F_content<C_intersect const>();
  return I_intersect.M_side;
 }

GC_box::T_scalar  GC_box::Fs_min(  T_state const& P_state )
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect const>();
  return I_intersect.M_min;
 }

GC_box::T_scalar  GC_box::Fs_max(  T_state const& P_state )
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect const>();
  return I_intersect.M_max;
 }
