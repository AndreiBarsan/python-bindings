"""Sample Python code living in the same package as the native bindings."""

from .lib.native import native_function


def some_helper():
    print("Hello, I'm a Python helper...")
    return native_function()
