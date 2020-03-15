#include <string>


namespace
{ // Avoid cluttering the global namespace.

  // A couple of simple C++ functions that we want to expose to Python.
  std::string greet() { return "hello, world"; }
  int square(int number) { return number * number; }
}

#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(getting_started1)
{
    // Add regular functions to the module.
    boost::python::def("greet", greet);
    boost::python::def("square", square);
}



//     >>> import getting_started1
//     >>> print getting_started1.greet()
//     hello, world
//     >>> number = 11
//     >>> print number, '*', number, '=', getting_started1.square(number)
//     11 * 11 = 121