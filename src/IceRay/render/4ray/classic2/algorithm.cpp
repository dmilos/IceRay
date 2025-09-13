#include <numeric>

#include "./algorithm.hpp"
#include "IceRay/material/compute/surface.hpp"

#include <memory>
#include <functional>
#include <iostream>
#include <iomanip>

using namespace GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2;


GC_algorithm::GC_algorithm( )
 {
  M2_object = &GC_algorithm::Fs_vacuum();
  M2_depth = 8;
  M2_trash = T_scalar( 0.5 );
  M2_next = 16;
  M2_ior = 1;

  F_trash( T_scalar( 0.5 ) );
  F_next( 16 );
  F_depth( 4 );
 }

#define PRINT(DP_number)                                                            \
                                          (DP_number / 1000000000000)% 1000 << " "  \
    <<                                    (DP_number / 1000000000   )% 1000 << " "  \
    << std::setw(3) << std::setfill('0')<< (DP_number / 1000000      )% 1000 << " "  \
    << std::setw(3) << std::setfill('0')<< (DP_number / 1000         )% 1000 << " "  \
    << std::setw(3) << std::setfill('0')<< (DP_number / 1            )% 1000 << " "  \
    << "( " << std::setw(12)<< DP_number   << " ) "                                 \
    <<  std::setw(6) << std::fixed << std::setprecision(5) << 100 * (DP_number / (double)I_summae) << " %; "      \
    <<  std::setw(6) << std::fixed << std::setprecision(5) << 100 * (DP_number / (double)M2_stack.F_total()) << " %; "

GC_algorithm::~GC_algorithm( )
 {
  if( false ) return;

  T_size I_summae = M2_stack.F_total();
  std::cout << "Summary:      " << PRINT( M2_stack.F_total() )       << std::endl;

  for( auto const& I_info : M2_statistic.M_depth )
   {
    I_summae = std::accumulate( I_info.begin(), I_info.end(), T_size(0) );

    std::cout << "Total:      " << PRINT( I_summae ) ;
    std::cout << "Eye:        " << PRINT( I_info[ (int)C_statistic::Ee_type::En_eye        ] );
    std::cout << "Traced:     " << PRINT( I_info[ (int)C_statistic::Ee_type::En_traced     ] );
    std::cout << "Abandoned:  " << PRINT( I_info[ (int)C_statistic::Ee_type::En_abandoned  ] );
    std::cout << "Reflected:  " << PRINT( I_info[ (int)C_statistic::Ee_type::En_reflected  ] );
    std::cout << "Refracted:  " << PRINT( I_info[ (int)C_statistic::Ee_type::En_refracted  ] );
    std::cout << "Too far:    " << PRINT( I_info[ (int)C_statistic::Ee_type::En_2far       ] );
    std::cout << "Too deep:   " << PRINT( I_info[ (int)C_statistic::Ee_type::En_2deep      ] );
    std::cout << "Under:      " << PRINT( I_info[ (int)C_statistic::Ee_type::En_under      ] );
    std::cout << "Miss:       " << PRINT( I_info[ (int)C_statistic::Ee_type::En_miss       ] );
    std::cout << "Teleported: " << PRINT( I_info[ (int)C_statistic::Ee_type::En_teleported ] );
    std::cout << "Broken:     " << PRINT( I_info[ (int)C_statistic::Ee_type::En_broken     ] );
    //std::cout << "Unknown:    " << PRINT( I_info[ (int)C_statistic::Ee_type::En__Unknown   ] );
    std::cout << std::endl;
   }
  std::cout << std::setfill(' ');
  std::cout << std::endl;
 }

bool GC_algorithm::F_object( T_object * P_object )
 {
  M2_object = P_object;
  return F_depth( F_depth() );
 }

GC_algorithm::T2_wrap & GC_algorithm::Fs_vacuum()
 {
  static T2_wrap Is_vacuum;
  return Is_vacuum;
 }

