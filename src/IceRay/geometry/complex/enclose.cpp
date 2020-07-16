#include <limits>
#include "./enclose.hpp"
#include "../volumetric/vacuum.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_complex;



struct GC_enclose::C_intersect
 {
  bool M_hit;
 };

GC_enclose::GC_enclose()
: GC_enclose( nullptr, nullptr )
 {
 }

GC_enclose::GC_enclose
 (
  T__base *P_child, T__base *P_hull
 )
 {
  F_hull( P_hull );
  F_child( P_child );
 }

GC_enclose::~GC_enclose( )
 {
 }

void
GC_enclose::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  T_state I_hull;       P_state.F_tail<C_intersect>( I_hull );
  F_hull().Fv_reset( I_hull );

  T_state I_child;   I_hull.F_tail( I_child,   M2_hull.M_weight );
  F_child().Fv_reset( I_child );

  return;
 }

GC_enclose::T_size
GC_enclose::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += F_hull().Fv_weight();
  Ir_weigh += F_child().Fv_weight();

  return Ir_weigh;
 }

GC_enclose::T_size const& GC_enclose::Fv_id( T_state const&P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state I_hull;       P_state.F_tail<C_intersect>( I_hull );
  T_state I_child;   I_hull.F_tail( I_child,   M2_hull.M_weight );

  return M2_child.M__base->Fv_id( I_child );
 }

GC_enclose::T_size const&    GC_enclose::Fv_quantity()const
 {
  static T_size Irs_size = 1;
  return Irs_size;
 }

GC_enclose::T__base*    GC_enclose::Fv_base( T_size const& P_index )const
 {
  if( 0 != P_index )
   {
    return nullptr;
   }
  return M2_child.M__base;
 }

bool                    GC_enclose::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  if( false == I_head.M_hit )
   {
    return false ;
   }

  ++P_fragment.M_depth;

  T_state I_hull;       P_state.F_tail<C_intersect>( I_hull );
  T_state I_child;   I_hull.F_tail( I_child,   M2_hull.M_weight );

  P_fragment.M_index = 0;
  P_fragment.M_state = I_child;
  P_fragment.M__base = M2_child.M__base;

  return true;
 }

bool GC_enclose::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_lam_inf=0, I_lam_sup=P_lambda;

  C_intersect    &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );
  T_state I_hullTemp;   I_mainHit.F_tail( I_hullTemp,   M2_hull.M_weight );
  T_state I_childTemp; I_hullTemp.F_tail( I_childTemp,  M2_child.M_weight );

  auto I_location = M2_hull.M_inside->Fv_inside( P_ray.M_origin /*, P_intersect */ );

  switch( I_location )
   {
    case( T_location::En_in  ):
     {
     }break;
    case( T_location::En_out ):
     {
      auto I_lambda = P_lambda;
      if( false == M2_hull.M_intersect->Fv_intersect( I_lambda, I_hullTemp, P_ray ) )
       {
        return false;
       }
      break;
     }
    default: return false;
   }

  if( true ==  M2_child.M_intersect->Fv_intersect( P_lambda, I_childTemp, P_ray ) )
   {
     I_intersect.M_hit = true;
   }

  return I_intersect.M_hit;
 }

void GC_enclose::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state      const& P_state
 )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  if( false == I_head.M_hit )
   {
    return;
   }

  T_state I_hull;       P_state.F_tail<C_intersect>( I_hull );
  T_state I_child;   I_hull.F_tail( I_child,   M2_hull.M_weight );

  return M2_child.M_normal->Fv_normal( P_normal, P_point, I_child );
 }

GC_enclose::T_location GC_enclose::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  auto I_location = M2_hull.M_inside->Fv_inside( P_point /*, P_intersect */ );

  switch( I_location )
   {
    case( T_location::En_in  ):
     {
      return  M2_child.M_inside->Fv_inside( P_point /*, P_intersect */ );
     }break;
    default: return T_location::En_out;
   }

  return T_location::En_out;
 }

GC_enclose::T_scalar
GC_enclose::Fv_distance( T_coord const& P_point )const
 {
  // TODO
  return 0;
 }

bool  GC_enclose::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const& P_state)const
 {
  return false;
 }

GC_enclose::T__base & GC_enclose::Fs_vacuum()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum T_vacuum;
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }


GC_enclose::T__base const& GC_enclose::F_hull( )const
 {
  return *M2_hull.M__base;
 }

bool GC_enclose::F_hull( T__base * P_hull )
 {
  auto I_old = M2_hull;
  if( nullptr == P_hull )
   {
    P_hull = &Fs_vacuum();
   }

  M2_hull.M_weight    = P_hull->Fv_weight();
  M2_hull.M__base     = P_hull ;
  M2_hull.M_intersect = dynamic_cast< T2_intersect*>( P_hull );
  M2_hull.M_inside    = dynamic_cast< T2_inside*>( P_hull );

  if( ( nullptr == M2_hull.M_intersect ) || ( nullptr == M2_hull.M_inside ) )
   {
    M2_hull = I_old;
    return false;
   }

  F1_box( F_hull().F_box() );
  return true;
 }

GC_enclose::T__base const& GC_enclose::F_child( )const
 {
  return *M2_child.M__base;
 }

bool GC_enclose::F_child( T__base * P_child )
 {
  auto I_old = M2_child;
  if( nullptr == P_child )
   {
    P_child = &Fs_vacuum();
   }

  M2_child.M_weight    = P_child->Fv_weight();
  M2_child.M__base     = P_child ;
  M2_child.M_intersect = dynamic_cast< T2_intersect*>( P_child );
  M2_child.M_normal    = dynamic_cast< T2_normal*>( P_child );
  M2_child.M_inside    = dynamic_cast< T2_inside*>( P_child );

  if( ( nullptr == M2_child.M_intersect ) || ( nullptr == M2_child.M_inside ) )
   {
    M2_child = I_old;
    return false;
   }

  if( false == M2_hull.M__base->Fv_box( F_child().F_box() ) )
   {
    M2_child = I_old;
    return false;
   }

  F1_box( F_hull().F_box() );
  return true;
 }