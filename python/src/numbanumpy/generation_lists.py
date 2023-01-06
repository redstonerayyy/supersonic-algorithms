import generators
from timer import Timer
import os

# bench
print(os.path.basename(__file__))
# pythonic
Timer.start("python list comprehension")
lone = generators.gen_pythonic(generators.tenmillion)
Timer.stop("python list comprehension")

# pythonic + numba
Timer.start("python list comprehension with numba")
ltwo = generators.gen_pythonic_numba(generators.tenmillion)
Timer.stop("python list comprehension with numba")

# numpy
Timer.start("numpy array.random.randint method")
# allocating to a new list/array is faster than to an existing one if it is a python list
lthree = generators.gen_numpy(generators.tenmillion)
Timer.stop("numpy array.random.randint method")

# numpy + numba
Timer.start("numpy array.random.randint method with numba")
lfour = generators.gen_numpy_numba(generators.tenmillion)
Timer.stop("numpy array.random.randint method with numba")

# modern numpy way
Timer.start("numpy modern generator way")
lfive = generators.gen_numpy_modern(generators.tenmillion)
Timer.stop("numpy modern generator way")

# no numba version because of unknown numpy functions
# numba.typed list + numba
# Timer.start("numpy modern generator way with numba")
# leigth = generators.gen_numpy_modern_numba(generators.tenmillion)
# Timer.stop("numpy modern generator way with numba")

# numba.typed list
Timer.start("python list comprehension with conversion to numba.typed list")
lseven = generators.gen_numba_typed(generators.tenmillion)
Timer.stop("python list comprehension with conversion to numba.typed list")

# numba.typed list with numba jit
Timer.start("python list comprehension with conversion to numba.typed list with numba jit")
lseven = generators.gen_numba_typed_numba(generators.tenmillion)
Timer.stop("python list comprehension with conversion to numba.typed list with numba jit")