bool GC_algorithm::F_depth( T_size const& P_depth )
 {
  M2_depth = P_depth;

  T_size I_reseve = P_depth;
  I_reseve += 1; //!< First ray;
  I_reseve += 1; //!< Candidate

  auto I_next = std::max<T_size>( M2_next, F1_object().Fv_maxNextRays() );
  I_reseve += I_next * F_depth(); //!< Other rays
  I_reseve += I_next ; //!< Rejected

  I_reseve += 1; //!< Lights

  M2_stack.F_reserve( I_reseve );
  M2_stack.F_clear();

  M2_allocator.F_weight( F1_object().Fv_weight() );
  M2_allocator.F_reserve( I_reseve );
  M2_allocator.F_clear();
  M2_statistic.M_depth.resize( M2_depth + 3 );

  return true;
 }

bool GC_algorithm::F_trash( T_scalar const& P_trash )
 {
  M2_trash = P_trash;
  return true;
 }

bool GC_algorithm::F_next( T_size const& P_next )
 {
  M2_next = P_next;
  return F_depth( F_depth() );
 }

bool GC_algorithm::F_ior( T_scalar const& P_ior )
 {
  M2_ior = P_ior;
  return true;
 }

void GC_algorithm::Fv_trace( T_color &P_color, T_ray const& P_incident )
 {
  {
   M2_stack.Fv_push();
   auto & I_accident = M2_stack.Fv_topAccident();
   auto & I_incoming = I_accident.M_incoming;

    I_incoming.M_derivation = T2_ray::Ee_derivation::En_Eye;
    (T_ray&)I_incoming = P_incident;

   M2_allocator.F_new( I_incoming.M_state.F_chunk() ) ;
   F1_object().F_geometry().Fv_reset( I_incoming.M_state );
  }

  M2_stack.F_jurisdiction().F_clear();
  M2_stack.F_jurisdiction().F_push( 0, M2_ior );

  F1_object().F_material().Fv_IOR( M2_stack.F_jurisdiction(), P_incident.M_origin );

  F2_trace( P_color );
 }

bool GI_debug = false;

