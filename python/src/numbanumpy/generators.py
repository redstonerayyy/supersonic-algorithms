import random
#random.seed(10) # set seed if desired
import numpy as np
from numba import jit
from numpy.random import MT19937, Generator
from numba.typed import List
import random

# constant
tenmillion = 10 ** 7 # 10 millions
onemillion = 10 ** 6 # 1 million

def gen_pythonic(length):
    return [random.randint(0, 4294967295) for i in range(length)]

@jit(nopython=True)
def gen_pythonic_numba(length):
    return [random.randint(0, 4294967295) for i in range(length)]

def gen_numpy(length):
    return np.random.randint(0, 4294967295, length)

@jit(nopython=True)
def gen_numpy_numba(length):
    return np.random.randint(0, 4294967295, length)

def gen_numpy_modern(length):
    rng = Generator(MT19937(12345))
    return rng.integers(low=0, high=4294967295, size=length)

# no numba version because of unknown numpy functions
# @jit(nopython=True)
# def gen_numpy_modern_numba(length):
#     rng = Generator(MT19937(12345))
#     return rng.integers(low=0, high=4294967295, size=length)

def gen_numba_typed(length):
    return List([random.randint(0, 4294967295) for x in range(length)])

@jit(nopython=True)
def gen_numba_typed_numba(length):
    return List([random.randint(0, 4294967295) for x in range(length)])
