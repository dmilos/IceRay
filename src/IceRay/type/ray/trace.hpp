#ifndef Dh_DDMM_IceRay_type_ray__trace_HPP_
 #define Dh_DDMM_IceRay_type_ray__trace_HPP_
// GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace

#include <sstream>
#include <iomanip>

#include "../basic/size.hpp"
#include "../basic/string.hpp"
#include "IceRay/geometry/_type/state.hpp"


 #include "./simple.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_ray
        {

         class GC_trace
          : public GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_string              T_string;

             enum class Ee_derivation
              {
                En__Unknown,
                En_Eye
               ,En_Light
               ,En_Reflected
               ,En_Refracted
               ,En_Teleported
               ,En_Blossom
               ,En_Broken      //! Pass to thin object like plane. Same medium but different direction.
              };

             static T_string to_string( Ee_derivation const& P_derivation )
              {
               switch( P_derivation  )
                {
                 default:
                 case( Ee_derivation::En__Unknown   ): return "_Unknown";
                 case( Ee_derivation::En_Eye        ): return "Eye";
                 case( Ee_derivation::En_Light      ): return "Light";
                 case( Ee_derivation::En_Reflected  ): return "Reflected";
                 case( Ee_derivation::En_Refracted  ): return "Refracted";
                 case( Ee_derivation::En_Teleported ): return "Teleported";
                 case( Ee_derivation::En_Blossom    ): return "Blossom";
                 case( Ee_derivation::En_Broken     ): return "Broken";
                }
              }

             enum class Ee_status
              {
                En__Unknown
               ,En_active
               ,En_abandoned
              };
             static T_string to_string( Ee_status const& P_status )
              {
               switch( P_status )
                {
                 default:
                 case( Ee_status::En__Unknown  ): return "_Unknown";
                 case( Ee_status::En_active    ): return "active";
                 case( Ee_status::En_abandoned ): return "abandoned";
                }
              }

             enum class Ee_hierarchy
              {
                En__Unknown
               ,En_solo
               ,En_lead
               ,En_middle
               ,En_back
              };
             static T_string to_string( Ee_hierarchy const& P_hierarchy )
              {
               switch( P_hierarchy )
                {
                 default:
                 case( Ee_hierarchy::En__Unknown    ): return "_Unknown";
                 case( Ee_hierarchy::En_solo        ): return "solo";
                 case( Ee_hierarchy::En_lead        ): return "lead";
                 case( Ee_hierarchy::En_middle      ): return "middle";
                 case( Ee_hierarchy::En_back        ): return "back";
                }
              }

           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_uint64             T_uint64;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state  T_state;

             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_line   T_line;
             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple T_simple;

           public:
             GC_trace()
              :GC_trace( T_simple( T_line{} ), Ee_derivation::En__Unknown )
              {
              }

             explicit GC_trace( T_line const& P_line )
              :GC_trace( T_simple( P_line ), Ee_derivation::En__Unknown )
              {
              }

             explicit GC_trace( T_simple const& P_simple )
              :GC_trace( P_simple, Ee_derivation::En__Unknown )
              {
              }

             GC_trace( T_simple const& P_simple, Ee_derivation const& P_derivation )
              :T_simple( P_simple )
              ,M_depth( 0 )
              ,M_parentUID( 0 )
              ,M_derivation( P_derivation )
              ,M_status( Ee_status::En_active )
              ,M_hierarchy( Ee_hierarchy::En_solo )
              ,M_ior( 1.000277 )
              ,M_coefficient( 1 )
              {
              }

             GC_trace const& operator=( T_simple const& P_simple )
              {
               (T_simple)*this = P_simple;
               return *this;
              }

           public:
             void F_clear()
              {
               M_depth       = -1;
               M_UID         = -1;
               M_parentUID   = -1;
               M_derivation  = Ee_derivation::En__Unknown;
               M_status      = Ee_status::En__Unknown;
               M_hierarchy   = Ee_hierarchy::En__Unknown;
               M_ior         = -1;
               M_coefficient = -1;
               M_state.F_clear();
               M_geometryID  = -1;
              }

           public:
             T_size         M_depth;
             T_uint64       M_UID;
             T_uint64       M_parentUID;
             Ee_derivation  M_derivation;
             Ee_status      M_status;
             Ee_hierarchy   M_hierarchy;

           public:
             T_scalar  M_ior;
             T_scalar  M_coefficient;
             T_state   M_state;
             T_size    M_geometryID;

           public:
             static T_string to_string( GC_trace const & P_ray )
              {
               std::stringstream ss;
               ss << "{ ";
               ss << "d: " << std::setw( 3 ) << P_ray.M_depth << "; ";
               ss << "UID: " << std::setw( 8 ) << P_ray.M_UID << "; ";
               ss << "p: " << std::setw( 8 ) << P_ray.M_parentUID << "; ";
               ss << std::setw( 8 ) << GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace::to_string( P_ray.M_derivation ) << "; ";
               ss << std::setw( 8 ) << GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace::to_string( P_ray.M_status     ) << "; ";
               ss << std::setw( 8 ) << GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace::to_string( P_ray.M_hierarchy  ) << "; ";
               ss << "G: " << P_ray.M_geometryID  << "; ";
               ss << "ior: " << P_ray.M_ior << "; ";
               ss << "ptr: " << GS_DDMRM::S_system::S_allocator::S_fixed::GC_manager::to_string( P_ray.M_state.F_chunk() ) << "; ";
               ss << " }";
               return ss.str();
              }
          };

        }
      }
    }
  }

#endif

