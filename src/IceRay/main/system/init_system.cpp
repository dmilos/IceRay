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
  extern void InitSystemUnix( void );
  InitSystemUnix();
#endif
 }

void ShutDownSystem( void )
 {
#if defined( _MSC_VER  )
  extern void ShutDownSystemWindows( void );
  ShutDownSystemWindows();
#endif

#if defined( __GNUC__  )
  extern void ShutDownSystemUnix( void );
  ShutDownSystemUnix();
#endif

 }

#if defined( _MSC_VER  )
#include "./windows_system.cpp"
#endif

#if defined( __GNUC__  )
#include "./unix_system.cpp"
#endif
