#include <cmath>

//#include <boost/core/noncopyable.hpp>
#include <boost/noncopyable.hpp>
#include <boost/python.hpp>

#define MAKE_SUBMODULE(DP_name)

/*
#define MAKE_SUBMODULE(DP_name)                                                    \
  boost::python::object       DI_subscopeObject_##DP_name;                         \
   {                                                                               \
    using namespace boost::python;                                                 \
    auto        DI_name_object    = scope().attr("__name__") + "." #DP_name;       \
    std::string DI_name_string = extract<std::string>( DI_name_object );           \
    auto        DI_submodule = PyImport_AddModule( DI_name_string.c_str() );       \
    auto        DI_handle = handle<>( borrowed( DI_submodule ) );                  \
    DI_subscopeObject_##DP_name = object( DI_handle );                             \
    scope().attr( DI_name_string.c_str() ) = DI_subscopeObject_##DP_name;          \
   }                                                                               \
  boost::python::scope DP_scope_##DP_name           = DI_subscopeObject_##DP_name

*/
