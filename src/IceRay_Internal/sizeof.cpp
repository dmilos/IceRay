
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


std::string print_system_sizeof( )
 {
  std::stringstream ss;
  ss << "<table border=\"1\" cellspacing=\"0\" cellpadding=\"2\" >" << std::endl;

  ss << "<tr><td> Type          </td> <td> Size</td> </tr> "<< std::endl;

  ss << "<tr><td> char          </td> <td> "<< sizeof( char           ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> char          </td> <td> "<< sizeof( unsigned char  ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> wchar_t       </td> <td> "<< sizeof( wchar_t        ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> wchar_t       </td> <td> "<< sizeof( wint_t         ) << "</td> </tr> " << std::endl;

  ss << "<tr><td> std::int8_t   </td> <td> "<< sizeof( std::int8_t    ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> std::int16_t  </td> <td> "<< sizeof( std::int16_t   ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> std::int32_t  </td> <td> "<< sizeof( std::int32_t   ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> std::int64_t  </td> <td> "<< sizeof( std::int64_t   ) << "</td> </tr> " << std::endl;

  ss << "<tr><td> std::uint8_t  </td> <td> "<< sizeof( std::uint8_t   ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> std::uint16_t </td> <td> "<< sizeof( std::uint16_t  ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> std::uint32_t </td> <td> "<< sizeof( std::uint32_t  ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> std::uint64_t </td> <td> "<< sizeof( std::uint64_t  ) << "</td> </tr> " << std::endl;

  ss << "<tr><td> float         </td> <td> "<< sizeof( float          ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> double        </td> <td> "<< sizeof( double         ) << "</td> </tr> " << std::endl;
  ss << "<tr><td> long double   </td> <td> "<< sizeof( long double    ) << "</td> </tr> " << std::endl;

  ss << "<tr><td> nullptr_t     </td> <td> "<< sizeof( nullptr_t      )<< "</td> </tr> " << std::endl;
  ss << "<tr><td> void*         </td> <td> "<< sizeof( void*          )<< "</td> </tr> " << std::endl;
  ss << "<tr><td> unsigned      </td> <td> "<< sizeof( short          )<< "</td> </tr> " << std::endl;
  ss << "<tr><td> short         </td> <td> "<< sizeof( unsigned short )<< "</td> </tr> " << std::endl;
  ss << "<tr><td> int           </td> <td> "<< sizeof( int            )<< "</td> </tr> " << std::endl;
  ss << "<tr><td> unsigned      </td> <td> "<< sizeof( unsigned       )<< "</td> </tr> " << std::endl;
  ss << "<tr><td> long          </td> <td> "<< sizeof( long           )<< "</td> </tr> " << std::endl;
  ss << "<tr><td> long long     </td> <td> "<< sizeof( long long      )<< "</td> </tr> " << std::endl;


  ss << "</table>";
  return ss.str();
 }

int main( int argc, char *argv[] )
 {

  std::cout << print_system_sizeof( ) << std::endl;

  return EXIT_SUCCESS;
 }




