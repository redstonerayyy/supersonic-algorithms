import generators
from timer import Timer
import os
import numpy as np
from numpy.random import MT19937, Generator

# bench
print(os.path.basename(__file__))

liste = generators.gen_numpy(generators.tenmillion)

Timer.start("standard list.sort() on numpy array")
liste.sort()
Timer.stop("standard list.sort() on numpy array")

liste_zwei = generators.gen_numpy(generators.tenmillion)

Timer.start("ndarray.sort() on numpy array")
liste_zwei = np.sort(liste_zwei)
Timer.stop("ndarray.sort() on numpy array")
