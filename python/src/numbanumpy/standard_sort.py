import generators
from timer import Timer
import os

# bench
print(os.path.basename(__file__))

liste = generators.gen_numpy(generators.tenmillion)

Timer.start("standard list.sort() on numpy array")
liste.sort()
Timer.stop("standard list.sort() on numpy array")

liste_zwei = generators.gen_pythonic(generators.tenmillion)

Timer.start("standard list.sort() on python list")
liste_zwei.sort()
Timer.stop("standard list.sort() on python list")
