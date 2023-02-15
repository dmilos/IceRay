#include <map>
#include <string>
#include <cstddef>

typedef std::map<std::string,std::string> InfoContainer;

InfoContainer GI_info;


int InitInfo( )
 {
  GI_info["size-size_t"] = std::to_string( sizeof( std::size_t ) );
  GI_info["size-void*"] = std::to_string( sizeof( void* ) );
  GI_info["__func__"] = __func__ ;
  GI_info["__cplusplus"] = std::to_string(__cplusplus);
  GI_info["__TIME__"] = __TIME__ ;
  GI_info["__DATE__"] = __DATE__ ;
  GI_info["__LINE__"] = std::to_string(__LINE__);
  GI_info["__FILE__"] = __FILE__;

#if defined( _DEBUG  )
  GI_info["_DEBUG"] =  std::to_string( _DEBUG );
#endif

#if defined( _MSC_VER  )
  GI_info["OS"] = "Microsoft";
  GI_info["compiler"] = "MSVC";
  GI_info["_MSC_BUILD"] = std::to_string( _MSC_BUILD );
  GI_info["_MSC_FULL_VER"] = std::to_string( _MSC_FULL_VER );

#if defined( _WIN32  )
  GI_info["_WIN32"] = std::to_string( _WIN32 ) ;
#endif

#if defined( _WIN64  )
  GI_info["_WIN64"] = std::to_string( _WIN64 ) ;
#endif
  GI_info["_MSVC_LANG"] = std::to_string( _MSVC_LANG );
#endif

#if defined( __GNUC__  )
 // TODO
  GI_info["OS"] = "gnu";
  GI_info["__STRICT_ANSI__"] = "__STRICT_ANSI__";
  GI_info["__GNUG__"] = "__GNUG__";
  GI_info["__GNUC_MINOR__"] = "__GNUC_MINOR__";
  GI_info["__GNUC_PATCHLEVEL__"] = "__GNUC_PATCHLEVEL__";
#endif
  return GI_info.size();
 }
