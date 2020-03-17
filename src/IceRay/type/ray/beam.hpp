#ifndef Dh_DDMM_IceRay_type_beam_HPP_
 #define Dh_DDMM_IceRay_type_beam_HPP_

// GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GC_beam< ... >
// GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GT_line
// GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GT_simple
// GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GT_trace
// GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GT_state

 
 #include <vector>
 #include "./line.hpp"
 #include "./simple.hpp"
 #include "./trace.hpp"
 #include "./state.hpp"
 

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_ray
        {
         namespace S_beam
          {

           template< typename N_ray>
            struct GC_generator
             {
              public:
                typedef std::vector<N_ray> T_typedef;
             };

           typedef GC_generator< GS_DDMRM::S_IceRay::S_type::S_ray::GC_line   >::T_typedef    GT_line;
           typedef GC_generator< GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple >::T_typedef    GT_simple;
           typedef GC_generator< GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace  >::T_typedef    GT_trace;
           typedef GC_generator< GS_DDMRM::S_IceRay::S_type::S_ray::GC_state  >::T_typedef    GT_state;

          }
        }
      }
    }
  }

#endif
