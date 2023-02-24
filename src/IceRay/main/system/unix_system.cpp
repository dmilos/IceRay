#include <iostream>
#include <iomanip>




void InitSystemUnix( void )
 {
  // nothing
 }


void ShutDownSystemUnix( void )
 {
  // nothing
 }

__attribute__((constructor)) void initialize_module(void)
 {
  extern void InitSystem( void );
  InitSystem();
 }
__attribute__((destructor))  void finalize_module(void)
 {
  extern void ShutDownSystem( void );
  ShutDownSystem();
 }

