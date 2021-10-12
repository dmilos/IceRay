#include "./aifs.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_complex;


struct GC_AIFS::C_intersect
 {
  T_size M_depth;
  T_size M_index;
  T_affine M_2local;
  T_affine M_2world;
};

GC_AIFS::GC_AIFS()
 {
 }

GC_AIFS::~GC_AIFS( )
 {
 }

void GC_AIFS::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_state = P_state.F_content<C_intersect>();
  I_state.M_index = Fs_invalid();
 }

GC_AIFS::T_size
GC_AIFS::Fv_weight( )const
 {
  T_size Ir_size = 0;

  Ir_size += sizeof( C_intersect );
  Ir_size += M2_compartment; //<! hit
  Ir_size += M2_compartment; //<! candidate
  Ir_size += M2_compartment; //<! test subject
  Ir_size += M2_depth * sizeof( T_size ) ; //<! original path
  Ir_size += M2_depth * sizeof( T_size ); //<! current path

  return Ir_size;

  return sizeof( C_intersect );
 }

GC_AIFS::T_size const& GC_AIFS::Fv_id( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  if( I_intersect.M_index == Fs_invalid() )
   {
    return Fs_invalid();
   }
  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );

  return M2_collection[I_intersect.M_index].M_geometry.M_cluster->Fv_id( I_mainHit );
 }

bool GC_AIFS::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  T_size I_depth=0;

  // push
  struct C_item
   {
    T_affine     M_2world;
    //T_intersect *M_intersect;
    T_size       M_depth;
   };

  for( auto const& I_object: M2_collection)
   {
     // push
     // I_new.M_2world    = I_object.M_2world;
     // I_new.M_intersect = I_object.M_intersect;
     // I_new.M_depth     =0 ;
   }


  while( false/* stack*/ )
   {
    //C_item const& I_current;

    T_ray I_ray;
    //I_ray.M_origin    = TODO
    //I_ray.M_direction =
    T_scalar I_lambda;
    I_lambda = P_lambda;

    //if( true == I_current.Fv_intersect( I_lambda, I_hitTest, I_ray ) )
     {


     }


     //if( I_item.M_depth < M2_depth )
      {
       for( auto const& I_object: M2_collection )
        {
         C_item  I_new;

         //::math::linear::affine( I_new.M_2world, I_item.M_2world , I_object.M_2world );
         //I_new.M_intersect = I_new.M_intersect;
         //I_new.M_depth     = I_item.M_depth + 1;
        }

      }

   };


  // TODO
  return false;
 }

void GC_AIFS::Fv_normal( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  if( I_intersect.M_index == Fs_invalid() )
  {
    return;
  }

  T_coord I_normal;

  T_coord I_point;
  ::math::linear::affine::transform( I_point, I_intersect.M_2local, P_point );
  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );
  M2_collection[I_intersect.M_index].M_geometry.M_normal->Fv_normal( I_normal, I_point, I_mainHit );

  T_matrix I_transpose;
  ::math::linear::matrix::transpose( I_transpose, I_intersect.M_2local.matrix() );

 ::math::linear::matrix::transform( P_normal, I_transpose, I_normal );

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_AIFS::T_location GC_AIFS::Fv_inside( T_coord const& P_point/*, T_state const&P_state*/ )const
 {
  // TODO
  //C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  //T_coord I_point;
  //::math::linear::affine::transform( I_point, I_intersect.M_2local, P_point );
  //
  //return M2_inside->Fv_inside( I_point/*, P_intersect */ );

  return En_nowhere;
 }

GC_AIFS::T_scalar  GC_AIFS::Fv_distance( T_coord const& P_point )const
 {
  static T_scalar Is_infinity = 1e+16;
//  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  // TODO
  return Is_infinity;
 }

bool      GC_AIFS::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  if( I_intersect.M_index == Fs_invalid() )
  {
    return false;
  }

  T_coord I_point;
  ::math::linear::affine::transform( I_point, I_intersect.M_2local, P_point );

  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );

  M2_collection[I_intersect.M_index].M_geometry.M_uvw->Fv_uvw( P_uvw, I_point, I_mainHit );

  return true;
}

GC_AIFS::T_affine const&  GC_AIFS::Fv_2world( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  if( I_intersect.M_index == Fs_invalid() )
   {
    return Fs_identity();
   }

  return I_intersect.M_2world;
 }

GC_AIFS::T_affine const&  GC_AIFS::Fv_2local( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  if( I_intersect.M_index == Fs_invalid() )
   {
    return Fs_identity();
   }
  return I_intersect.M_2local;
 }

GC_AIFS::T_size    const&  GC_AIFS::Fv_quantity()const
 {
  return M2_size = M2_collection.size();
 }

GC_AIFS::T__base*          GC_AIFS::Fv_base( T_size const& P_index )const
 {
  if( P_index < M2_collection.size())
   {
    return M2_collection[P_index].M_geometry.M__base;
   }
  return &Fs_vacuum();
 }

bool              GC_AIFS::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();

  P_fragment.M__base = nullptr;

  if( Fs_invalid() == I_head.M_index )
   {
    P_fragment.M_index = I_head.M_index;
    return false;
   }

  ++P_fragment.M_depth;
  P_fragment.M_index = I_head.M_index;
  P_fragment.M__base = M2_collection[P_fragment.M_index].M_geometry.M__base;
  P_state.F_tail<C_intersect>( P_fragment.M_state );

  return true;
 }

GC_AIFS::T_size    const& GC_AIFS::F_depth( )const
 {
  return M2_depth;
 }

bool             GC_AIFS::F_depth( T_size const& P_depth )
 {
  M2_depth = P_depth;
  return false;
 }



GC_AIFS::T_vacuum & GC_AIFS::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
