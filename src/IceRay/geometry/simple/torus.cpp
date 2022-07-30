#define _TORUS_C_

#include <array>
#include <iostream>
#include <iomanip>
#include <algorithm>


#include "./torus.hpp"
#include "math/math.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_torus::C_intersect
 {
  bool M_hit;
  float M_control = 1.123456789f;
 };

GC_torus::T_scalar GC_torus::M2s_worst;

// (x*x+y*y+z*z+1-r*r)^2-4*(x*x+y*y) = 0

GC_torus::GC_torus( )
 {
  F_minor( 0.5 );
  //M2s_worst = 0;
 }

GC_torus::GC_torus( T_scalar const& P_minor )
: GC_torus()
 {
  F_minor( P_minor );
 }

GC_torus::~GC_torus( )
 {
  //std::cout << __FUNCTION__ << " = " << std::setprecision(10)<< M2s_worst << std::endl;
 }

bool GC_torus::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const
 {
  static T_scalar Is_epsilon_quartic      = 1e-10;
  static T_scalar Is_epsilon_lambda       = 1e-5; // 9.018249101e-06
  static T_scalar Is_epsilon_coefficient  = 1e-8;

  C_intersect &I_intersect = P_state.F_content<C_intersect>();


  T_coord I_origin =  P_ray.M_origin;
  T_coord const & I_direction =  P_ray.M_direction;

  T_scalar I_distacne = Fv_distance( I_origin );

  T_scalar I_move = 0; // , I_shift = 0;
  std::array<T_scalar,5> I_general;

  bool I_equation =  ( ( true == I_intersect.M_hit ) || ( ( -Is_epsilon_lambda < I_distacne ) &&  ( I_distacne < Is_epsilon_lambda ) ) );

  if( false == I_equation )
   {
    I_move = - ::math::linear::vector::dot( I_direction, P_ray.M_origin );
    ::math::linear::vector::combine( I_origin, P_ray.M_origin, I_move, I_direction );
   }
  else
   {
    I_intersect.M_hit = I_intersect.M_hit;
   }

  {
   T_scalar a,b,c,al,bl,cl;

   al =     I_direction[0]*I_direction[0] + I_direction[1]* I_direction[1];
   bl = 2*( I_direction[0]*I_origin[0]    + I_direction[1]* I_origin[1] );
   cl =     I_origin[0] * I_origin[0]    + I_origin[1] * I_origin[1];

   a = al +   I_direction[2]*I_direction[2];   //T_scalar(1); // 
   b = bl + 2*I_direction[2]*I_origin[2];     // T_scalar(0); //
   c = cl +   I_origin[2]   *I_origin[2] + M1_pv;

   I_general[0] =  c*c               -  4.0*cl;  // if( I_equation ) T_scalar(0); //
   I_general[1] =  2.0*b*c           -  4.0*bl;
   I_general[2] =      b*b + 2.0*a*c -  4.0*al;
   I_general[3] =  2.0*b*a                    ;  // if( false == I_equation ) T_scalar(0); //
   I_general[4] =  a*a                        ;  // if( false == I_equation ) T_scalar(1); //

   ::math::polynomial::normalize( I_general.data(), I_general.size() );
   ::math::polynomial::optimize( I_general.data(), I_general.size(), Is_epsilon_coefficient );
   ::math::polynomial::monicing( I_general.data(), I_general.size(), Is_epsilon_coefficient );
  }

  auto const & I_coefficient = I_general;
  std::array<T_scalar,4> I_root;
  T_size I_count=0;
  switch( I_equation )
   {
    case( false ):
     {
      // I_shift = ::math::polynomial::solve:::quartic::monic( I_monic.data(), I_general.data(), Is_epsilon_coefficient )

      //std::array<T_scalar,4> I_rootD;
      //int I_countDescartes = ::math::polynomial::quartic::solve::descartes( I_rootD.data(), I_coefficient.data(), Is_epsilon_quartic );
      //std::array<T_scalar,4> I_rootF;
      //int I_countFerrai    = ::math::polynomial::quartic::solve::ferrari(  I_rootF.data(),  I_coefficient.data(), Is_epsilon_quartic );
      //I_count = I_countFerrai;
      //I_root = I_rootF;

      I_count = ::math::polynomial::quartic::solve::descartes(  I_root.data(),  I_coefficient.data(), Is_epsilon_quartic );
    //I_count = ::math::polynomial::quartic::solve::ferrari(  I_root.data(),  I_coefficient.data(), Is_epsilon_quartic );

     }break;
    case( true ):
     {
      I_count = ::math::polynomial::cubic::solve::general( I_root.data(), I_coefficient.data()+1, Is_epsilon_quartic );
     }break;
   }

 // T_coord I_point;
  bool Ir_hit = false;
  switch( I_count )
   {
    case( 4 ) : I_root[3] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[3], P_ray.M_direction ) ) ) );
    case( 3 ) : I_root[2] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[2], P_ray.M_direction ) ) ) );
    case( 2 ) : I_root[1] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[1], P_ray.M_direction ) ) ) );
    case( 1 ) : I_root[0] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[0], P_ray.M_direction ) ) ) );
      break;
    case( 0 ):  return I_intersect.M_hit = false;
   }

  std::sort( I_root.begin(), I_root.begin() + I_count );
  for( T_size I_index=0; I_index < I_count; ++I_index )
   {
    if( ( Is_epsilon_lambda < I_root[I_index] ) && ( I_root[I_index] < P_lambda ) )
     {
      P_lambda = I_root[I_index];
      Ir_hit = true;
     }
   }

  if( true == Ir_hit )
   {
    I_intersect.M_hit = true;
   }
  return Ir_hit;
 }


