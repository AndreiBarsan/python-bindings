"""This file shows examples of how you'd import the built native library."""
from __future__ import print_function

import numpy as np

from native import native_function, native_numpy_function, python_module


def main():
    print("Calling native function...")
    print(native_function())
    print("-" * 80)
    print("Calling helper function from binding module...")
    print(python_module.some_helper())
    print("-" * 80)

    np_array = np.ones((5, 5))
    print(f"(Python) Calling native module with np array of shape: ({np_array.shape})")
    modified = native_numpy_function(np_array)
    print(f"(Python) Resulting shape: {modified.shape}")


if __name__ == '__main__':
    main()