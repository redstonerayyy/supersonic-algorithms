from setuptools import setup
from Cython.Build import cythonize
import numpy

setup(
    name='Optimized Quicksort',
    ext_modules=cythonize(["quicksort_full_optimization.pyx", "quicksort_with_types.pyx", "quicksort_no_optimization.pyx"]),
    include_dirs=[numpy.get_include()],
    zip_safe=False,
)
