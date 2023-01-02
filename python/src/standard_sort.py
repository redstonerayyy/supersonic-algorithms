import generators
from timer import Timer
import os

# bench
print(os.path.basename(__file__))
Timer.start("gen_numpy")
liste = generators.gen_numpy(generators.tenmillion)
Timer.stop("gen_numpy")

Timer.start("standard list.sort()")
liste.sort()
Timer.stop("standard list.sort()")

Timer.start("gen_pythonic")
liste_zwei = generators.gen_pythonic(generators.tenmillion)
Timer.start("gen_pythonic")

Timer.start("standard list.sort() with pythonic")
liste_zwei.sort()
Timer.stop("standard list.sort() with pythonic")
