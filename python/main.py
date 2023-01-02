# file to bench all the algorithms

from src.timer import Timer
from subprocess import run
import os

if __name__ == "__main__":
    # run files
    Timer.start("total time")
    run(["python", f"{os.path.dirname(__file__)}/src/generation_lists.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/src/standard_sort_numpy_variations.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/src/standard_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/src/quicksort_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/src/quicksort_numba_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/src/quicksort_numba_counters_sort.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/src/recursive_fibonacci_numba.py"])
    print("")
    run(["python", f"{os.path.dirname(__file__)}/src/recursive_fibonacci.py"])
    print("")
    Timer.stop("total time")
