#include "./intersect.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG;



struct GC_intersect::C_intersect
 {
  C_intersect()
  {
   M_hitHit = GC_intersect::En_none;
  }

  GC_intersect::Ee_side M_hitHit;
 };


GC_intersect::GC_intersect()
 :GC_intersect( &Fs_vacuum(), T_location::En_in, &Fs_vacuum(), T_location::En_in  )
 {
 }

GC_intersect::GC_intersect( T_geometry * P_left, T_location const& P_lo,  T_geometry * P_right, T_location const& P_ro )
{
  M2_left.F_set( P_left,  P_lo );
  M2_right.F_set( P_right, P_ro );

  F2_recalc();
 }

GC_intersect::~GC_intersect( )
 {
 }

void    GC_intersect::Fv_reset( T_state &P_state )const
 {
  C_intersect *I_intersect = new ( P_state.F_ptr() ) C_intersect();
 }

GC_intersect::T_size  GC_intersect::Fv_weight( )const
 {
  T_size Ir_size = 0;

  Ir_size += sizeof( C_intersect );
  Ir_size += M_intersecMainSize;
  Ir_size += M2_left.M_tempSize;
  Ir_size += M2_right.M_tempSize;

  return Ir_size;
 }

GC_intersect::T_size const& GC_intersect::Fv_id( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );
  T_state I_leftTemp;   I_mainHit.F_tail( I_leftTemp, M_intersecMainSize );
  T_state I_rightTemp; I_leftTemp.F_tail( I_rightTemp, M2_left.M_tempSize );

  switch( I_intersect.M_hitHit )
   {
    case( En_left ):
     {
      std::memcpy( I_leftTemp.F_ptr(),  I_mainHit.F_ptr() , M2_left.M_tempSize );
      return M2_right.M_base->Fv_id( I_rightTemp );
     }break;
    case( En_right ):
     {
      std::memcpy( I_rightTemp.F_ptr(), I_mainHit.F_ptr(), M2_right.M_tempSize  );
      return M2_left.M_base->Fv_id( I_leftTemp );
     }break;
    default:
     {
      return F_id();
     }break;
   }

  return F_id();
 }

bool GC_intersect::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  T_state I_mainHit; P_state.F_tail<C_intersect>(I_mainHit) ;
  T_state I_leftTemp;   I_mainHit.F_tail( I_leftTemp, M_intersecMainSize );
  T_state I_rightTemp; I_leftTemp.F_tail( I_rightTemp, M2_left.M_tempSize );

  Ee_side I_hitTemp = En_none;

  switch( I_intersect.M_hitHit )
   {
    case( En_left ):
     {
      std::memcpy( I_leftTemp.F_ptr(),  I_mainHit.F_ptr() , M2_left.M_tempSize );
      M2_right.M_base->Fv_reset( I_rightTemp );
     }break;
    case( En_right ):
     {
      M2_left.M_base->Fv_reset( I_leftTemp );
      std::memcpy( I_rightTemp.F_ptr(), I_mainHit.F_ptr(), M2_right.M_tempSize  );
     }break;
    default:
     {
      M2_left.M_base->Fv_reset( I_leftTemp );
      M2_right.M_base->Fv_reset( I_rightTemp );
     }break;
   }

  T_scalar I_lambda = 0;
  T_scalar left_lambda = P_lambda;
  T_scalar right_lambda = P_lambda;

  T_ray I_ray( P_ray );

  bool lf = M2_left.M_intersect->Fv_intersect(  left_lambda,  I_leftTemp,  I_ray );
  bool rf = M2_right.M_intersect->Fv_intersect( right_lambda, I_rightTemp, I_ray );

  // ******** "Zajednicki" deo *********
  if( ( false == lf  ) && ( false == rf ) )
   {
    return false;
   }

  if( ( true == lf ) && ( false == rf ) )
   {                // nedovrseno ( solid objekat sa rupom )
    last_left_test:
     I_lambda += left_lambda;
     using namespace ::math::linear::vector;
     I_ray.M_origin = I_lambda * P_ray.M_direction + P_ray.M_origin;

     if( M2_right.M_orientation == M2_right.M_inside->Fv_inside( I_ray.M_origin ) )
      {
       goto left_hit;
      }
    return false;
   }

  if( ( false == lf ) && ( true == rf ) )
   {
    last_right_test: // nedovrseno ( solid objekat sa rupom )
     I_lambda += right_lambda ;
     using namespace ::math::linear::vector;

     I_ray.M_origin = I_lambda * P_ray.M_direction + P_ray.M_origin;

     if( M2_left.M_orientation == M2_left.M_inside->Fv_inside( I_ray.M_origin ) )
      {
       goto right_hit;
      }

    return false;
   }

  while( true )
   if( left_lambda < right_lambda )
    {
     I_lambda += left_lambda;
     right_lambda -= left_lambda;

     using namespace ::math::linear::vector;

     I_ray.M_origin = I_lambda * P_ray.M_direction + P_ray.M_origin;
     if( M2_right.M_orientation == M2_right.M_inside->Fv_inside( I_ray.M_origin ) )
      {
       goto  left_hit;
      }

     left_lambda  = P_lambda - I_lambda;
     if( false == M2_left.M_intersect->Fv_intersect( left_lambda, I_leftTemp, I_ray ) )
      {
       goto last_right_test;
      }
    }
   else
    {
     I_lambda += right_lambda;
     left_lambda -= right_lambda;

     using namespace ::math::linear::vector;

     I_ray.M_origin = I_lambda * P_ray.M_direction + P_ray.M_origin;
     if( M2_left.M_orientation == M2_left.M_inside->Fv_inside( I_ray.M_origin ) )
      {
       goto right_hit;
      }
     right_lambda  = P_lambda - I_lambda;
     if( false == M2_right.M_intersect->Fv_intersect( right_lambda, I_rightTemp, I_ray ) )
      {
       goto last_left_test;
      }
    }

  //I_intersect.M_hitHit = En_none;
  return false;

  left_hit:
    P_lambda = I_lambda;
    I_intersect.M_hitHit = En_left;
    std::memcpy( I_mainHit.F_ptr(),  I_leftTemp.F_ptr() , M2_left.M_tempSize  );
    return true;

  right_hit:
    P_lambda = I_lambda;
    I_intersect.M_hitHit = En_right;
    std::memcpy( I_mainHit.F_ptr(),  I_rightTemp.F_ptr() , M2_right.M_tempSize  );
    return true;
 }

