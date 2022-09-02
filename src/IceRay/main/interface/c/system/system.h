

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
