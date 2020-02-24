# Mini boost-python CMake project

A simple project skeleton which can build native C++ code using CMake and boost-python and pass NumPy arrays back and forth. I wrote this in Feb 2020 to teach myself the basics of boost-python.

The most key elements are in `native/CMakeLists.txt` and `native/__init__.py`.

There are probably better ways of organizing the code (cf. the Pytorch source code, for instance), but this should work OK for smaller projects.

## Minimal Instructions

0. Install `cmake` (>=2.8) and `libbost-python`, `libboost-numpy` as well as a modern Python with NumPy.
1. Build the native code.
    (You may need to explicily point to the proper Python installation if you're using, e.g., Anaconda and the build fails or the code crashes (pass `-DPYTHON_EXECUTABLE=... -DPYTHON_INCLUDE_DIR=... -DPYTHON_LIBRARY=...` to `cmake`).)
    ```bash
    mkdir build && cd $_ && cmake .. 
    ```
2. From the project root, run `main.py` with the same Python you built against. You should see something like:
```
Calling native function...
Hello from C++
13
--------------------------------------------------------------------------------
Calling helper function from binding module...
Hello, I'm a Python helper...
Hello from C++
13
--------------------------------------------------------------------------------
(Python) Calling native module with np array of shape: ((5, 5))
(C++) Old shape: [5, 5]
(C++) Dtype:     float64
(C++) New shape: [25, 1]
(Python) Resulting shape: (25, 1)
```
This means the code is now able to pass arrays back and forth between Python and C++!