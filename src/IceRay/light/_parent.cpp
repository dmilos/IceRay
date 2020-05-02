#include <cmath>

#include "./_parent.hpp"
#include "./point.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


GC__parent::GC__parent( )
 : GC__parent( &Fs_point() )
 {
 }

GC__parent::~GC__parent()
 {

 }

GC__parent::GC__parent
 (
   T__pure *P_child
 )
 : M2_child( P_child )
 {
  if( nullptr == M2_child )
   {
    M2_child = &Fs_point();
   }

  F1_max() = M2_child->F_max();
 }

GC__parent:: T__pure & GC__parent::Fs_point()
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;
  static Tf_point Irs_point( T_coord{ 0, 0, 0 } );

  return Irs_point;
 }
