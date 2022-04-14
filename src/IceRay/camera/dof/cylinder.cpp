#include   "./cylinder.hpp"
#include "IceRay/utility/random.hpp"
#include "math/function/function.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera::S_dof;

GS_DDMRM::S_IceRay::S_utility::S_table::GC_hexagon GC_cylinder::M2s_hexagon( 20 );


GC_cylinder::GC_cylinder()
 :GC_cylinder( &Fs_child(), 1, 0, 1 )
 {
 }

GC_cylinder::GC_cylinder( T_size const& P_sample, T_scalar const& P_aperture )
  :GC__parent( nullptr, P_sample )
{
  F_aperture( P_aperture );
  F_gauss( 1 );
}

GC_cylinder::GC_cylinder( T__pure *P_camera, T_size const& P_sample, T_scalar const& P_aperture )
  :GC__parent( P_camera, P_sample )
{
  F_aperture( P_aperture );
  F_gauss( 1 );
}

GC_cylinder::GC_cylinder( T__pure *P_camera, T_size const& P_sample, T_scalar const& P_aperture, T_scalar const& P_gauss )
 :GC__parent( P_camera, P_sample )
 {
  F_aperture( P_aperture );
  F_gauss( P_gauss );
 }

GC_cylinder::~GC_cylinder()
 {
 }

GC_cylinder::T_size
GC_cylinder::Fv_beam
 (
   T_beam         & P_beam
  ,T_coord2D const& P_uv
 )const
 {
  T_coord2D I_disc;
  T_affine I_affine;
  F_child().Fv_system( I_affine, P_uv );

  T_coord I_back  =::math::linear::vector::fill( T_coord{}, 0 );
  T_coord I_front =::math::linear::vector::load( T_coord{}, 0,1,0 );

  T_coord I_heading;
  {
   T_coord I_base;
   ::math::linear::matrix::transform( I_base,      I_affine.matrix(), I_back );
   ::math::linear::matrix::transform( I_heading,   I_affine.matrix(), I_front );
   ::math::linear::vector::subtraction( I_heading, I_base );
   ::math::linear::vector::length( I_heading, T_scalar( 1 ) );
  }
  T_scalar I_summae = 0;
  for( T_size I_index =0; I_index < F_size(); I_index++ )
   {
    GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_disc[0], I_disc[1], M2_randSobol2D );
  //GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_disc, M2_randStandard2D );
  //GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_disc, M2_randVaLND );
    I_disc = M2s_hexagon.F_spot()[I_index]; ::math::linear::vector::scale( I_disc, T_scalar(1)/M2s_hexagon.F_radius()[M2_index] );

    T_scalar const& I_x = I_disc[0];
    T_scalar const& I_y = I_disc[1];

    T_coord & I_direction = P_beam[I_index].M_direction;
    T_coord & I_origin    = P_beam[I_index].M_origin;

    I_back[0] = I_x * F_aperture();
    I_back[1] =                  0;
    I_back[2] = I_y * F_aperture();

    I_front[0] =  I_x * F_aperture();
    I_front[1] =                   1;
    I_front[2] =  I_y * F_aperture();

   ::math::linear::affine::transform( I_origin,    I_affine, I_back );
   ::math::linear::affine::transform( I_direction, I_affine, I_front );

    ::math::linear::vector::subtraction( I_direction, I_origin );
    auto I_len = ::math::linear::vector::length( I_direction );

    {
     T_scalar I_intesity = ::math::linear::vector::dot( I_heading, I_direction ) / I_len;
     I_intesity = ( 1 < I_intesity ? 1: I_intesity );
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

void GC_cylinder::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )
 {
  F_child().Fv_system( P_affine, P_uv );
 }

bool GC_cylinder::Fv_size( T_size const& P_size )
{
  T_size I_size  = P_size; 
  if( M2s_hexagon.F_size().size() <= I_size )
   {
    I_size = M2s_hexagon.F_size().size() - 1;
   }
  F1_size() = M2s_hexagon.F_size()[I_size];
  M2_index = I_size;
  return true;
}

bool GC_cylinder::F_aperture
 (
  T_scalar const& P_aperture
 )
 {
  if( P_aperture < T_scalar( 0 ) )return false;

  M2_aperture = P_aperture;

  return true;
 }

bool      GC_cylinder::F_gauss( T_scalar const& P_gauss )
 {
  M2_gauss = P_gauss;
  return true;
 }

