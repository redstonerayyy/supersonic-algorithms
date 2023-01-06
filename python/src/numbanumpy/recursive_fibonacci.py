from timer import Timer
import sys

sys.setrecursionlimit(1000000)

def fib(n):
    if n < 2:
        return n
    else:
        return fib(n - 1) + fib(n - 2)

Timer.start("recursive fibonacci")
fib(40)
Timer.stop("recursive fibonacci")
