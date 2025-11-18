#include <iostream>
#include <iomanip>

#include "./implementation.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack;

GC_implementation::GC_implementation()
 {
  M2_lastUID = 0;
  M2_index =0;
 }
 
GC_implementation::~GC_implementation()
 {
 }

GC_implementation::T__input::T_ray           & GC_implementation::Fv_top( ) 
 {
  return T_data::F_top().M_incoming;
 }

GC_implementation::T__input::T_ray      const& GC_implementation::Fv_top( )const 
 {
  return T_data::F_top().M_incoming;
 }

GC_implementation::T__stack::T_accident       & GC_implementation::Fv_topAccident( )
 {
  return T_data::F_top();
 }

GC_implementation::T__stack::T_accident   const& GC_implementation::Fv_topAccident( )const
 {
  return T_data::F_top();
 }

void GC_implementation::Fv_pop()
 {
  if( 0 == T_data::F_size() )
   {
    return;
   }

  if( 0 == M2_index )
   {
    M2_index = T_data::F_size();
    //return;
   }

  --M2_index;

  auto & I_accident = Fv_topAccident();

  I_accident.F_clear();

  T_data::F_pop();
 }

GC_implementation::T_size const&
GC_implementation::Fv_occupancy()const
 {
  return T_data::F_size();
 }

void GC_implementation::Fv_reserve( T_size const& P_capacity )
 {
  return T_data::F_reserve( P_capacity );
 }

GC_implementation::T_size const&
GC_implementation::Fv_size( )const
 {
  return M2_index;
 }

GC_implementation::T__input::T_ray & 
GC_implementation::Fv_expose( T_size const& P_index )
 {
  return  T_data::F_at( ( T_data::F_size() - M2_index ) + P_index ).M_incoming;
 }

GC_implementation::T__input::T_ray const& 
GC_implementation::Fv_get( T_size const& P_index )const
 {
  return  T_data::F_at( ( T_data::F_size() - M2_index ) + P_index ).M_incoming;
 }

void GC_implementation::Fv_push()
 {
  static T_scalar Is_infinity = + 1e12;

  if( T_data::F_size() == T_data::F_capacity() )
   {
    return;
   }

  ++M2_lastUID;
  ++M2_index;

  auto & I_accident = T_data::F_push();
//I_ray.M_intersection.M_lambda  = Is_infinity;
  I_accident.M_incoming.M_UID    = M2_lastUID;
  I_accident.M_incoming.M_status = T__input::T_ray::Ee_status::En_active;
  I_accident.M_consume           = T__stack::T_accident::Ee_consume::En_fresh;
 }

void GC_implementation::F_clear()
 { // DONE
  M2_lastUID = 0;
  M2_index = 0;
  T_data::F_clear();
  T__beam::F_clear();
  //T__stack::F_clear();
 }

GC_implementation::T_size   const&  GC_implementation::F_index()const
 { 
  return M2_index; 
 }
void             GC_implementation::Fv_mark()
 {
  M2_index = 0; 
 }

