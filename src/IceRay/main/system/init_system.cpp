#include <iostream>
#include <iomanip>

void InitSystem( void )
 {
  extern void InitSystemWindows( void );
  InitSystemWindows();
  std::cout << __FILE__ << "-" << __FUNCTION__ << __DATE__ << " - " << __TIME__ << std::endl;
 }


void ShutDownSystem( void )
 {
  extern void ShutDownSystemWindows( void );
  ShutDownSystemWindows();
 }
