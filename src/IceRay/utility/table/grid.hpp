#ifndef Dh_DDMRM_Iceray_utility_table_grid_HPP_
 #define Dh_DDMRM_Iceray_utility_table_grid_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_grid

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"

#include <iostream>
#include <iomanip>

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_table
        {

         class GC_grid
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

           public:
             explicit GC_grid( T_size const& P_size = 10 )
              {
               F_init( P_size );
              }
           public:
             bool F_init( T_size const& P_size )
              {
               T_scalar I_epsilon = 0.000001;
               M2_size.clear();
               M2_radius.clear();
               M2_point.clear();

               T_size I_grid = 2*( P_size / 2 ) +1;
               T_scalar I_perimeter = I_grid/2 - 2;
               M2_point.reserve( I_grid * I_grid );

               for( T_size I_v =0; I_v < I_grid; ++ I_v )
               for( T_size I_u =0; I_u < I_grid; ++ I_u )
                {
                 T_coord2D I_spot;
                 I_spot[0] = T_scalar( I_u ) - T_scalar( I_grid /2 );
                 I_spot[1] = T_scalar( I_v ) - T_scalar( I_grid /2 );

                 if( I_perimeter < ::math::linear::vector::length( I_spot ) )
                  {
                   continue;
                  }
                 M2_point.push_back( I_spot );
                }

               std::sort
                 (
                   M2_point.begin(),
                   M2_point.end(),
                   [](auto const& a, auto const& b)
                    {
                     return ::math::linear::vector::dot(a,a) < ::math::linear::vector::dot(b,b);
                    }
                );

               // TODO epsilon

               M2_size.push_back( 0 );
               M2_radius.push_back( 0 );
               for( auto const& I_spot: M2_point )
                {
                 auto I_radius = ::math::linear::vector::length( I_spot );
                 if( I_radius < M2_radius.back() + I_epsilon )
                  {
                   ++M2_size.back();
                   continue;
                  }
                 M2_size.push_back( 1+M2_size.back() );
                 M2_radius.push_back( I_radius );
                 //std::cout<< M2_size[ M2_size.size() -2 ] << ", ";
                }
               //std::cout<< std::endl << "Max grid size: " << M2_size.size() << std::endl;
               return true;
              }

           public:
             std::vector<T_size> const& F_size()const{ return M2_size; }
           private:
             std::vector<T_size>    M2_size;
           public:
             std::vector<T_scalar> const& F_radius()const{ return M2_radius; }
           private:
             std::vector<T_scalar>  M2_radius;
           public:
             std::vector<T_coord2D> const& F_spot()const{ return M2_point; }
           private:
             std::vector<T_coord2D> M2_point;

          };

        }
      }
    }
  }
#endif
