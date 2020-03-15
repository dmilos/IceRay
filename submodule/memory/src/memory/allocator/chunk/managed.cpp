#include "./managed.hpp"
#include "../fixed.hpp"

using namespace GS_DDMRM::S_system::S_allocator::S_chunk;

GC_managed::GC_managed( T_allocator *P_allocator, T_ptr P_ptr )
 : T_simple( P_ptr )
 , M2_allocator( P_allocator )
 {
  if( nullptr != M2_allocator )
   {
    // TODO if( false == M2_allocator->F_check( P_ptr ) )
    // TODO  {
    // TODO   F_ptr( nullptr );
    // TODO  }
   }
 }

GC_managed::~GC_managed()
 {
  F_release();
 }

GC_managed & GC_managed::operator=( GC_managed const& P_other )
 {
  if( nullptr == P_other.F_allocator() )
   {
    M2_allocator = nullptr;
    F_ptr( P_other.F_ptr() );
    return *this;
   }

  P_other.F_allocator()->F_new( *this, P_other );

  return *this;
 }

void GC_managed::F_release( )
 {
  if( nullptr == F_allocator() )
   {
    F_ptr( nullptr );
    return;
   }

  M2_allocator->F_release( *this );
  F_ptr( nullptr );
 }
