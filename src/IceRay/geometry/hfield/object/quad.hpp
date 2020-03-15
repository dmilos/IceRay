#ifndef _DDMM_IceRAY_geometry_hfield_object_quad_H_
 #define _DDMM_IceRAY_geometry_hfield_object_quad_H_

#include "math/polynomial/quadric/solve.hpp"

#include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_hfield
        {
         namespace S_object
          {
              
           class GC_quad
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure
            {

             virtual bool Fv_intersect( T_scalar &P_lambda, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_ray const& P_ray )const
              {
               static T_scalar Is_epsilon = 1e-12;
               T_scalar _a, _b, _c, tx, ty, t;
             
               tx =  P_01 - P_00;
               ty =  P_10 - P_00;
               t  =  P_11 - P_01 - ( P_10 - P_00 );

               _a = P_ray.M_direction[0] * P_ray.M_direction[1] * t;
               _b = tx * P_ray.M_direction[0]  +  ty * P_ray.M_direction[1] + t*( P_ray.M_direction[0] * P_ray.M_origin[1] + P_ray.M_direction[1] * P_ray.M_origin[0]) - P_ray.M_direction[2];
               _c = P_00 + tx * P_ray.M_origin[0] + ty * P_ray.M_origin[1] + t * P_ray.M_origin[0] * P_ray.M_origin[1]  -  P_ray.M_origin[2];

              T_scalar I_lambda = -1.0;

               switch( ::math::polynomial::quadric::solve::general( tx, ty, {_c, _b, _a}, Is_epsilon ) )
                {
                 case( 2 ):
                   if( Is_epsilon < ty )
                    {
                     _a = P_ray.M_origin[0]  +  ty * P_ray.M_direction[0];
                     _b = P_ray.M_origin[1]  +  ty * P_ray.M_direction[1];

                     if( ( 0 < _a ) && ( _a < 1 ) && ( 0 < _b ) && ( _b < 1 ) )
                      {
                       I_lambda = ty;
                      }
                     
                    }
                 case( 1 ):
                   if( Is_epsilon < tx )
                    {
                     _a = P_ray.M_origin[0]  +  tx * P_ray.M_direction[0];
                     _b = P_ray.M_origin[1]  +  tx * P_ray.M_direction[1];

                     if( ( 0 < _a ) && ( _a < 1 ) && ( 0 < _b ) && ( _b < 1 ) )
                      {
                       I_lambda = tx;
                      }
                    }
                  break;
                 default: ;
                }

               if( ( Is_epsilon < I_lambda ) && (  I_lambda < P_lambda ) )
                {
                 P_lambda = I_lambda;

                 return true;
                }

               return false;
              }


             virtual void Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
              {
               P_height =  P_00 + (P_01 - P_00) * P_x + (P_10 - P_00) * P_y + ( P_11 - P_01 - ( P_10 - P_00 ) ) * P_x * P_y;
              }

             void  Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
              {
               P_normal[0] =  (P_01 - P_00)  +  P_y * ( P_11 - P_01 - ( P_10 - P_00 ) );
               P_normal[1] =  (P_10 - P_00)  +  P_x * ( P_11 - P_01 - ( P_10 - P_00 ) );
               P_normal[2] =  -1.0;
               ::math::linear::vector::length( P_normal, T_scalar(1) );
              }
            };

          }
        }
      }
    }
  }

#endif