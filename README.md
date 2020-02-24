# Mini boost-python CMake project

A simple project skeleton which can build native C++ code using CMake and boost-python and pass NumPy arrays back and forth. I wrote this in Feb 2020 to teach myself the basics of boost-python.

The most key elements are in `native/CMakeLists.txt` and `native/__init__.py`.

There are probably better ways of organizing the code (cf. the Pytorch source code, for instance), but this should work OK for smaller projects.
