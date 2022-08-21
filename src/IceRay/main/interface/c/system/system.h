
#ifndef IceRayC__EXPORT
#define IceRayC__EXPORT  extern "C"
#endif

#if defined _MSC_BUILD
#ifndef IceRayC__DECLSPEC
#define IceRayC__DECLSPEC      __declspec( dllexport )
#endif
#else
#ifndef IceRayC__DECLSPEC   /*TODO __attribute__((visibility("default")))*/
#define IceRayC__DECLSPEC
#endif
#endif



////#ifdef IceRay_DLL
//#define IceRayC__DECLSPEC      __declspec( dllexport )
////# else
////#define IceRayC__DECLSPEC      __declspec( dllimport)
////# endif