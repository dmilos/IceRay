#include   "./focus.hpp"
#include "math/function/function.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera::S_dof;


#define D_min(a,b) ((a)<(b)?(a):(b))
#define D_max(a,b) ((a)>(b)?(a):(b))

GC_focus::GC_focus ()
 {
  M2_focus    = T_interval1D{ 1, 1000 };
  M2_aperture = T_interval1D{ 0, 1 };
  M2_gauss    = 1;
 }

GC_focus::GC_focus( T_size const& P_sample, T_interval1D const& P_aperture, T_interval1D const& P_focus, T_scalar const& P_gauss )
: GC__parent( nullptr, P_sample)
 {
  F_aperture( P_aperture );
  F_gauss( P_gauss );
  F_focus( P_focus );
 }

GC_focus::GC_focus( T__pure *P_camera, T_size const& P_sample, T_interval1D const& P_aperture, T_interval1D const& P_focus )
: GC__parent( P_camera, P_sample)
 {
  F_aperture( P_aperture );
  F_gauss( 1 );
  F_focus( P_focus );
 }

GC_focus::GC_focus( T__pure *P_camera, T_size const& P_sample, T_interval1D const& P_aperture, T_interval1D const& P_focus, T_scalar const& P_gauss )
: GC__parent( P_camera, P_sample)
 {
  F_aperture( P_aperture );
  F_gauss( P_gauss );
  F_focus( P_focus );
 }


bool
GC_focus ::F_aperture
 (
  T_interval1D const& P_aperture
 )
 {
  //! @todo Ceheck/fix
  M2_aperture = P_aperture;
  return true;
 }


bool

GC_focus::F_focus
 (
   T_interval1D const&  P_focus
 )
 {
  //! @todo Ceheck/fix
  /*
  T_scalar I_near(P_near), I_far(P_far);

  if( I_near < VECTOR1<T_scalar>::Fs_epsilon() ) I_near = T_scalar( 1 );
  if( I_far  < VECTOR1<T_scalar>::Fs_epsilon() ) I_far  = T_scalar( 1 );

  M2_focus = D_min( I_near, I_far );
  M2_focus = D_max( I_near, I_far );
  */
  M2_focus = P_focus;
  return true;
 }


GC_focus::T_size
GC_focus::Fv_beam
 (
  T_beam         & P_beam
 ,T_coord2D const& P_uv
 )const
 {
  T_affine I_affine;
  F_child().Fv_system( I_affine, P_uv );

  T_coord I_back  =::math::linear::vector::fill( T_coord{}, 0 );
  T_coord I_front =::math::linear::vector::load( T_coord{}, 0, 1, 0 );

  T_coord I_heading;
  {
   T_coord I_base;
   ::math::linear::matrix::transform( I_base,      I_affine.matrix(), I_back );
   ::math::linear::matrix::transform( I_heading,   I_affine.matrix(), I_front );
   ::math::linear::vector::subtraction( I_heading, I_base );
  }
  T_scalar I_main = ::math::linear::vector::length( I_heading, T_scalar( 1 ) );

  T_scalar I_summae=0;
  for( T_size I_index =0; I_index < F_size(); I_index++ )
   {
    T_scalar I_x0, I_y0;
    GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_x0, I_y0, M2_randStandard2D );
  //GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_x0, I_y0, M2_randSobol2D  );

    T_scalar I_x1, I_y1;
    GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_x1, I_y1, M2_randStandard2D );
  //GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_x1, I_y1, M2_randSobol2D    );

  //T_scalar const I_focus = M2_randSobol1D.next();
  //T_scalar const I_focus = M2_randVDC.next();
  //T_scalar const I_focus = M2_randGold1D.next();
    T_scalar const I_focus = M2_randStandard1D();

    T_coord & I_direction = P_beam[I_index].M_direction;
    T_coord & I_origin    = P_beam[I_index].M_origin;

    I_back[0] =  I_x0 * F_aperture().lo();
    I_back[1] =  0;
    I_back[2] =  I_y0 * F_aperture().lo();

    I_front[0] = ( I_x1 * F_aperture().hi() );
    I_front[1] = ::math::function::convex( I_focus, F_focus().lo(), F_focus().hi() );
    I_front[2] = ( I_y1 * F_aperture().hi() );

    ::math::linear::matrix::transform( I_origin,    I_affine.matrix(), I_back );
    ::math::linear::matrix::transform( I_direction, I_affine.matrix(), I_front );
    ::math::linear::vector::subtraction( I_direction, I_origin );

    ::math::linear::vector::length( I_direction, T_scalar( 1 ) );

    {
     T_scalar I_intesity = ::math::linear::vector::dot( I_heading, I_direction );
     I_intesity = ( 1 < I_intesity ? 1 : I_intesity );
     I_intesity = ::math::function::pdf<T_scalar>( acos( I_intesity ), F_gauss() );
     P_beam[I_index].M_intesity = T_gray{ {I_intesity} };
     I_summae += I_intesity;
    }
   }

  I_summae /= F_size();

  for( T_size I_index =0; I_index < F_size(); I_index++ )
   {
    P_beam[I_index].M_intesity /= I_summae;
   }

  return F_size();
 }

bool             GC_focus::F_gauss( T_scalar const& P_gauss )
 {
  M2_gauss = P_gauss;
  return true;
 }

