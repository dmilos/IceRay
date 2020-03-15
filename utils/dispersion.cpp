#include "z:\work\code\cpp\prj\github\PNM\src\pnm\pnm.hpp"
#include "z:\work\code\cpp\prj\github\math\work\src\math\math.hpp"
#include "z:\work\code\cpp\prj\github\color\work\src\color\color.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

void load_image( std::vector< double >  & image, std::string const& name )
 {
  std::vector< std::uint8_t > data;
  PNM::Info info;

  { std::ifstream( name, std::ios_base::binary ) >> PNM::load( data, info ); }

  image.resize( info.width () * info.height() );

  ::color::rgb<std::uint8_t> *r = reinterpret_cast< ::color::rgb<std::uint8_t> *>( data.data() );
  ::color::gray<double>      *g = reinterpret_cast< ::color::gray<double> *>(      image.data() );

  std::transform( r, r + image.size(), g, []( ::color::rgb<std::uint8_t> const& r ) { return ::color::gray<double>(r); } );

 }

int main( int argc, char *argv[] )
 {
  std::vector< double > left;
  std::vector< double > right;
  load_image( left,  argv[1] );
  load_image( right, argv[2] );

  ::math::statistic::gauss::V1< double, unsigned > g1;
  ::math::statistic::gauss::V2< double, unsigned > g2;

  double summae = 0;

  for( int i=0; i<  left.size(); ++i )
   {
     //if( 0 == left[i])
     // {
     //  continue;
     // }
     g1.push( fabs( left[i] - right[i] ) );
     g2.push( fabs( left[i] - right[i] ) );
     summae += fabs( left[i] - right[i] );

   }

  std::cout << std::setw(20) << std::fixed << 100*summae << " - ";
  std::cout << std::setw(20) << 10000000 * g1.deviation() << " - ";
  std::cout << std::setw(20) << 10000000 * g2.deviation() << " - ";
  std::cout << argv[2] << " - ";

  std::cout <<std::endl;

  return EXIT_SUCCESS;
 }

