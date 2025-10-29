#include <limits>
#include "./mist.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_volumetric;



struct GC_mist::C_intersect
 {
  bool M_hit;
 };

 namespace {

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          GTs_scalar;


  GTs_scalar GFs_randX()
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
    return (  ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,3)
            - ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,2)/3.0  + 1/3.0
            + ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,5)/5.0
            - ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,7)/7.0  + 1/7.0
            ) /(1+1/3.0+1/5.0+1/7.0);
   }

}

GC_mist::GC_mist()
: GC_mist( 0.25, 0.01 )
 {
 }

GC_mist::GC_mist
 (
  T_scalar const& P_density, T_scalar const& P_precision
 )
 :  M2_density( P_density )
 ,  M2_precision( P_precision )
 {
  F_hull( &Fs_vacuum() );
 }

GC_mist::~GC_mist( )
 {
 }

void
GC_mist::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  T_state      I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  M2_hull.M__base->Fv_reset( I_tail );
  return;
 }

GC_mist::T_size
GC_mist::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += F_hull().Fv_weight();

  return Ir_weigh;
 }

bool GC_mist::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_lam_inf=0, I_lam_sup=P_lambda;

  // T_scalar I_bound[2];
  // auto count = M2_hull.M_pierce( 2, I_bound, I_intersect.F_tail<C_intersect>(), P_ray ) )
  // if( 2 != count )
  //  {
  //   return false;
  //  }


  C_intersect &I_head  = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>(I_tail);

  bool I_hit1 = M2_hull.M_intersect->Fv_intersect( I_lam_sup, I_tail, P_ray );

  auto I_location = M2_hull.M_inside->Fv_inside( P_ray.M_origin /*, P_intersect */ );

  switch( I_location )
   {
    case( T_location::En_in  ):  break;
    case( T_location::En_out ): 
     {
      if( false == I_hit1 )
       {
        return false;
       }

      I_lam_inf = I_lam_sup;
      I_lam_sup = P_lambda - I_lam_inf;
      auto I_ray = P_ray;
      ::math::linear::vector::combine( I_ray.M_origin, P_ray.M_origin, I_lam_inf, P_ray.M_direction );
      bool I_hit2 = M2_hull.M_intersect->Fv_intersect( I_lam_sup, I_tail, I_ray );
      break;
     }
    default: return false;
   }

  T_coord I_position = P_ray.M_origin;

  T_coord I_step;
  ::math::linear::vector::scale( I_step, M2_precision, P_ray.M_direction );

  T_scalar I_lambda = I_lam_inf;
  T_scalar I_summa = 0.0;
  T_scalar I_value;
  T_scalar I_bound = GFs_randX();

  while( I_lambda < I_lam_sup )
   {
    I_value =  M2_density;

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
    ::math::linear::vector::addition( I_position, I_step );
   }

  return false;
 }

void GC_mist::Fv_normal
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
    P_normal[0] = GFs_randX() - 0.5;
    P_normal[1] = GFs_randX() - 0.5;
    P_normal[2] = GFs_randX() - 0.5;
    I_len = ::math::linear::vector::length( P_normal );

    if( ( Is_epsilon < I_len ) && ( I_len < T_scalar( 1 ) ) )
     {
      ::math::linear::vector::scale( P_normal, T_scalar(1)/ I_len );
      return;
     }
   }

 }

GC_mist::T_location GC_mist::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  return  M2_hull.M_inside->Fv_inside( P_point /*, P_intersect */ );
 }

GC_mist::T_scalar
GC_mist::Fv_distance( T_coord const& P_point )const
 {
  return 0;
 }

bool   GC_mist::F_density( T_scalar const& P_density )
 {
  M2_density = P_density;
  return bool( true );
 }

bool   GC_mist::F_precision( T_scalar const& P_precision )
 {
  M2_precision = P_precision;
  return bool( true );
 }

GC_mist::T_vacuum & GC_mist::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }

GC_mist::T__base const& GC_mist::F_hull( )const
 {
  return *M2_hull.M__base;
 }

bool GC_mist::F_hull( T__base * P_hull )
 {
  auto I_old = M2_hull;
  if( nullptr == P_hull )
   {
    P_hull = &Fs_vacuum();
   }

  M2_hull.M__base     = P_hull ;
  M2_hull.M_intersect = dynamic_cast< T_intersect*>( P_hull );
  M2_hull.M_inside    = dynamic_cast< T_inside*>( P_hull );

  if( ( nullptr == M2_hull.M_intersect ) || ( nullptr == M2_hull.M_inside ) )
   {
    M2_hull = I_old;
    return false;
   }

  F1_box( F_hull().F_box() );
  return true;
 }
