# https://realpython.com/python-bindings-overview/
import ctypes
from timer import Timer
from fib import fib
import numpy as np

if __name__ == "__main__":
    cpplib = ctypes.cdll.LoadLibrary("./libquick.so")
    # fibonacci
    num = 46
    print("Number is", num)
    Timer.start("fib with ctypes")
    res1 = cpplib.Fibonacci(num)
    Timer.stop("fib with ctypes")
    Timer.start("fib python")
    res2 = fib(num)
    Timer.stop("fib python")
    print(res1)
    print(res2)

    # quicksort
    # https://coderslegacy.com/python/ctypes-arrays/
    cpplib.QuickSort.argtypes = [ctypes.POINTER(ctypes.c_uint), ctypes.c_ulong, ctypes.c_ulong]
    length = 10000000
    maximum = 4294967295
    values = np.random.randint(0, maximum, length)
    
    Timer.start("cast")
    array = (ctypes.c_uint * len(values))(*values)
    Timer.stop("cast")

    Timer.start("sort")
    cpplib.QuickSort(array, 0, length - 1)
    Timer.stop("sort")