void GC_intersect::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_state ) const
 {
  C_intersect const &I_intersect = P_state.F_content<C_intersect>();

  T_state I_state; P_state.F_tail<C_intersect>(I_state);

  switch( I_intersect.M_hitHit )
   {
    case( En_left ):
     {
      M2_left.M_normal->Fv_normal( P_normal, P_point, I_state );
     }break;

    case( En_right ):
     {
      M2_right.M_normal->Fv_normal( P_normal, P_point, I_state );
     }break;
   }
 }

GC_intersect::T_location GC_intersect::Fv_inside( T_coord const& P_point )const
 {
  auto I_left  = ( M2_left.M_orientation  ==  M2_left.M_inside->Fv_inside( P_point ) ); 
  auto I_right = ( M2_right.M_orientation == M2_right.M_inside->Fv_inside( P_point ) ); 

  switch( (I_left?1:0) + (I_right?2:0) )
   {
    case( 0 + 0 ): return En_out;
    case( 1 + 0 ): return En_out;
    case( 0 + 2 ): return En_out;
    case( 1 + 2 ): return En_in;
   }
  return En_nowhere;
 }

GC_intersect::T_scalar  GC_intersect::Fv_distance( T_coord const& P_point )const
 {
  // C_intersect const &I_intersect = P_state.F_content<C_intersect>();
  // T_state I_stateL = P_state.F_tail<C_intersect>();
  // T_state I_stateR = P_state.F_tail<C_intersect>();

  T_scalar I_left  = M2_left.M_distance->Fv_distance(  P_point/*, I_stateL*/ );
  T_scalar I_right = M2_right.M_distance->Fv_distance( P_point/*, I_stateR*/ );

  return std::min<T_scalar>( I_left, I_right );
 }

bool      GC_intersect::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const& P_state )const
 {
  C_intersect const &I_intersect = P_state.F_content<C_intersect>();

  T_state I_state; P_state.F_tail<C_intersect>(I_state);

  switch( I_intersect.M_hitHit )
   {
    case( En_left ):
     {
      return M2_left.M_uvw->Fv_uvw( P_uvw, P_point, I_state );
     }break;

   case( En_right ):
    {
     return M2_right.M_uvw->Fv_uvw( P_uvw, P_point, I_state );
    }break;
   }
  return false;
 }

GC_intersect::T_size const&
GC_intersect::Fv_quantity( )const
 {
  static T_size Irs_size = 2;
  return Irs_size;
 }

GC_intersect::T__base*
GC_intersect::Fv_base( T_size const& P_index )const
 {
  switch( P_index )
   {
    case( 0 ): return M2_left.M_base;
    case( 1 ): return M2_right.M_base;
   }
  return &Fs_vacuum();
 }

