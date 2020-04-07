
#include "./algorithm.hpp"
#include <memory>
#include <functional>
#include <iostream>
#include <iomanip>

using namespace GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2;


GC_algorithm::GC_algorithm( )
 {
  M2_object = &GC_algorithm::Fs_vacuum();
  F_trash( T_scalar( 0.5 ) );
  F_depth( 4 );
 }

#define PRINT(DP_number)                                                            \
                                          (DP_number / 1000000000000)% 1000 << " "  \
    <<                                    (DP_number / 1000000000   )% 1000 << " "  \
    << std::setw(3)<< std::setfill('0')<< (DP_number / 1000000      )% 1000 << " "  \
    << std::setw(3)<< std::setfill('0')<< (DP_number / 1000         )% 1000 << " "  \
    << std::setw(3)<< std::setfill('0')<< (DP_number / 1            )% 1000 << " "  \
    << "( " << std::setw(12)<< DP_number   << " ) "                                 \
    << 100 * (DP_number / (double)M2_stack.F_total()) << " %"

GC_algorithm::~GC_algorithm( )
 {
    std::cout << "Total:      " << PRINT(M2_stack.F_total() )       << std::endl;
    std::cout << "Traced:     " << PRINT(M2_statistic.M_traced    ) << std::endl;
    std::cout << "Discarded:  " << PRINT(M2_statistic.M_discarded ) << std::endl;
    std::cout << "Eye:        " << PRINT(M2_statistic.M_eye       ) << std::endl;
    std::cout << "Reflected:  " << PRINT(M2_statistic.M_reflected ) << std::endl;
    std::cout << "Refracted:  " << PRINT(M2_statistic.M_refracted ) << std::endl;
  //std::cout << "Too far:    " << PRINT(M2_statistic.M_2far      ) << std::endl;
    std::cout << "Too deep:   " << PRINT(M2_statistic.M_2deep     ) << std::endl;
    std::cout << "Under:      " << PRINT(M2_statistic.M_under     ) << std::endl;
    std::cout << "Miss:       " << PRINT(M2_statistic.M_miss      ) << std::endl;
    std::cout << "Teleported: " << PRINT(M2_statistic.M_teleported) << std::endl;
    std::cout << "Broken: "     << PRINT(M2_statistic.M_broken    ) << std::endl;

   std::cout << "Depth count: ";
   T_size I_summae = 0;
   for( auto const & I_count: M2_statistic.M_depth )
    {
     std::cout << I_count << "; ";
     I_summae += I_count;
    }
   std::cout << "S: " << I_summae << "; " ; 
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

  I_reseve += F1_object().Fv_maxNextRays() * F_depth(); //!< Other rays
  I_reseve += F1_object().Fv_maxNextRays() ; //!< Rejected

  I_reseve += 1; //!< Lights

  M2_stack.F_reserve( I_reseve );
  M2_stack.F_clear();

  M2_allocator.F_weight( F1_object().Fv_weight() );
  M2_allocator.F_reserve( I_reseve );
  M2_allocator.F_clear();
  M2_statistic.M_depth.resize( M2_depth, 0 );

  return true;
 }

bool GC_algorithm::F_trash( T_scalar const& P_trash )
 {
  M2_trash = P_trash;
  return true;
 }

void GC_algorithm::Fv_trace( T_color &P_color, T_ray const& P_incident )
 {
  {
   M2_stack.Fv_push();
   auto & I_accident = M2_stack.Fv_topAccident();
   auto & I_incoming = I_accident.M_incoming;

   new  (&I_incoming) T2_ray{ P_incident, T2_ray::En_type1Eye };

   M2_allocator.F_new( I_incoming.M_state.F_chunk() ) ;
   F1_object().F_geometry().Fv_reset( I_incoming.M_state );
  }

  F2_trace( P_color );
 }

/*
// puno zrakova svi su mali a treba sve pratiti.???
// smanjiti trash ???
// Da. tokom renderinga nemamo vremena za dodatnu logiku
*/
void GC_algorithm::F2_trace( T_color &P_color )
 {
  static T_scalar Is_infinity = 1e+12;// T_scalar( std::numeric_limits<T_scalar>::???() );

  T2_gray I_gray;
  T_color I_color, I_deplete, I_fog;
  P_color = ::color::constant::black_t{};

  while( 0 != M2_stack.Fv_occupancy() )
   {
    auto & I_accident     = M2_stack.Fv_topAccident();
    auto & I_incoming     = I_accident.M_incoming;
    auto & I_intersection = I_accident.M_intersection;

    if( T_stack::T_accident::En_statusUsed == I_accident.M_status )
     {
      if( T2_ray::En_type1Refracted == I_incoming.M_type )
       {
        auto id = F1_object().F_geometry().Fv_id( I_intersection.M_state );
        //if true == F1_object().F_geometry()->Fv_solid() )
        //F_medium()->pop( id );
       }
      M2_stack.Fv_pop(); continue;
     }

    ++M2_statistic.M_depth[ I_incoming.M_depth ];
    switch( I_incoming.M_type )
     {
      case( T2_ray::En_type1Eye        ) : ++M2_statistic.M_eye;        break;
      case( T2_ray::En_type1Light      ) : ++M2_statistic.M_light;      break;
      case( T2_ray::En_type1Reflected  ) : ++M2_statistic.M_reflected;  break;
      case( T2_ray::En_type1Refracted  ) : ++M2_statistic.M_refracted;  break;
      case( T2_ray::En_type1Teleported ) : ++M2_statistic.M_teleported; break;
      case( T2_ray::En_type1Broken     ) : ++M2_statistic.M_broken;     break;
     }

    if( T2_ray::En_statusDiscarded == I_incoming.M_status )
     {
      ++M2_statistic.M_discarded;
      M2_stack.Fv_pop(); continue;
     }

    if( F_depth() < I_incoming.M_depth )
     {
      ++M2_statistic.M_2deep;
      M2_stack.Fv_pop(); continue;
     }

    if( T2_gray( I_incoming.M_intesity ).get<0>() < F_trash() )
     {
      ++M2_statistic.M_under;
      M2_stack.Fv_pop(); continue;
     }

    ++M2_statistic.M_traced;

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
      ++M2_statistic.M_miss;
      M2_stack.Fv_pop(); continue;
     }

    I_intersection.M_geometryID = F1_object().F_geometry().Fv_id( I_intersection.M_state );

    if( T2_ray::En_type1Refracted == I_incoming.M_type )
     {
      // if true == F1_object().F_geometry()->Fv_solid() )
      //TODO F_medium()->push( I_accident.M_geometryID, I_incoming.M_IOR );
     }

    M2_stack.Fv_mark();

    F1_object().Fv_normal( I_intersection.M_normal, I_intersection.M_point, I_intersection.M_state );
    if( 0 < ::math::linear::vector::dot( I_intersection.M_normal, I_incoming.M_direction ) )
     {
      ::math::linear::vector::negate( I_intersection.M_normal );
     }

    F1_object().F_material().Fv_color( I_color, M2_stack, I_accident, I_intersection.M_state );

    I_accident.M_status = T_stack::T_accident::En_statusUsed;

    ::color::operation::multiply( I_color, I_incoming.M_intesity );

    P_color += I_color;
   }

  if( 0 != M2_allocator.F_acquired() )
   {
    M2_allocator.F_clear();
   }
    /*    */
  }
