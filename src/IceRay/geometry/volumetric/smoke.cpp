#include <limits>
#include "./smoke.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_smoke::C_intersect
 {
  bool M_hit;
 };

 namespace {

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          GTs_scalar;



 inline GTs_scalar GF_VanDerCorput
  (
    unsigned const& P_index
   ,unsigned const& P_base
  )
  {
   GTs_scalar base_inv= 1.0 / ( ( GTs_scalar ) P_base );
   GTs_scalar r=0;

   int I_index = P_index;

   while ( I_index != 0 )
   {
     r = r + ( ( GTs_scalar ) (I_index % P_base) ) * base_inv;
     base_inv = base_inv / ( ( GTs_scalar ) P_base );
     I_index = I_index / P_base;
   }

   return r;
  }

  GTs_scalar GFs_rand()
   {
    static int Is_counter=0;

    //static int Is_duzina = 4; static int niz[]={ 1,  2,  3,  4 };
    //static int Is_duzina = 4; static int niz[]={ 1,  3,  4,  2 };

  //static int Is_duzina =13; static int niz[]={ 1,  13,   7,   9,   8,   3,   5,   2,  12,   4,   6,  11  };
  //static int Is_duzina =17; static int niz[]={ 1,  15,   3,  10,   2,  12,  11,   7,   9,  17,   5,   6,   8,  13,  14,  16,   4  };
   // LOS!! static int Is_duzina =17; static int niz[]={ 1,   2,  14,  17,  15,   5,   8,   7,   9,   3,  12,  11,  13,  10,   6,  16,   4  };
  //static int Is_duzina =17; static int niz[]={ 1,   2,   3,   4,   8,  10,  11,   5,  13,  16,   6,  12,   9,  14,  17,   7,  15 };
  //static int Is_duzina =17; static int niz[]={ 1,  17,  10,   5,   4,   2,  15,  14,   3,  13,   8,  16,   6,   7,  12,   9,  11 };
   //static int Is_duzina =17; static int niz[]={ 1,   2,   3,  10,   6,  14,   9,   7,   4,   5,  13,  11,   8,  17,  16,  15,  12 };

    //return rand()/((GTs_scalar)RAND_MAX);
    //return 0.2;
    //return (rand()%3)/3.0;
    //return (i++%5)/4.0;
    //return (niz[Is_counter++%Is_duzina]-1)/GTs_scalar(Is_duzina-1.0);
    return (  GF_VanDerCorput(Is_counter++,3)
            - GF_VanDerCorput(Is_counter++,2)/3.0  + 1/3.0
            + GF_VanDerCorput(Is_counter++,5)/5.0
            - GF_VanDerCorput(Is_counter++,7)/7.0  + 1/7.0
            ) /(1+1/3.0+1/5.0+1/7.0);
   }

}


GC_smoke::GC_smoke()
 {
  T_coord I_lo; ::math::linear::vector::fill( I_lo, -1 );
  T_coord I_hi; ::math::linear::vector::fill( I_hi, +1 );
  F1_box( T_box{ I_lo, I_hi } );

  M2_precision = 0.01;
  M2_density = [ ](T_coord const& ){ return 0.25; };
  F_hull( &Fs_vacuum() );
 }

// GC_smoke::GC_smoke
//  (
//    T_hull * P_hull
//  )
//  {
//   //F1_box( T_box{ P_lo, P_hi } );
//   M2_precision = 0.01;
//   M2_density = [ ](T_coord const& ){ return 0.25; };
//   F_hull( P_hull );
//  }

GC_smoke::~GC_smoke( )
 {

 }

void
GC_smoke::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();

  return;
 }

GC_smoke::T_size
GC_smoke::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += F_hull().Fv_weight();

  return Ir_weigh;
 }

