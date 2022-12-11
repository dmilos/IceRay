#ifndef Dh_DDMRM_Iceray_utility_table_structure_HPP_
 #define Dh_DDMRM_Iceray_utility_table_structure_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_structure

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"
#include <fstream>
#include <string>

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_table
        {

         class GC_structure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

           public:
             typedef std::vector<T_size>  T_sizeContainer;
             typedef std::vector<T_scalar>  T_radiusContainer;
             typedef std::vector<T_coord2D>  T_pointContainer;

           void F_compile()
            {
             T_scalar I_epsilon = 0.000001;
             M2_size.clear();
             M2_radius.clear();
             std::sort
              (
                M2_point.begin(),
                M2_point.end(),
                [](auto const& a, auto const& b)
                 {
                  return ::math::linear::vector::dot(a,a) < ::math::linear::vector::dot(b,b);
                 }
              );

             M2_radius.push_back( 0 );
             M2_size.push_back( 0 );
             T_size I_size  = M2_point.size();
             T_size I_rsize = M2_radius.size();

             //auto & output = std::ofstream( "table_" + std::to_string( I_size )+ "-"+ std::to_string(I_rsize) +".svg" );

             //output << "<svg height=\"100\" width=\"100\">" << std::endl;
             for( auto const& I_spot: M2_point )
              {
               //output<< "<circle cx=\"" << I_spot[0] << "\" cy=\"" << I_spot[1] << "\" r=\"0.1\" fill=\"red\" /> " << std::endl;

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
             //output << "</svg>" << std::endl;
             //std::cout<< std::endl << "Max grid size: " << M2_size.size() << std::endl;
            }

           public:
             void F_clear()
              {
               M2_size.clear();
               M2_radius.clear();
               M2_point.clear();
              }
           public:
             T_sizeContainer const& F_size()const{ return M2_size; }
           private:
             T_sizeContainer    M2_size;
           public:
             T_radiusContainer const& F_radius()const{ return M2_radius; }
           private:
             T_radiusContainer  M2_radius;
           public:
             T_pointContainer const& F_spot()const{ return M2_point; }
             T_pointContainer      & F_spot()     { return M2_point; }
           private:
             T_pointContainer M2_point;
          };

        }
      }
    }
  }

#endif
