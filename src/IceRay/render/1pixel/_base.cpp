#include "./_base.hpp"


#include "./strategy/center.hpp"
#include "./filter/const.hpp"



using namespace GS_DDMRM::S_IceRay::S_render::S_pixel;


GC__base::T2_center GC__base::M2s_center;
GC__base::T2_const GC__base::M2s_const;

GC__base::GC__base()
 :M2_strategy( &M2s_center )
 ,M2_filter(   &M2s_const )
 {

 }
GC__base::~GC__base()
 {

 }

void
GC__base::Fv_render( T_color & P_color, T_cell const& P_cell )
 {
  F_strategy().Fv_make();
  F1_filter().Fv_reset();

  T1_uv I_origin;
  F1_2uv( I_origin, P_cell );

  T1_color I_summae( ::color::constant::black_t{} );
  T1_size  I_index = 0;
  for( auto const& I_dot : F_strategy().F_sieve() )
   {
    switch( F1_filter().Fv_check( I_summae, I_dot, I_index++ ) )
     {
      case( T_filter::En_skip    ): continue; break;
      case( T_filter::En_process ): break;
      case( T_filter::En_break   ): goto L_break; break;
     }

    T1_uv I_uv;
    ::math::linear::vector::multiply( I_uv, I_dot, F1_scale() );
    ::math::linear::vector::addition( I_uv, I_origin );

    T1_color I_color( ::color::constant::black_t{} );
    F_pierce().F_render( I_color, I_uv );
    I_summae += I_color;
   }
  L_break:
    ;

  I_summae /= F_strategy().F_sieve().size();
  ::color::fix::overburn( I_summae );
  P_color = I_summae;
 }

void GC__base::F_strategy( T_strategy * P_strategy )
 {
  M2_strategy = P_strategy;
 }

void GC__base::F_filter( T_filter  * P_filter )
{
  M2_filter = P_filter;
}