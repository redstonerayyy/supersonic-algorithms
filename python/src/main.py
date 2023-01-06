# file to bench all the algorithms

from numbanumpy.timer import Timer
from subprocess import run
import os

if __name__ == "__main__":
    # run files
    Timer.start("total time")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/generation_lists.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/standard_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/standard_sort_numpy_variations.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/quicksort_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/quicksort_numba_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/quicksort_numba_counters_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/recursive_fibonacci.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/numbanumpy/recursive_fibonacci_numba.py"])
    print("")
    Timer.stop("total time")
