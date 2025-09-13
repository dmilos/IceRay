#include "./bezier.hpp"


struct GC_box::C_intersect
 {
  bool M_hit;
  T_coord2D M_uv;
 };

GC_bezier::GC_bezier(  )
 {
  T2_id::Fs_make( M2_struct );
 }


GC_bezier::GC_bezier( T_struct const& P_struct )
 {
  M2_struct = P_struct;
 }



GC_bezier::~GC_bezier( )
 {

 }

bool GC_bezier::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state  & P_intersect
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;//TODO make it local
  C2_state &I_intersect = P_intersect.F_content<C2_state>();


  I_intersect.M_hit = false;

  M2_stack.push_back( C2_item() );

  C2_item & I_first = M2_stack.back();

  ::math::linear::vector::load( I_first.M_interval.F_lo(), 0, 0 );
  ::math::linear::vector::load( I_first.M_interval.F_hi(), 1, 1 );
  I_first.M_struct = M2_struct;
  I_first.M_used = false;

  T_size I_count = 0;
  T_scalar I_lambda;

  while( false == M2_stack.empty() )
   {
    C2_item & I_item = M2_stack.back();

    if( true == I_item.M_used )
     {
      M2_stack.pop_back();
      continue;
     }

    I_item.M_used = true;

    T_interval I_box = I_item.M_struct.F_box();

    std::tuple< unsigned, T_scalar, unsigned, T_scalar > I_intersect;

    if( false == ::math::geometry::interval::intersect( I_intersect, I_box, {P_ray.M_origin, P_ray.M_direction}, Is_epsilon ) )
     {
      continue;
     }

    T_coord I_size; ::math::linear::vector::subtraction( I_size, I_box.F_lo(), I_box.F_i() );

    if( std::min( {I_size[0], I_size[1], I_size[2]  } ) < TODO_NEKA_MALA_VREDNOST )
     { // if small enough for hit test
      T_coord p0, pX, pY;
      T2_plane I_plane( p0, pX, pY )

      if( false == ::intersect( I_lambda, I_plane, I_ray ) )
       {
        continue;
       }
      if( P_lambda < I_lambda )
       {
        continue;
       }

      //T_UV I_center; ::math::linear::vector::median( I_item.M_struct.F_lo(), I_item.M_struct.F_hi() );

      T_coord I_point = P_ray.M_origin + I_lambda * P_ray.M_direction - I_plane.M_pivot;
      T_scalar I_u =  ::math::linear::vector::dot( I_plane.M_base[0], I_plane.M_base[0] );
      T_scalar I_v =  ::math::linear::vector::dot( I_plane.M_base[1], I_plane.M_base[1] );

      I_u = ::math::linear::vector::dot( I_plane.M_base[0], I_point ) / I_u;
      I_v = ::math::linear::vector::dot( I_plane.M_base[1], I_point ) / I_v;

      if(   ( I_u < 0 ) || ( T_scalar( 1 ) < I_u )
          ||( I_v < 0 ) || ( T_scalar( 1 ) < I_v )
       )
       {
        continue;
       }

      I_intersect.M_hit = true;
      I_intersect.M_lambda = I_lambda;
      I_intersect.M_parameter[0] = I_item.M_interval.F_lo()[0] + I_u * ( I_item.M_interval.F_hi()[0] - I_item.M_interval.F_lo()[0] );
      I_intersect.M_parameter[1] = I_item.M_interval.F_lo()[1] + I_v * ( I_item.M_interval.F_hi()[1] - I_item.M_interval.F_lo()[1] );

      P_lambda = I_lambda;
      continue;
     }

     M2_stack.resize( M2_stack.size() + 4 );
     { // Big one. Then divide.
      C2_item & I_item = M2_stack[ M2_stack.size() - 5 ];
      T_struct I_fragment[4];
      Fs_split( I_fragment, I_item.M_struct );

      for( T_size I_index=0; I_index < 4; ++I_index )
       {
        C2_item & I_sub = M2_stack[ M2_stack.size() - I_index ];

        I_sub.M_used = false;

        I_sub.M_struct = I_fragment[I_index];

        I_sub.M_interval.F_lo()[0] = I_item.M_interval.F_lo()[0] + I_fragment[I_index].M_parameter[0][0].F_lo()[0] * ( I_item.M_interval.F_hi()[0] - I_item.M_interval.F_lo()[0] );
        I_sub.M_interval.F_lo()[1] = I_item.M_interval.F_lo()[1] + I_fragment[I_index].M_parameter[0][0].F_lo()[1] * ( I_item.M_interval.F_hi()[1] - I_item.M_interval.F_lo()[1] );
        I_sub.M_interval.F_hi()[0] = I_item.M_interval.F_lo()[0] + I_fragment[I_index].M_parameter[0][0].F_hi()[0] * ( I_item.M_interval.F_hi()[0] - I_item.M_interval.F_lo()[0] );
        I_sub.M_interval.F_hi()[1] = I_item.M_interval.F_lo()[1] + I_fragment[I_index].M_parameter[0][0].F_hi()[1] * ( I_item.M_interval.F_hi()[1] - I_item.M_interval.F_lo()[1] );
       }

     }

   }

  if( true == I_intersect.M_hit )
   {
    P_lambda = I_intersect.M_lambda;
   }

  return I_intersect.M_hit;
 }


 void GC_bezier::Fv_normal
  (
    T_coord           & P_normal
   ,T_coord      const& P_point
   ,T_state  const& P_intersect
  )const
  {
   C2_state const& I_intersect = P_intersect.F_content<C2_state>();
   T2_plane I_plane;
   T2_tangent::Fs_calc( M2_struct, I_intersect.M_parameter, I_plane );
   P_normal = I_plane.M_normal;
  }


 typename GC_bezier::T_location
  GC_bezier::Fv_inside
  (
   T_coord const& P_point
  )const
  {
   //C2_state &I_intersect = P_intersect.F_content<C2_state>();
   return En_out;
  }


 typename GC_bezier::T_scalar
 GC_bezier::Fv_distance( T_coord const& P_point )const
  {

   return -1;
  }


 bool GC_bezier::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const&P_intersect )const
  {
   C2_state const &I_intersect = P_intersect.F_content<C2_state>();
   P_uvw[0] = I_intersect.M_parameter[0];
   P_uvw[1] = I_intersect.M_parameter[1];
   P_uvw[2] = 0;
   return true;
  }


 void
 GC_bezier::Fv_reset( T_state &P_intersect )const
  {
   C2_state &I_intersect = P_intersect.F_content<C2_state>();
   I_intersect.M_hit = false;
   I_intersect.M_parameter[0] = -1;
   I_intersect.M_parameter[1] = -1;
   return;
  }


 typename GC_bezier::T_size
 GC_bezier::Fv_weight( )const
  {
   return sizeof( C2_state );
  }