void GC_torus::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const
 {
  T_scalar pom;

  pom = ::math::linear::vector::length( P_point );
  pom *=  pom;
  pom += M1_pv;

  P_normal[0] =  ( pom - T_scalar( 2 ) ) * P_point[0];
  P_normal[1] =  ( pom - T_scalar( 2 ) ) * P_point[1];
  P_normal[2] =  pom         * P_point[2];

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_torus::T_location GC_torus::Fv_inside(T_coord const& P_point/*, T_state &P_state*/ )const
 {
  static T_scalar Is_epsilon = 1e-6;

  T_scalar llen2  = P_point[0] * P_point[0]  +  P_point[1] * P_point[1];
  T_scalar res1  = llen2 + P_point[2] * P_point[2] + M1_pv;

  T_scalar I_distance = res1 * res1 - T_scalar( 4 ) * llen2;

  if( I_distance  < Is_epsilon )
   {
    return En_in;
   }

  if( Is_epsilon < I_distance )
   {
    return En_out;
   }

  return En_surface;

 }

GC_torus::T_scalar
GC_torus::Fv_distance( T_coord const& P_point )const
 {
  T_scalar llen = sqrt( P_point[0]*P_point[0]+P_point[1]*P_point[1] );
  T_scalar t = llen-T_scalar(1);

  return sqrt( t*t+ P_point[2] * P_point[2] ) - M2_minor;
 }

void
GC_torus::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  I_intersect.M_control = 9.87654321f;
  return;
 }

GC_torus::T_size
GC_torus::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool
GC_torus::F_minor( T_scalar const& P_minor )
 {
  M2_minor = P_minor;
  T_scalar I_major = 1;
  M1_pv = I_major*I_major - M2_minor*M2_minor;
  T_scalar I_tmp = I_major + M2_minor;

  T_coord I_lo, I_hi;
  I_lo[0] = -I_tmp; I_lo[1] = -I_tmp; I_lo[2] = -1;
  I_hi[0] =  I_tmp; I_hi[1] =  I_tmp; I_hi[2] =  1;
  F1_box( T_box{ I_lo, I_hi } );

  return true;
 }
