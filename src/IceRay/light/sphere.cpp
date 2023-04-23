#include "./sphere.hpp"


using namespace GS_DDMRM::S_IceRay::S_light;



GC_sphere::GC_sphere( )
 :M2_radius( 1 )
 {
  M2_sample = 1;
 }

GC_sphere::GC_sphere
 (
   T_spot   const& P_spot
  ,T_scalar const& P_radius
  ,T_size   const& P_sample
 )
 :M2_radius( P_radius )
 ,M2_spot( P_spot )
 {
  //if( is_epsilon( radius ) ) { En_mBAD_INIT; return ; }
  F_sample( P_sample );
 }

GC_sphere::T_size
GC_sphere::Fv_swarm( T_swarm &P_swarm, T_coord const& P_point )const
 {
  T_coord I_z;
  T_spot I_spot = M2_spot;
  ::math::linear::vector::subtraction( I_z, P_point, M2_spot.F_center() );
  ::math::linear::vector::length( I_z, F_radius() );

  T2_affine I_affine;
  ::math::linear::affine::id( I_affine );
  T_coord I_x, I_y;

  auto I_axis = ::math::linear::vector::dominant( I_z ).first;

  switch( I_axis )
   {
    case( 0 ): I_y[0] = 0; I_y[1] = 0; I_y[2] = 1; break;
    case( 1 ): I_y[0] = 1; I_y[1] = 0; I_y[2] = 0; break;
    case( 2 ): I_y[0] = 0; I_y[1] = 1; I_y[2] = 0; break;
   }

  ::math::linear::vector::cross( I_x, I_y, I_z ); ::math::linear::vector::length( I_x, F_radius() );
  ::math::linear::vector::cross( I_y, I_z, I_x ); ::math::linear::vector::length( I_y, F_radius() );

  ::math::linear::affine::system( I_affine, M2_spot.F_center(), I_x, I_y, I_z );

  T_coord I_uvw;
  for( T_size I_index=0; I_index < M2_sample; ++ I_index )
   {
    //T_scalar I_x, I_y; M2_randStandard2D( I_uvw[0], I_uvw[1] );
      M2_randSobol2D.next( I_uvw[0], I_uvw[1] );
    //T_coord2D I_c2D; M2_randVaLND.next( I_c2D );
    I_uvw[2] = 1;

    ::math::linear::vector::length( I_uvw, T_scalar(1) );
    ::math::linear::affine::transform( I_spot.F_center(), I_affine , I_uvw );
    P_swarm.F_push( I_spot );
   }

  return 0;
 }

bool  GC_sphere::F_radius( T_scalar const& P_radius )
 {
  M2_radius = P_radius;
  return true;
 }

bool
GC_sphere::F_sample( T_size const& P_sample )
 {
  M2_sample = P_sample;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  return bool( true );
 }

/*
static int EXTENDED::light1( VECTOR3 point, LSPOT *sp, LIGHT *This )
 {
  USHORT i;
  FLOAT x, y, z, r, t, next;
  VECTOR3 pnt;
  VECTOR3 e_x, e_y, e_z;
  MATRIX3 mat;
  LSPHERE *info = This->info;

  VECTOR3::fsub( e_z, point, info->center ); VECTOR3::len( t, e_z );

  if( info->radius < t )
   {
    //r = acos( info->radius / t ); V 1.0 maping

    r = info->radius / t;  r = sqrt( 1 - r * r );

    if( is_epsilon( e_z.z ) )
     { VECTOR3::load( e_y, 0, 0, 1 ); VECTOR3::fcross( e_x, e_y, e_z ); }
    else
     {

      VECTOR3::load( e_y, 0, 1, 0 );
      VECTOR3::fcross( e_x, e_y, e_z ); VECTOR3::fcross( e_y, e_z, e_x );
     }

    VECTOR3::relen( e_x, info->radius );
    VECTOR3::relen( e_y, info->radius );

    t = info->radius/ t; VECTOR3::scale( e_z, t );
   }
  else
   {
    // obraditi posebno
    r = 1.0;

    y = x = info->radius; if( 1 < (x*x+y*y) ) { y = sqrt (-1e7 + x * x ); }

    VECTOR3::load( e_x, info->radius, 0.0, 0.0 );
    VECTOR3::load( e_y, 0.0, info->radius, 0.0 );
    VECTOR3::load( e_z, 0.0, 0.0, info->radius );
    return 0;
   }

  MATRIX3::load( mat, e_x.x, e_y.x, e_z.x,
                      e_x.y, e_y.y, e_z.y,
                      e_x.z, e_y.z, e_z.z );


  next = info->next;

  for( i=0; i < This->ssampling.test; i++, sp++ )
   {
    sp->flag=This->flag; sp->c0=This->c0; sp->c1=This->c1; sp->c2=This->c2;

    do
     {
      lebesgue2d( &x, &y, next ); lebesgue1d( next );

      x -= 0.5; y -= 0.5;
      t = x * x  +  y * y ;
     }
    while( 0.25 < t );

    x = r * ( x + x ); y = r * ( y + y );

    z = sqrt( 1.0 - x * x - y * y );

    VECTOR3::load( pnt, x, y, z );
    v_faffine( sp->center, info->center, mat, pnt );


    //VECTOR3::scale( pnt, info->radius ); VECTOR3::fadd( sp->center, pnt, info->center );

   }

  info->next = next;
  return This->ssampling.test;
 }
/  *
    // V 0.0
    x = 2.0 * d_frand()-1.0;

    if( ( -1.0 < x ) && ( x < 1.0 ) )
     {
      y = sqrt( 1.0  -  x * x ) *  ( 2.0* d_frand()-1.0);

      z =x * x  +  y * y;
      if( z < 1.0 )
       z = sqrt( 1.0 - z ) *  ( 2.0 *  d_frand()-1.0);
      else
       z = 0.0;
     }
    else
     y = z = 0.0;
   // V 1.0
    x = 2.0 * d_frand()-1.0;
    if( ( -1.0 < x ) && ( x < 1.0 ) )
     {
      y = sqrt( 1.0  -  x * x ) *  ( 2.0* d_frand()-1.0);
      x *= r;     y *= r;
     }
    else
     { y = 0.0; x = r; }

    z = sqrt( 1 - x*x - y*y );


*  /
*/



