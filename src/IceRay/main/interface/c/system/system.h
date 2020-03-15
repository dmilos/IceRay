

#ifndef IceRayC__EXPORT
#define IceRayC__EXPORT  extern "C" 
#endif

#ifndef IceRayC__DECLSPEC
#define IceRayC__DECLSPEC      __declspec( dllexport )
#endif


////#ifdef IceRay_DLL
//#define IceRayC__DECLSPEC      __declspec( dllexport )
////# else
////#define IceRayC__DECLSPEC      __declspec( dllimport)
////# endif  