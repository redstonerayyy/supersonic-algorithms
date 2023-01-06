from numba import jit

from timer import Timer
import sys

sys.setrecursionlimit(1000000)

@jit(nopython=True)
def fib(n):
    if n < 2:
        return n
    else:
        return fib(n - 1) + fib(n - 2)

Timer.start("recursive fibonacci with numba")
fib(40)
Timer.stop("recursive fibonacci with numba")