void GC_algorithm::F2_trace( T_color &P_color )
 {
  static T_scalar Is_infinity = 1e+12;// T_scalar( std::numeric_limits<T_scalar>::???() );

  T2_gray I_gray;
  T_color I_color, I_deplete, I_fog;
  P_color = ::color::constant::black_t{};
  auto & I_jurisdiction = M2_stack.F_jurisdiction();

  while( 0 != M2_stack.Fv_occupancy() )
   {
    auto & I_accident = M2_stack.Fv_topAccident();
    auto & I_incoming = I_accident.M_incoming;
    if( true == GI_debug )
     {
      std::cout << std::endl;
      std::cout << (int)I_accident.M_consume << "; ";
      std::cout << (int)I_incoming.M_derivation << "; ";
      std::cout << I_incoming.M_geometryID  << "; ";
      std::cout << I_incoming.M_ior << "; ";
      std::cout << std::endl;
     }

    switch( I_accident.M_consume )
     {
      case( T_stack::T_accident::Ee_consume::En__unknown ): /*TODO some comment or action */break;
      case( T_stack::T_accident::Ee_consume::En_discard ):
       {
        M2_stack.Fv_pop();
        continue;
       } break;
      case( T_stack::T_accident::Ee_consume::En_spent ):
       {
        if( T2_ray::Ee_derivation::En_Refracted == I_incoming.M_derivation )
         {
          switch( I_incoming.M_hierarchy )
           {
            case( T2_ray::Ee_hierarchy::En_solo ):
            case( T2_ray::Ee_hierarchy::En_back ):
             {
              I_jurisdiction.F_pop();
             }break;

            case( T2_ray::Ee_hierarchy::En_lead   ): /*TODO some comment or action */break;
            case( T2_ray::Ee_hierarchy::En_middle ): /*TODO some comment or action */break;

           }
         }
        I_accident.M_consume = T_stack::T_accident::Ee_consume::En_discard;
        continue;
       } break;
      //case( T_stack::T_accident::Ee_consume::En_skip ):
      case( T_stack::T_accident::Ee_consume::En_fresh ):
       {
        //++M2_statistic.M_depth[ I_incoming.M_depth ];
        switch( I_incoming.M_derivation )
         {
          case( T2_ray::Ee_derivation::En_Eye        ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_eye        ]; break;
          case( T2_ray::Ee_derivation::En_Light      ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_light      ]; break;
          case( T2_ray::Ee_derivation::En_Reflected  ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_reflected  ]; break;
          case( T2_ray::Ee_derivation::En_Refracted  ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_refracted  ]; break;
          case( T2_ray::Ee_derivation::En_Teleported ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_teleported ]; break;
          case( T2_ray::Ee_derivation::En_Broken     ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_broken     ]; break;
          case( T2_ray::Ee_derivation::En__Unknown   ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En__Unknown   ]; break;
          case( T2_ray::Ee_derivation::En_Blossom    ) : ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_blossom    ]; break;
         }
       } break;
     }

    if( T2_ray::Ee_status::En_abandoned == I_incoming.M_status )
     {
      ++M2_statistic.M_depth[ I_incoming.M_depth ][ (int)C_statistic::Ee_type::En_abandoned ];
      I_accident.M_consume = T_stack::T_accident::Ee_consume::En_discard;
      continue;
     }

    if( F_depth() < I_incoming.M_depth )
     {
      ++M2_statistic.M_depth[ I_incoming.M_depth ][ (T_size)C_statistic::Ee_type::En_2deep ];
      I_accident.M_consume = T_stack::T_accident::Ee_consume::En_discard;
      continue;
     }
    if( T2_gray( I_incoming.M_intesity ).get<0>() < F_trash() )
     {
      ++M2_statistic.M_depth[ I_incoming.M_depth ][ (int)C_statistic::Ee_type::En_under ];
      I_accident.M_consume = T_stack::T_accident::Ee_consume::En_discard;
      continue;
     }

    I_accident.M_consume = T_stack::T_accident::Ee_consume::En_spent;
    if( T2_ray::Ee_derivation::En_Refracted == I_incoming.M_derivation )
     {
      switch( I_incoming.M_hierarchy )
       {
        case( T2_ray::Ee_hierarchy::En_solo ):
        case( T2_ray::Ee_hierarchy::En_lead ):
         {
          I_jurisdiction.F_push( I_incoming.M_geometryID, I_incoming.M_ior );
         }break;
        case( T2_ray::Ee_hierarchy::En_middle ):  /*TODO some comment or action */break;
        case( T2_ray::Ee_hierarchy::En_back   ):  /*TODO some comment or action */break;
       }
     }

    M2_stack.Fv_mark();

    ++M2_statistic.M_depth[ I_incoming.M_depth ][ (int)C_statistic::Ee_type::En_traced ];

    auto & I_intersection = I_accident.M_intersection;

    I_intersection.M_lambda = Is_infinity;
    I_intersection.M_state = I_incoming.M_state;
    auto I_hit =  F1_object().Fv_intersect( I_intersection.M_lambda, I_intersection.M_state, I_incoming );

    ::math::linear::vector::combine( I_intersection.M_point, I_incoming.M_origin, I_intersection.M_lambda, I_incoming.M_direction );

    if( true == F1_object().F_material().Fv_attenuate( I_fog, I_deplete, I_incoming.M_origin, I_intersection.M_point, I_incoming.M_state ) )
     {
      ::color::operation::multiply( I_color, I_fog, I_incoming.M_intesity );
      P_color += I_color;
      ::color::operation::multiply( I_incoming.M_intesity, I_deplete );
     }

    if( false == I_hit )
     {
      ++M2_statistic.M_depth[ I_incoming.M_depth ][ (int)C_statistic::Ee_type::En_miss ];
      continue;
     }

    I_intersection.M_geometryID = F1_object().F_geometry().Fv_id( I_intersection.M_state );

    F1_object().Fv_normal( I_intersection.M_normal, I_intersection.M_point, I_intersection.M_state );
    if( 0 < ::math::linear::vector::dot( I_intersection.M_normal, I_incoming.M_direction ) )
     {
      ::math::linear::vector::negate( I_intersection.M_normal );
     }

    F1_object().F_material().Fv_color( I_color, M2_stack, I_accident, I_intersection.M_state );

    ::color::operation::multiply( I_color, I_incoming.M_intesity );

    P_color += I_color;
   }

  if( 0 != M2_allocator.F_acquired() )
   {
    M2_allocator.F_clear();
   }
    /*    */
  }
