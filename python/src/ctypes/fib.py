from timer import Timer
import sys
from numba import jit

sys.setrecursionlimit(1000000)

@jit(nopython=True)
def fib(n):
    if n < 2:
        return n
    else:
        return fib(n - 1) + fib(n - 2)

