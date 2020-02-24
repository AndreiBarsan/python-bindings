cmake_minimum_required(VERSION 2.8)
project(python_bindings)

set(CMAKE_CXX_STANDARD 17)

# If you are using, e.g., anaconda, make sure to pass PYTHON_EXECUTABLE, PYTHON_INCLUDE_DIR, and PYTHON_LIBRARY to
# cmake. For example: cmake .. '-DPYTHON_EXECUTABLE=$CONDA_ROOT/bin/python
# -DPYTHON_INCLUDE_DIR=$CONDA_ROOT/include/python3.6m/ -DPYTHON_LIBRARY=$CONDA_ROOT/lib'
#
# On my machine, $CONDA_ROOT would look like '/home/andreib/miniconda3/env/ml36' (it's a Python 3.6 environment).
#
find_package(PythonInterp 3.6 REQUIRED EXACT)
find_package(PythonLibs 3.6 REQUIRED EXACT)
# This can be installed on Ubuntu using 'apt-get install libboost-python-dev libboost-numpy-dev'
#find_package(Boost REQUIRED COMPONENTS python36 numpy36)                # Newer cmakes support this cleaner naming.
find_package(Boost REQUIRED COMPONENTS python-py36 numpy3-py36)        # Older cmakes

#
# Bindings for the 'native' C++ module.
#
add_library(native SHARED some_native_lib.cpp)
target_include_directories(native PRIVATE ${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
target_link_libraries(native ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})

# This ensures that
# (1) the output library name isn't prefixed by 'lib' so it's, e.g., 'bindings.so' instead of 'libbindings.so', and
# (2) all CMake auxiliary files stay in their out-of-directory build, while the actual library is placed in the
#     original tree so we can cleanly import it without having to hack the Python path.
set_target_properties(native PROPERTIES PREFIX "" LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

