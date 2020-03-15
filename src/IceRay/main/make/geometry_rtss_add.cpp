
#include "../../geometry/rtss/_pure.hpp"
#include "../../geometry/rtss/object.hpp"



typedef GS_DDMRM::S_IceRay::S_type::GT_size  GTs_size;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;

typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object GTs_rtss_object;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure GTs_rtss__pure;


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {


//void rtss_begin( GTs_object * P_rtss )
// {
//  GTs_rtss_object   *I_rtss= dynamic_cast<GTs_rtss_object *>( P_rtss );
//
//  if( nullptr == I_rtss ) return ;
//
//  I_rtss->F_rtss()->Fv_??????();
// }

GTs_size rtss_add( GTs_object * P_rtss, GTs_object * P_child )
 {
  GTs_rtss_object   *I_rtss= dynamic_cast<GTs_rtss_object *>( P_rtss );

  if( nullptr == I_rtss ) return GTs_rtss__pure::Fs_invalid();

  return I_rtss->F_push( P_child );
 }


void rtss_done( GTs_object * P_rtss )
 {
  GTs_rtss_object   *I_rtss= dynamic_cast<GTs_rtss_object *>( P_rtss );

  if( nullptr == I_rtss ) return ;

  I_rtss->F_rtss()->Fv_optimize();
 }

     }
   }
 }