bool GC_smoke::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_intersect
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  int I_side_inf, I_side_sup, I_side_tinf, I_side_tsup;
  T_scalar I_lamt_inf, I_lamt_sup;

  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();

  // T_scalar I_bound[2];
  // auto count = F_hull().Fv_pierce( 2, I_bound, I_intersect.F_tail<C_intersect>(), P_ray ) )
  // if( 2 != count )
  //  {
  //   return false;
  //  }

 using namespace ::math::linear::vector;
  T_coord I_lo( F_box().lo() - P_ray.M_origin );
  T_coord I_hi( F_box().hi() - P_ray.M_origin );

  T_scalar I_lam_inf = -std::numeric_limits<T_scalar>::max();
  T_scalar I_lam_sup =  std::numeric_limits<T_scalar>::max();

  for( int I_proj=0; I_proj < (int)T_coord().size() ; I_proj++ )
   {
    if( Is_epsilon < P_ray.M_direction[ I_proj ] )
     {
      I_lamt_inf = I_lo[ I_proj ] / P_ray.M_direction[ I_proj ];
      I_lamt_sup = I_hi[ I_proj ] / P_ray.M_direction[ I_proj ];
      I_side_tinf = 2*I_proj+1;
      I_side_tsup = 2*I_proj+2;
     }
    else
     {
      if( P_ray.M_direction[ I_proj ] < -Is_epsilon )
       {
        I_lamt_inf  = I_hi[ I_proj ] / P_ray.M_direction[ I_proj ];
        I_lamt_sup  = I_lo[ I_proj ] / P_ray.M_direction[ I_proj ];
        I_side_tinf = 2 * I_proj+2;
        I_side_tsup = 2 * I_proj+1;
       }
      else
       {
        if( ( T_scalar( 0 ) < I_lo[ I_proj ] ) || ( I_hi[ I_proj ] < T_scalar( 0 ) ) )
         {
          return false;
         }

        I_lamt_inf = -std::numeric_limits<T_scalar>::max();
        I_lamt_sup =  std::numeric_limits<T_scalar>::max();
      }
    }

    if( I_lamt_sup < - Is_epsilon )
     {
      return false;
     }

    if( I_lam_inf  < I_lamt_inf ) { I_lam_inf = I_lamt_inf; I_side_inf = I_side_tinf; }
    if( I_lamt_sup < I_lam_sup  ) { I_lam_sup = I_lamt_sup; I_side_sup = I_side_tsup; }

    if( I_lam_sup  < I_lam_inf  )
     {
      return false;
     }
   }

  if( ( P_lambda < I_lam_inf ) )
   {
    return false;
   }

  if(  I_lam_inf < Is_epsilon )
   {
    I_lam_inf = 0;
   }

  if( I_lam_sup < Is_epsilon )
   {
    return false;
   }

  if( ( P_lambda < I_lam_sup ) )
   {
    I_lam_sup = P_lambda;
   }

  T_coord I_position;
  I_position = I_lam_inf * P_ray.M_direction + P_ray.M_origin;

  T_coord I_step;
  I_step = M2_precision * P_ray.M_direction;


  T_scalar I_lambda = I_lam_inf;
  T_scalar I_summa = 0.0;
  T_scalar I_value;
  T_scalar I_bound = GFs_rand();

  while( I_lambda < I_lam_sup )
   {
    I_value = 0.25;//M2_density( I_position );

    I_summa += M2_precision * I_value;

    if( I_bound < I_summa )
     {
      /*
      if( not_epsilon( value ) )
       *lambda +=   delta
                  * ( info->next  - exp( -summa ) )
                  / ( exp( -summa ) - exp( -summa +delta* value ) );

       *lambda = ????;
      */

      if( I_lam_sup < I_lambda )
       {
        return false;
       }
      P_lambda = I_lambda;
      return true;
     }

    I_lambda += M2_precision;
    I_position += I_step;
   }

  return false;
 }

void GC_smoke::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state  const& P_intersect
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  T_scalar I_len;

  while( true )
   {
    P_normal[0] = GFs_rand() - 0.5;
    P_normal[1] = GFs_rand() - 0.5;
    P_normal[2] = GFs_rand() - 0.5;
    I_len = ::math::linear::vector::length( P_normal );

    if( ( Is_epsilon < I_len ) && ( I_len < T_scalar( 1 ) ) )
     {
      ::math::linear::vector::scale( P_normal, T_scalar(1)/ I_len );
      return;
     }
   }

 }

GC_smoke::T_location GC_smoke::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  return true == ::math::geometry::interval::in( F_box(), P_point ) ? En_in : En_out;
 }

GC_smoke::T_scalar
GC_smoke::Fv_distance( T_coord const& P_point )const
 {
  return 0;
 }

bool   GC_smoke::F_density( T_function const& P_density )
 {
  M2_density = P_density;
  return bool( true );
 }

bool   GC_smoke::F_precision( T_scalar const& P_precision )
 {
  M2_precision = P_precision;
  return bool( true );
 }

GC_smoke::T_vacuum & GC_smoke::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }


GC_smoke::T_hull const& GC_smoke::F_hull( )const
 {
  return *M2_hull;
 }

void GC_smoke::F_hull( T_hull * P_hull )
 {
  M2_hull = P_hull;
  F1_box( F_hull().F_box() );
 }
