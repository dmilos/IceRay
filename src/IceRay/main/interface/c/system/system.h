
#if defined( _MSC_BUILD )

#ifndef IceRayC__EXPORT
#define IceRayC__EXPORT  extern "C"
#endif

#ifndef IceRayC__DECLSPEC
#define IceRayC__DECLSPEC      __declspec( dllexport )
#endif

#endif

#if defined(__GNUC__) || defined(__GNUG__)

#ifndef IceRayC__EXPORT
#define IceRayC__EXPORT  extern "C"
#endif

#ifndef IceRayC__DECLSPEC
#define IceRayC__DECLSPEC      __attribute__((visibility("default")))
#endif

#endif


#ifndef _0a5f6a6ebb3d43e095aaf8cdc3ae48c1
#define _0a5f6a6ebb3d43e095aaf8cdc3ae48c1

#include <cstddef>

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_System_First( std::size_t P_capacity, char*P_key );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_System_Value( std::size_t P_length, char*P_key,     std::size_t P_capacity, char* P_value );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_System_Next(  std::size_t P_length, char*P_current, std::size_t P_capacity, char* P_next );

#endif
