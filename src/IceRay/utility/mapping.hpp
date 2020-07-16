#ifndef Dh_DDMRM_Iceray_utility_mapping_HPP_
 #define Dh_DDMRM_Iceray_utility_mapping_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_identity
 // GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2cylindric
 // GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2spherical
 // GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cylindric2cartesian
 // GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cylindric2spherical



#include "IceRay/type/math/coord.hpp"
#include "IceRay/type/math/affine.hpp"
#include "IceRay/type/math/homography.hpp"
#include "math/geometry/geometry.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_mapping
        {

         class GC_identity
          {
           public:
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
            T_coord   operator()( T_coord const& P_point )const
             {
              return P_point;
             }
          };

         class GC_translate
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;

             GC_translate( T_coord const& P_move = T_coord{ 0, 0, 0 } )
              : M_move( P_move )
              {
              }
             T_coord   operator()( T_coord const& P_point )const
              {
               T_coord Ir_result;
               ::math::linear::vector::addition( Ir_result, M_move, P_point );
               return Ir_result;
              }
           public:
             T_coord M_move;
          };

         class GC_affine
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar            T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar   T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar  T_affine;

           public:
             GC_affine( T_affine const& P_affine =  T_affine{} )
              :M_affine( P_affine )
              {
               M_affine = ::math::linear::affine::id<T_scalar,3>();
              }
             T_coord   operator()( T_coord const& P_point )const
              {
               T_coord Ir_result;
               ::math::linear::affine::transform( Ir_result, M_affine, P_point );
               return P_point;
              }
           public:
             T_affine M_affine;
          };

         class GC_homography
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                  T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar         T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_homography::GT_homography T_homography;

             GC_homography( T_homography const& P_homography = T_homography{} )
              :M_homography( P_homography )
              { 
               //::math::linear::matrix::id<T_scalar,3>()
              }

             T_coord   operator()( T_coord const& P_point )const
              {
               T_coord Ir_result;
               ::math::linear::homography::transform( Ir_result, M_homography, P_point );
               return P_point;
              }
           public:
             T_homography M_homography;
          };


         class GC_cartesian2cylindric
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const& P_point )const
              {
               return ::math::geometry::cartesian2cylindric( P_point );
              }
          };

         class GC_cartesian2spherical
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               return  ::math::geometry::cartesian2spherical( P_point );
              }
          };

         class GC_cylindric2cartesian
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               return  ::math::geometry::cylindric2cartesian( P_point );
              }
          };

         class GC_cylindric2spherical
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               return  ::math::geometry::cylindric2spherical( P_point );
              }
          };

         class GC_spherical2cartesian
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               return  ::math::geometry::spherical2cartesian( P_point );
              }
          };

         class GC_spherical2cylindric
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               return  ::math::geometry::spherical2cylindric( P_point );
              }
          };

         class GC_euclid2max
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar            T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar   T_coord;

           public:
             T_coord   operator()( T_coord const& P_point )const
              {
               T_coord Ir_result;
               T_scalar I_length = ::math::linear::vector::length( P_point );
               T_scalar I_max = std::max<T_scalar>( std::max<T_scalar>( fabs( P_point[0]), fabs( P_point[1] ) ), fabs( P_point[2] ) );
               ::math::linear::vector::scale( Ir_result, ( I_length / I_max ), P_point );
               return Ir_result;
              }
          };

         class GC_max2euclid
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar            T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar   T_coord;

           public:
             T_coord   operator()( T_coord const& P_point )const
              {
               T_coord Ir_result;
               T_scalar   I_length = ::math::linear::vector::dominant( P_point ).second;
               ::math::linear::vector::length( Ir_result, P_point, I_length );
               return Ir_result;
              }
          };

         class GC_cartesian2tablecloth //?? TODO fisheye
          {
           public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          T_scalar;
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;

            T_coord   operator()( T_coord const& P_point )const
             {
              T_coord Ir_result;
              static T_scalar Is_M_1_2PI = T_scalar( 1 ) / ( 4 * acos( T_scalar(0) ) );
              static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

              T_scalar I_length = ::math::linear::vector::length( P_point );

              if( ( -Is_epsilon < I_length ) && ( I_length < Is_epsilon ) )
               {
                Ir_result[0] = 0;
                Ir_result[1] = 0;
                Ir_result[2] = 0;

                return Ir_result;
               }

              T_scalar x =  P_point[1];
              T_scalar y = -P_point[0];
              T_scalar z =  P_point[2];

              T_scalar r = ( 0.25 - Is_M_1_2PI * asin( z / I_length ) ) /sqrt( x * x + y * y );

              Ir_result[0] = r * x + T_scalar( 0.5 );
              Ir_result[1] = r * y + T_scalar( 0.5 );
              Ir_result[2] = I_length/ T_scalar( 1 );

              return Ir_result;
             }
          };

         class GC_cartesian2torus
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;

             T_coord   operator()( T_coord const&P_point )const
              {
               static T_scalar Is_M_1_2PI = T_scalar(1)/(4*acos( T_scalar(0) ));

               T_scalar llen = sqrt(P_point[0]*P_point[0]+P_point[1]*P_point[1]);

               T_scalar t = llen - T_scalar( 1 );

               T_coord Ir_result;

               Ir_result[0] = atan2( P_point[1], P_point[0] ) *Is_M_1_2PI + T_scalar( 0.5 );
               Ir_result[1] = atan2( P_point[2],          t ) *Is_M_1_2PI + T_scalar( 0.5 );
               Ir_result[2] = sqrt( t*t+ P_point[2] * P_point[2] );

               return Ir_result;
              }
          };

         class GC_cartesian2woodX
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               T_coord Ir_result;
               Ir_result[0] = atan2( P_point[2], P_point[1] );
               Ir_result[1] = P_point[0];
               Ir_result[2] = sqrt(P_point[1]*P_point[1]  + P_point[2]*P_point[2] );

               return Ir_result;
              }
          };

         class GC_cartesian2woodY
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               T_coord Ir_result;
               Ir_result[0] = atan2( P_point[2], -P_point[0] );
               Ir_result[1] = P_point[1];
               Ir_result[2] = sqrt(P_point[0]*P_point[0]  + P_point[2]*P_point[2] );

               return Ir_result;
              }
          };

         class GC_cartesian2woodZ
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             T_coord   operator()( T_coord const&P_point )const
              {
               T_coord Ir_result;

               Ir_result[0] = atan2( P_point[1], P_point[0] );
               Ir_result[1] = P_point[2];
               Ir_result[2] = sqrt(P_point[0]*P_point[0]  + P_point[1]*P_point[1] );

               return Ir_result;
              }
          };

         class GC_cartesian2fisheye
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord2D;

            T_coord   operator()( T_coord const& P_point )const
             {
              T_coord2D I_uv;
              I_uv[0] = P_point[0];
              I_uv[1] = P_point[1];

              T_scalar I_angle = - atan2( I_uv[1], I_uv[0] );
              T_scalar I_len   = ::math::linear::vector::length( I_uv );

              T_coord Ir_result;
              Ir_result[0] =  cos( I_angle ) * sin( I_len );
              Ir_result[1] =  cos( I_len );
              Ir_result[2] = -sin( I_angle ) * sin( I_len );

              ::math::linear::vector::scale( Ir_result, P_point[3] );

              return Ir_result;
             }
          };

         /*
           6|5|6
          --+-+-
           2|1|3
          --+-+-
           6|4|6
         */
         class GC_cartesian2package //!< Box package //TODO
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;

            T_coord   operator()( T_coord const& P_point )const
             { // map [0,1]x[0,1] -> box wrap
              static T_scalar Is_side = sqrt( T_scalar( 1 ) / T_scalar( 24 ) );
              T_coord Ir_result;

              //int x_side=0;
              //int y_side=0;
              //switch( y_side*2 + x_side )
              // {
              //  case( 0 ): break;
              // }

              return Ir_result;
             }
          };

        }
      }
    }
  }

#endif
