import generators
from timer import Timer
import os
import numpy as np
from numpy.random import MT19937, Generator

# bench
print(os.path.basename(__file__))
Timer.start("gen_numpy")
liste = np.random.randint(0, 4294967295, generators.tenmillion)
Timer.stop("gen_numpy")

Timer.start("gen_numpy for nparray.sort()")
liste_zwei = np.random.randint(0, 4294967295, generators.tenmillion)
Timer.stop("gen_numpy for nparray.sort()")

Timer.start("gen_numpy new")
rng = Generator(MT19937(12345))
rints = rng.integers(low=0, high=4294967295, size=generators.tenmillion)
Timer.stop("gen_numpy new")

Timer.start("standard list.sort() with normal numpy")
liste.sort()
Timer.stop("standard list.sort() with normal numpy")

Timer.start("ndarray.sort()")
liste_zwei = np.sort(liste_zwei)
Timer.stop("ndarray.sort()")

Timer.start("standard list.sort() with new numpy")
rints.sort()
Timer.stop("standard list.sort() with new numpy")

