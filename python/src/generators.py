import random
#random.seed(10) # set seed if desired
import numpy as np
from numba import jit

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
