#include "./structure.hpp"

// /*debug*/ #include <string>
// /*debug*/ #include <fstream>

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_table
       {

        void GC_structure::F_compile()
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
           }
          return;

          //std::cout<< std::endl << "Max grid size: " << M2_size.size() << std::endl;
 
          // /*debug*/ auto & outputSvg = std::ofstream( "table_" + std::to_string( I_size )+ "-"+ std::to_string(I_rsize) +".svg" );
          // /*debug*/ outputSvg << "<svg height=\"100\" width=\"100\">" << std::endl;
          for( auto const& I_spot: M2_point )
           {
            // /*debug*/ outputSvg<< "<circle cx=\"" << I_spot[0] << "\" cy=\"" << I_spot[1] << "\" r=\"0.1\" fill=\"red\" /> " << std::endl;
           }
          // /*debug*/ outputSvg << "</svg>" << std::endl;
          //std::cout<< std::endl << "Max grid size: " << M2_size.size() << std::endl;

          ::math::geometry::direction::fit2D<double>::sample_type sample;
          ::math::statistic::average<double,1>     average;

          double index=0;
          // /*debug*/ auto & outputTxt = std::ofstream( "table_" + std::to_string( I_size )+ "-"+ std::to_string(I_rsize) +".txt" );
          ::math::geometry::direction::fit2D<double>::scalar_type   a,  b ;
          for( std::size_t index=1; index < M2_size.size(); ++index )
           {
            sample.push_back( (double) M2_size[index] );
            average.push( M2_size[index] - M2_size[index-1] );
            ::math::geometry::direction::fit2D<double>::process( a,b, sample );
            // /*debug*/ outputTxt << M2_size[index]<< ", "<< average.value() << "," << "[" << a << ", "<< b <<"] " << std::endl ;
           }
         }

        void GC_structure::F_clear()
         {
          M2_size.clear();
          M2_radius.clear();
          M2_point.clear();
         }

       }
     }
   }
 }