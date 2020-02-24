// This file contains the Python bindings.
// It shouldn't contain other logic/helpers; those should go in other places, since it's easy to just link against
// anything in the final '*.so' containing the Python bindings.

#include <iostream>
#include <string>

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

namespace p = boost::python;
namespace np = boost::python::numpy;

namespace {
    using namespace std;

    /// Helper for writing a vector to a stream, like stdout.
    template<typename T>
    ostream &operator<<(ostream &out, const vector<T> &v) {
        out << "[";
        for (int i = 0; i < v.size(); ++i) {
            out << v[i];
            if (i < v.size() - 1) {
                out << ", ";
            }
        }
        out << "]";
    }

    vector<int> get_shape(const np::ndarray &array) {
        vector<int> dims;
        const int nd = array.get_nd();
        for (int i = 0; i < nd; ++i) {
            dims.push_back(array.shape(i));
        }
        return dims;
    }
}

namespace bindings {
    using namespace std;

    int native_function() {
        cout << "Hello from C++" << endl;
        return 13;
    }

    np::ndarray native_numpy_function(np::ndarray &array) {
        cout << "(C++) Old shape: " << get_shape(array) << "\n";
        cout << "(C++) Dtype:     " << p::extract<const char*>(p::str(array.get_dtype())) << "\n";

        auto flat_array = array.reshape(p::make_tuple(-1, 1));
        cout << "(C++) New shape: " << get_shape(flat_array) << "\n";


        return flat_array;
    }
}

BOOST_PYTHON_MODULE(native) {
    Py_Initialize();
    np::initialize();

    p::def("native_function", bindings::native_function);
    p::def("native_numpy_function", bindings::native_numpy_function);
}