bool GC_intersect::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const &I_intersect = P_state.F_content<C_intersect>();

  T_state I_state ; P_state.F_tail<C_intersect>(I_state);

  switch( I_intersect.M_hitHit )
   {
    case( En_left ):
     {
      ++P_fragment.M_depth;
      if( false == M2_left.M_cluster->Fv_fragment( P_fragment, I_state ) )
       {
        P_fragment.M_index = 0;
        P_fragment.M_state = I_state;
        P_fragment.M__base = M2_left.M_base;
       }
     }break;

   case( En_right ):
    {
     ++P_fragment.M_depth;
     if( false == M2_right.M_cluster->Fv_fragment( P_fragment, I_state ) )
      {
       P_fragment.M_index = 1;
       P_fragment.M_state = I_state;
       P_fragment.M__base = M2_right.M_base;
      }
    }break;
   }

  return true;
 }

GC_intersect::T_bool GC_intersect::Fv_solid( T_state const& P_state )const
 {
  C_intersect const &I_intersect = P_state.F_content<C_intersect>();

  T_state I_state; P_state.F_tail<C_intersect>(I_state);

  switch( I_intersect.M_hitHit )
   {
    case( En_left ):
     {
      return M2_left.M_solid->Fv_solid( I_state );
     }break;

    case( En_right ):
     {
      return M2_right.M_solid->Fv_solid( I_state );
     }break;
   }
  return false;
 }

bool  GC_intersect::F_left( T_geometry * P_left )
 {
  return F_left( P_left, M2_left.M_orientation );
 }

bool  GC_intersect::F_left( T_geometry * P_left, T_location const& P_orientation )
 {
  M2_left.F_set( P_left, P_orientation );
  F2_recalc();
  return bool( true );
 }

bool  GC_intersect::F_right( T_geometry * P_right )
 {
  return F_right( P_right, M2_right.M_orientation );
 }

bool  GC_intersect::F_right( T_geometry * P_right, T_location const& P_orientation  )
 {
  M2_right.F_set( P_right, P_orientation );
  F2_recalc();
  return bool( true );
 }


void GC_intersect::F2_recalc()
 {
  M_intersecMainSize = std::max<T_size>( M2_left.M_tempSize, M2_right.M_tempSize );

  M_offsetMain = 0;
  M_offsetLeft = M_offsetMain + M_intersecMainSize ;
  M_offsetRight = M_offsetMain + M_offsetLeft + M2_left.M_tempSize;

  switch( ( ( M2_right.M_orientation == T_location::En_in ) ? 0 : 2) +  ( ( M2_left.M_orientation == T_location::En_in ) ? 0 : 1 ) )
   {
    case( 0 + 0 ):   // clasic intersection
     {
      T_box I_box = F_box();
      ::math::geometry::interval::intersect( I_box, M2_left.M_base->F_box(), M2_right.M_base->F_box() );
      F1_box( I_box );
     }break;

    case( 1 + 0 ): // reverse diference
      F1_box( M2_right.M_base->F_box() );
     break;

    case( 0 + 2 ): // clasic diference
      F1_box( M2_left.M_base->F_box() );
     break;

    case( 1 + 2 ): // inverted union
     {
      T_box I_box = F_box();
      ::math::geometry::interval::extend( I_box, M2_left.M_base->F_box(), M2_right.M_base->F_box() );
      F1_box( I_box );
     }break;

    default :
      return ;
   }
 }

GC_intersect::T_vacuum & GC_intersect::Fs_vacuum()
 {
  static GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum Is_vacuum;
  return Is_vacuum;
 }



/*
size_t INTERSECT__set_index( size_t i, OBJECT *This )
 {
  size_t io, i2;
  INTERSECT *info =M1_info;

  io = NULL__set_index( i, This );
  i2 = 0;
  i2 = OBJECT__set_index( i2, info->left );
  i2 = OBJECT__set_index( i2, info->right );

  if( io!=i || i2 )
   {M1_index=i+1; return i+1; }

 M1_index=0; return i;
 }
*/

/*
size_t INTERSECT__get_index( OBJECT *This )
 {
  size_t index;
  OBJECT *hit;

  hit =((INTERSECT__TEMP *)(This->temp))->src ;
  std::memcpy( hit->temp, ((INTERSECT *)(This->info))->src_temp, hit->s_temp);

  index = OBJECT__get_index( hit );
  if( index ) return index;
  returnM1_index;
 }
*/

