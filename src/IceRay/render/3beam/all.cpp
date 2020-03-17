#include "all.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_beam;

GC_all::GC_all()
 {
 }

GC_all::~GC_all()
 {
 }

void
GC_all::Fv_do( T_color &P_color, T_beam  const& P_beam )
 {
  T_color I_color;

  for( T_beam::const_iterator
         I_ray  = P_beam.begin();
         I_ray != P_beam.end();
         ++I_ray
     )
   {
    I_color = T_color( ::color::constant::black_t{} );
    F1v_ray()->Fv_trace( I_color, *I_ray );
    P_color += I_color;
   }

 }