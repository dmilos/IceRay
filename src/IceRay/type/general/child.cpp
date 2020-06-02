#include "./child.hpp"
#include "./parent.hpp"

using namespace GS_DDMRM::S_type::S_general;


GC_child::GC_child(T_parent *P_parent)
:M2_parent( nullptr )
 {
  this->Fv_parent( P_parent );
 }

GC_child::~GC_child()
 {
  this->Fv_parent( nullptr );
 }

void GC_child::Fv_parent( T_parent *P_parent )
 {
  if( M2_parent == P_parent )
   {
    return;
   }
  if( nullptr != M2_parent )
   {
    M2_parent->Fv_release( this );
   }

  M2_parent = P_parent;

  if( nullptr != M2_parent )
   {
    M2_parent->Fv_attach( this );
   }
}
