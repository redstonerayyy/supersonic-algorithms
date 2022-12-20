import generators
from timer import Timer
import os

# bench
print(os.path.basename(__file__))
# pythonic
Timer.start("gen_pythonic")
lone = generators.gen_pythonic(generators.tenmillion)
Timer.stop("gen_pythonic")

# numpy
Timer.start("gen_numpy")
# allocating to a new list/array is faster than to an existing one if it is a python list
ltwo = generators.gen_numpy(generators.tenmillion)
Timer.stop("gen_numpy")

# numpy + numba
Timer.start("gen_numpy_numba")
lthree = generators.gen_numpy_numba(generators.tenmillion)
Timer.stop("gen_numpy_numba")