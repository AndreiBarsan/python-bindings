// This file contains the Python bindings.
// It shouldn't contain other logic/helpers; those should go in other places, since it's easy to just link against
// anything in the final '*.so' containing the Python bindings.

#include <iostream>

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>


int native_function() {
    using namespace std;
    cout << "Hello from C++" << endl;
    return 13;
}

BOOST_PYTHON_MODULE(native) {
    namespace p = boost::python;
    namespace np = boost::python::numpy;
    Py_Initialize();
    np::initialize();

    p::def("native_function", native_function);
}

