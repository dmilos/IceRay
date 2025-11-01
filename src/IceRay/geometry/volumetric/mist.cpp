#include <limits>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include "./mist.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_volumetric;



struct GC_mist::C_intersect
 {
  bool M_hit;
 };

 namespace {

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::GT_size          GTs_size;

bool  GI_init = false;
GS_DDMRM::S_IceRay::S_type::GT_size  GI_seed = 0;
GS_DDMRM::S_IceRay::S_type::GT_size  GI_position = 0;

//GTs_size  GI_size = 8; int GIs_niz[]={ 0,  1,   2, 3,   4,  6, 7  };
GTs_size  GI_size = 18; int GIs_niz[] = { 0, 1,   2,   3,  4,   5,  6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  16,  17 };

//   7 - {  0,   7,   3,   4,   1,   6,   5, }
//   8 - {  0,   7,   5,   6,   4,   8,   1,   3, };   //!< 18.55045244107744
//   9 - {  0,   4,   8,   3,   7,   2,   5,   1,   6, };   //!< 15.937413194444444
//   9 - {  0,   2,   4,   7,   8,   5,   6,   3,   1, }; 
//   9 - {  0,   1,   2,   4,   3,   5,   8,   9,   6,  10,   7, };
//  11 - {  0,   1,   2,   5,   9,   6,  10,   8,   3,   7,   4, }; 

std::vector<GTs_size>  GIs_model = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

// 19.221801346801346
//std::vector<GTs_size>  GIs_model = { 43,  20,   6,  37,   3,  21,  31,  24,  34,   4,  27,  19,  25,  11,   8,  38,   0,  41,  32,  22,  16,  33,   7,  26,  39,  14,  40,   5,  35,  17,  23,  36,   2,  12,  13,  10,   1,  15,  18,  29,   9,  30,  28,  42, }; 

std::vector<GTs_size>  GIs_dynamic = GIs_model;

  GTs_scalar GFs_randX()
   {
    return rand()/((GTs_scalar)RAND_MAX);
    return (GIs_dynamic[GI_position++% GI_size])/GTs_scalar( GI_size -1.0);

    static int Is_counter=0;
    //return (GIs_niz[Is_counter++% GI_size])/GTs_scalar( GI_size -1.0);

    //GI_size = 4; static int niz[]={ 1,  2,  3,  4 };
    //GI_size = 4; static int niz[]={ 1,  3,  4,  2 };

    //GI_size =13; static int niz[]={ 1,  13,   7,   9,   8,   3,   5,   2,  12,   4,   6,  11  };
    //GI_size =17; static int niz[]={ 1,  15,   3,  10,   2,  12,  11,   7,   9,  17,   5,   6,   8,  13,  14,  16,   4  };
    // LOS!! GI_size =17; static int niz[]={ 1,   2,  14,  17,  15,   5,   8,   7,   9,   3,  12,  11,  13,  10,   6,  16,   4  };
    //GI_size =17; static int niz[]={ 1,   2,   3,   4,   8,  10,  11,   5,  13,  16,   6,  12,   9,  14,  17,   7,  15 };
    //GI_size =17; static int niz[]={ 1,  17,  10,   5,   4,   2,  15,  14,   3,  13,   8,  16,   6,   7,  12,   9,  11 };
    //GI_size =17; static int niz[]={ 1,   2,   3,  10,   6,  14,   9,   7,   4,   5,  13,  11,   8,  17,  16,  15,  12 };
    //return (niz[Is_counter++%Is_duzina]-1)/GTs_scalar(Is_duzina-1.0);

    //return 0.2;
    //return (rand()%2)/2.0;
    //return (rand()%2)/2.0+::math::random::VanDerCorput<GTs_scalar>(Is_counter++,2);
    //return+::math::random::VanDerCorput<GTs_scalar>(Is_counter++,3);
    //return ;
    //return (i++%5)/4.0;
    //return (
    //        - ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,2)/3.0  + 1/3.0
    //        + ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,3)
    //        + ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,5)/5.0
    //        - ::math::random::VanDerCorput<GTs_scalar>(Is_counter++,7)/7.0  + 1/7.0
    //        ) /(1+1/3.0+1/5.0+1/7.0);
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
 :M2_seed( 0 )
 ,M2_density( P_density )
 ,M2_precision( P_precision )
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

  T_scalar I_begin= P_lambda, I_end=P_lambda;

  // T_scalar I_bound[2];
  // auto count = M2_hull.M_pierce( 2, I_bound, I_intersect.F_tail<C_intersect>(), P_ray ) )
  // switch( count )
  //  {
  //   case( 0 ) :return false;
  //   case( 1 ): I_begin= I_bound[0], I_end=P_lambda;   break;
  //   case( 2 ): I_begin= I_bound[0], I_end=I_bound[1]; break;
  //   return false;
  //  }

  C_intersect &I_head  = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>(I_tail);

  bool I_hitB = M2_hull.M_intersect->Fv_intersect( I_begin, I_tail, P_ray );

  auto I_location = M2_hull.M_inside->Fv_inside( P_ray.M_origin /*, P_intersect */ );

  switch( I_location )
   {
    case( T_location::En_in  ):
     {
      I_end = I_begin;
      I_begin = 0;
     }break;
    case( T_location::En_out ): 
     {
      if( false == I_hitB )
       {
        return false;
       }

      auto I_ray = P_ray;
      ::math::linear::vector::combine( I_ray.M_origin, P_ray.M_origin, I_begin, P_ray.M_direction );
      I_end -= I_begin;
      bool I_hitE = M2_hull.M_intersect->Fv_intersect( I_end, I_tail, I_ray );
      switch( I_hitE )
       {
        case( false ): I_end  = P_lambda; break;
        case( true  ): I_end += I_begin;  break;
       }
     }break;
    default: return false;
   }
  T_scalar I_bound = GFs_randX();
           //I_bound = 0.5;
/*
  T_scalar I_steps = (I_end - I_begin) / M2_precision;
  T_scalar I_total = I_steps * M2_precision * M2_density;
  if( I_bound < I_total )
   {
    I_steps = I_bound /( M2_precision * M2_density );
    P_lambda = I_begin + I_steps * M2_precision;
    return true;
   }
  return false;
*/
  T_scalar I_precision = 0.01;
  T_scalar I_lambda = I_begin;
  T_scalar I_summa = 0.0;
  while( I_lambda < I_end )
   {
    I_summa  += I_precision * M2_density;
    I_lambda += I_precision;

    if( I_bound < I_summa )
     {
      //if( not_epsilon( value ) )
      // P_lambda +=   delta
      //            * ( info->next  - exp( -summa ) )
      //            / ( exp( -summa ) - exp( -summa +delta* value ) );
      //
      // P_lambda = ????;

      P_lambda = I_lambda;
      return true;
     }
   }

  return false;

/**/
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

bool   GC_mist::F_seed( T_size const& P_seed )
 {
  M2_seed = P_seed;
  if(false){
    if( 1000000 < P_seed )
     {
      M2_seed -= 1000000;
      GIs_model = GIs_dynamic;
     }
    if( GI_seed != M2_seed )
     {
      GIs_dynamic = GIs_model;
     }
    GI_seed = M2_seed;

   T_size I_chunck = 3;
   GI_size  = GIs_dynamic.size();

   M2_seed = M2_seed%(GIs_dynamic.size() - I_chunck + 1 );
   if( true == GI_init  )
   {
      std::shuffle( GIs_dynamic.begin()+ M2_seed, GIs_dynamic.begin() + M2_seed + I_chunck, std::mt19937( std::random_device()() ) );
   }
   else
   {
     GI_init = true;
   }
  }

  if(true){
    std::next_permutation( GIs_dynamic.begin()+1, GIs_dynamic.end() );
   }
  std::cout << "PERMUTATION: "<< (GI_size= GIs_dynamic.size()) <<" {";
  for( T_size I_index =0;  I_index < GI_size; ++I_index )
   {
    std::cout << std::setw(3) << GIs_dynamic[ I_index ] << ", ";
   }
  std::cout <<"}; " << std::endl;
  return bool( true );
 }

bool   GC_mist::F_density( T_scalar const& P_density )
 {
  M2_density = P_density;
  return bool( true );
 }

bool   GC_mist::F_precision( T_scalar const& P_precision )
 {
  M2_precision = P_precision;
  // set 
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
