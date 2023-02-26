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
GC_torus::T_size   GC_torus::M2s_descartes;
GC_torus::T_size   GC_torus::M2s_ferrari;
GC_torus::T_size   GC_torus::M2s_shmakov;
GC_torus::T_scalar GC_torus::M2s_worstShmakov;
GC_torus::T_scalar GC_torus::M2s_worstDescartes;
GC_torus::T_scalar GC_torus::M2s_worstFerrari;



// (x*x+y*y+z*z+1-r*r)^2-4*(x*x+y*y) = 0

GC_torus::GC_torus( )
 {
  F_minor( 0.38196601125010515179541316563436 );
  //M2s_worst = 0;
  M2s_descartes = 0;
  M2s_ferrari   = 0;
  M2s_shmakov   = 0;
  M2s_worstShmakov   = 0;
  M2s_worstDescartes = 0;
  M2s_worstFerrari   = 0;
 }

GC_torus::GC_torus( T_scalar const& P_minor )
: GC_torus()
 {
  F_minor( P_minor );
 }

GC_torus::~GC_torus( )
 {
  //std::cout << __FUNCTION__ <<" - "<< "worst    :" << " = " << std::setprecision(10)<< M2s_worst     << std::endl;
  //std::cout << __FUNCTION__ <<" - "<< "C descartes:" << " = " << std::setprecision(10)<< M2s_descartes << std::endl;
  //std::cout << __FUNCTION__ <<" - "<< "C ferrari  :" << " = " << std::setprecision(10)<< M2s_ferrari   << std::endl;
  //std::cout << __FUNCTION__ <<" - "<< "C shmakov  :" << " = " << std::setprecision(10)<< M2s_shmakov   << std::endl;
  //std::cout << __FUNCTION__ <<" - "<< "W descartes:" << " = " << std::setprecision(10)<< M2s_worstShmakov   << std::endl;
  //std::cout << __FUNCTION__ <<" - "<< "W ferrari  :" << " = " << std::setprecision(10)<< M2s_worstDescartes << std::endl;
  //std::cout << __FUNCTION__ <<" - "<< "W shmakov  :" << " = " << std::setprecision(10)<< M2s_worstFerrari   << std::endl;
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
  bool     I_surface = ( ( -Is_epsilon_lambda < I_distacne ) &&  ( I_distacne < Is_epsilon_lambda ) );

  T_scalar I_move = 0; // , I_shift = 0;
  std::array<T_scalar,5> I_general;

  bool I_equation =  ( ( true == I_intersect.M_hit ) || ( true == I_surface ) );

  if( false == I_equation )
   {
    I_move = - ::math::linear::vector::dot( I_direction, P_ray.M_origin );
    ::math::linear::vector::combine( I_origin, P_ray.M_origin, I_move, I_direction );
   }
  else
   {
    I_intersect.M_hit = I_intersect.M_hit;
    // TODO What if I_move = - ::math::linear::vector::dot( I_direction, P_ray.M_origin );
    // TODO What if ::math::linear::vector::combine( I_origin, P_ray.M_origin, I_move, I_direction );
   }

  {
   T_scalar a,b,c,al,bl,cl;

   al =     I_direction[0]*I_direction[0] + I_direction[1]* I_direction[1];
   bl = 2*( I_direction[0]*I_origin[0]    + I_direction[1]* I_origin[1] );
   cl =     I_origin[0] * I_origin[0]    + I_origin[1] * I_origin[1];

   a = al +   I_direction[2]*I_direction[2];   //T_scalar(1); //
   b = bl + 2*I_direction[2]*I_origin[2];     // T_scalar(0); //
   c = cl +   I_origin[2]   *I_origin[2] + M1_pv;

   I_general[0] =  c*c               -  4.0*cl;  // if( true == I_equation ) T_scalar(0); //
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
      //I_shift = ::math::polynomial::solve:::quartic::monic( I_monic.data(), I_general.data(), Is_epsilon_coefficient )
      /*
      std::array<T_scalar,4> I_rootS;
      int I_countShmakov   = ::math::polynomial::quartic::solve::shmakov(   I_rootS.data(), I_coefficient.data(), Is_epsilon_quartic );
      T_scalar I_qualityShmakov = 0;
      for( int I_index=0; I_index<I_countShmakov; ++I_index ) I_qualityShmakov = std::max( fabs( math::polynomial::evaluate( I_rootS[I_index], I_coefficient.data(), 4 ) ), I_qualityShmakov );
      std::array<T_scalar,4> I_rootD;
      int I_countDescartes = ::math::polynomial::quartic::solve::descartes( I_rootD.data(), I_coefficient.data(), Is_epsilon_quartic );
      T_scalar I_qualityDescartes = 0;
      for( int I_index=0; I_index<I_countDescartes; ++I_index ) I_qualityDescartes = std::max( fabs( math::polynomial::evaluate( I_rootD[I_index], I_coefficient.data(), 4 ) ), I_qualityDescartes );
      std::array<T_scalar,4> I_rootF;
      int I_countFerrai    = ::math::polynomial::quartic::solve::ferrari(   I_rootF.data(), I_coefficient.data(), Is_epsilon_quartic );
      T_scalar I_qualityFerrai = 0;
      for( int I_index=0; I_index<I_countFerrai; ++I_index ) I_qualityFerrai = std::max( fabs( math::polynomial::evaluate( I_rootF[I_index], I_coefficient.data(), 4 ) ), I_qualityFerrai );

      if( 0 != I_countShmakov   ) 
       {
        M2s_worstShmakov = std::max( I_qualityFerrai, M2s_worstShmakov );
        if( ( I_qualityShmakov   < I_qualityDescartes ) &&  ( I_qualityShmakov   < I_qualityFerrai    ) ) ++M2s_shmakov;
       }
      if( 1 < I_qualityShmakov )
       {
        I_qualityShmakov = I_qualityShmakov;
       }
      if( 0 != I_countDescartes ) 
       {
        M2s_worstDescartes = std::max( I_qualityFerrai, M2s_worstDescartes );
        if( ( I_qualityDescartes < I_qualityShmakov   ) &&  ( I_qualityDescartes < I_qualityFerrai    ) ) ++M2s_descartes;
       }
      if( 1 < I_qualityDescartes )
       {
        I_qualityDescartes = I_qualityDescartes;
       }
      if( 0 != I_countFerrai    )
       {
        M2s_worstFerrari = std::max( I_qualityFerrai, M2s_worstFerrari );
        if( ( I_qualityFerrai    < I_qualityShmakov   ) &&  ( I_qualityFerrai    < I_qualityDescartes ) ) ++M2s_ferrari;
       }
      if( 1 < I_qualityFerrai )
       {
        I_qualityFerrai = I_qualityFerrai;
       }

      if( I_countShmakov != I_countFerrai )
       {
        I_countShmakov = I_countShmakov;
       }
      if( I_countShmakov != I_countDescartes )
       {
        I_countShmakov = I_countShmakov;
       }
      if( I_countDescartes != I_countFerrai )
       {
        I_countShmakov = I_countShmakov;
       }
       */
      I_count = ::math::polynomial::quartic::solve::descartes(  I_root.data(),  I_coefficient.data(), Is_epsilon_quartic );

     }break;
    case( true ):
     {
      I_count = ::math::polynomial::cubic::solve::general( I_root.data(), I_coefficient.data()+1, Is_epsilon_quartic );
     }break;
   }

 // T_coord I_point;
  switch( I_count )
   {
    case( 4 ) : I_root[3] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[3], P_ray.M_direction ) ) ) );
    case( 3 ) : I_root[2] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[2], P_ray.M_direction ) ) ) );
    case( 2 ) : I_root[1] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[1], P_ray.M_direction ) ) ) );
    case( 1 ) : I_root[0] += I_move;  // M2s_worst = std::max( M2s_worst, fabs( Fv_distance( ::math::linear::vector::combine( I_point, P_ray.M_origin, I_root[0], P_ray.M_direction ) ) ) );
      break;
    case( 0 ):  return I_intersect.M_hit = false;
   }

  bool Ir_hit = false;
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
