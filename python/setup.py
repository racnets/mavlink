#!/usr/bin/env python

"""
setup.py file for SWIG-based mavlink module
"""

from distutils.core import setup, Extension


mavlink_module = Extension('_mavlink',
                           sources=['mavlink_wrap.c', 'mavlink.c'],
                           )

setup (name = 'mavlink',
       version = '0.1',
       author      = "Oswald Berthold",
       description = """Simple swig mavlink module""",
       ext_modules = [mavlink_module],
       py_modules = ["mavlink"],
       )