/*
point splitBezier(point P[4], float t, point P1[4], point P2[4])
{
    // compute first tree points along main segments P1-P2, P2-P3 and P3-P4
    point P12 = (1 - t) * P[0] + t * P[1];
    point P23 = (1 - t) * P[1] + t * P[2];
    point P34 = (1 - t) * P[2] + t * P[3];
    // compute two points along segments P1P2-P2P3 and P2P3-P3P4
    point P1223 = (1 - t) * P12 + t * P23;
    point P2334 = (1 - t) * P23 + t * P34;
    // finally compute P
    point P = (1 - t) * P1223 + t * P2334;
    P1[0] = P[0], P1[1] = P12, P1[2] = P1223, P1[3] = P;
    P2[0] = P, P2[1] = P2334, P2[2] = P34, P3[3] = P4;
}

Vec3f evalBezierCurve(const Vec3f *P, const float &t)
{
    float b0 = (1 - t) * (1 - t) * (1 - t);
    float b1 = 3 * t * (1 - t) * (1 - t);
    float b2 = 3 * t * t * (1 - t);
    float b3 = t * t * t;
    return P[0] * b0 + P[1] * b1 + P[2] * b2 + P[3] * b3;
}

Vec3f evalBezierPatch(const Vec3f *controlPoints, const float &u, const float &v)
{
    Vec3f uCurve[4];
    for (int i = 0; i < 4; ++i) uCurve[i] = evalBezierCurve(controlPoints + 4 * i, u);
    return evalBezierCurve(uCurve, v);
}
point evaluateBezierSurface(point P[16], float u, float v)
{
    point Pu[4];
    // compute 4 control points along u direction
    for (int i = 0; i < 4; ++i) {
       point curveP[4];
       curveP[0] = P[i * 4];
       curveP[1] = P[i * 4 + 1];
       curveP[2] = P[i * 4 + 2];
       curveP[2] = P[i * 4 + 3];
       Pu[i] = evalBezierCurve(curveP, u);
    }
    // compute final position on the surface using v
    return evalBezierCurve(Pu, v);
}*/