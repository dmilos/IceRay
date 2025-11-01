#ifndef Dh_DDMM_IceRay_type_ray_state_HPP_
 #define Dh_DDMM_IceRay_type_ray_state_HPP_
// GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace


 #include "../basic/size.hpp"

 #include "../../geometry/_type/state.hpp"

 #include "./trace.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_ray
        {

         class GC_state
          : public GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace
          {
           public:

             typedef GS_DDMRM::S_IceRay::S_type::GT_size                   T_size;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state     T_state;

             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace   T_trace;

           public:
                      GC_state( )
                       : M_index( 0 )
                       {
                       }

             explicit GC_state( T_state const& P_state )
              : M_state( P_state )
              , M_index( 0 )
              {
              }

             explicit GC_state( T_trace const& P_trace )
              : T_trace( P_trace )
              , M_index( 0 )
              {
              }

                      GC_state( T_trace const& P_trace, T_state const& P_state )
              : T_trace( P_trace )
              , M_state( P_state )
              , M_index( 0 )
              {
              }

             GC_state const& operator=( T_trace const& P_trace )
              {
               (T_trace)*this = P_trace;
               return *this;
              }

           public:
             T_state  M_state;
             T_size   M_index;
          };

        }
      }
    }
  }

#endif
