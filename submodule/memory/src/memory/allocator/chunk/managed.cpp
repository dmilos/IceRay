#include "./managed.hpp"
#include "../fixed.hpp"

using namespace GS_DDMRM::S_system::S_allocator::S_chunk;

GC_managed::GC_managed( T_allocator *P_allocator, T_ptr P_ptr )
 :T_simple( nullptr )
 ,M2_allocator( P_allocator )
 {
  if( nullptr != M2_allocator )
   {
    if( true == M2_allocator->F_check( P_ptr ) )
     {
      if( true == M2_allocator->F_share( *this, P_ptr ) )
       {
        return;
       }
      else
       {
        M2_allocator = M2_allocator;
       }
     }
    else
     {
      M2_allocator = M2_allocator;
     }
   }
  else
   {
    M2_allocator = M2_allocator;
   }

  M2_allocator = nullptr;
  T_simple::F_ptr( P_ptr );
 }

GC_managed::GC_managed( GC_managed const& P_that )
 : T_simple( nullptr )
 , M2_allocator( nullptr )
 {
  *this = P_that;
 }

GC_managed::~GC_managed()
 {
  F_release();
 }

GC_managed & GC_managed::operator=( GC_managed const& P_other )
 {
  if( nullptr != M2_allocator )
   {
    M2_allocator ->F_release( *this );
   }
  else
   {
    F_ptr( nullptr );
   }

  if( nullptr == P_other.F_allocator() )
   {
    F_ptr( P_other.F_ptr() );
    M2_allocator = nullptr;
    return *this;
   }
  P_other.F_allocator()->F_clone( *this, P_other );

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
