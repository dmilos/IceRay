#include <iostream>
#include <iomanip>



void InitSystem( void )
 {
  extern int InitInfo( void );
  InitInfo();

#if defined( _MSC_VER  )
  extern void InitSystemWindows( void );
  InitSystemWindows();
#endif

#if defined( __GNUC__  )

#endif

  std::cout << __FILE__ << "-" << __FUNCTION__ << __DATE__ << " - " << __TIME__ << std::endl;
 }


void ShutDownSystem( void )
 {
#if defined( _MSC_VER  )
  extern void ShutDownSystemWindows( void );
  ShutDownSystemWindows();
#endif
 }

#if defined( _MSC_VER  )
#include "./windows_system.cpp"
#endif
