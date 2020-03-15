#include "IceRay/geometry/blobby/sphere.hpp"
#include "IceRay/geometry/blobby/ucylinderZ.hpp"
#include "IceRay/geometry/blobby/uwaterZ.hpp"
#include "IceRay/geometry/blobby/system.hpp"
#include "IceRay/geometry/blobby/translate.hpp"
#include "IceRay/geometry/blobby/usphere.hpp"
#include "IceRay/geometry/blobby/system.hpp"
#include "IceRay/geometry/rtss/_pure.hpp"

#include "IceRay/type/math/coord.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar GTs_coord;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element  GTs__element;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure GTs_rtss;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system GTs_system;



namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {

GTs_object *make_blobby_system( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system GTs_system;
  return new GTs_system( );
 }
 
bool make_blobby_system_add( GTs_object *P_system, GTs_object* P_element )
 {
  GTs_system   *I_system = dynamic_cast<GTs_system *>( P_system );
  GTs__element *I_element = dynamic_cast<GTs__element *>( P_element );

  if( nullptr == I_system  ) return false;
  if( nullptr == I_element ) return false;
  
  I_system->F_add( I_element );
  return true;
 }


bool make_blobby_system_rtss( GTs_object *P_system, GTs_object* P_rtss )
 {
  GTs_system   *I_system = dynamic_cast<GTs_system *>( P_system );
  GTs_rtss     *I_rtss   = dynamic_cast<GTs_rtss *>( P_rtss );

  if( nullptr == I_system  ) return false;
  if( nullptr == I_rtss ) return false;
  
  I_system->F_rtss( I_rtss );
  return true;
 }
 
GTs_object * make_blobby_ucylinderZ( GTs_scalar const& P_radius )
  {
   typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ Tf_ucylinderZ;

   return new Tf_ucylinderZ( P_radius );
  }

GTs_object * make_blobby_uwaterZ( GTs_scalar const& P_level )
  {
   typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_uwaterZ Tf_uwaterZ;

   return new Tf_uwaterZ( P_level );
  }

GTs_object * make_blobby_sphere( GTs_coord const& P_center, GTs_scalar const& P_influence, GTs_scalar const& P_radius )
  {
   typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere Tf_sphere;

   return new Tf_sphere( P_center, P_influence, P_radius );
  }

GTs_object * make_blobby_usphere( GTs_scalar const& P_radius )
  {
   typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere Tf_usphere;

   return new Tf_usphere( P_radius );
  }


GTs_object * make_blobby_translate( GTs_object * P_element, GTs_coord const& P_translate )
  {
   typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate Tf_translate;

   Tf_translate *I_translate = new Tf_translate( dynamic_cast<GTs__element*> (P_element), P_translate );
   return I_translate;
  }

  
  

     }
   }
 }

