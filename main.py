"""This file shows examples of how you'd import the built native library."""

from __future__ import print_function

from native import native_function, python_module


def main():
    print("Calling native function...")
    print(native_function())
    print("-" * 80)
    print("Calling helper function from binding module...")
    print(python_module.some_helper())


if __name__ == '__main__':
    main()