import generators
from timer import Timer
from numba import jit
from numba.typed import List
import os
import random

# quicksort implementation with numba
# swap as utility function
@jit(nopython=True)
def swap(array_, i1, i2):
	temp = array_[i1]
	array_[i1] = array_[i2]
	array_[i2] = temp
	return array_

# partition
@jit(nopython=True)
def hoare_partition(array_, start, end):
	pivot = array_[(start + end) // 2]

	i = start - 1
	j = end + 1

	while True:
		i += 1
		while array_[i] < pivot:
			i += 1

		j -= 1
		while array_[j] > pivot:
			j -= 1

		if i >= j:
			return j
		
		swap(array_, i, j)

# quicksort
@jit(nopython=True)
def quicksort_numba(array_, start, end):
	if start >= 0 and end >= 0 and start < end:
		crossing = hoare_partition(array_, start, end)

		quicksort_numba(array_, start, crossing)
		quicksort_numba(array_, crossing + 1, end)


# bench
print(os.path.basename(__file__))
Timer.start("gen_numpy")
liste = generators.gen_numpy(generators.tenmillion)
Timer.stop("gen_numpy")

Timer.start("custom quicksort with numba")
quicksort_numba(liste, 0, len(liste) - 1)
Timer.stop("custom quicksort with numba")

Timer.start("gen_pythonic with numba.typed list")
typed_a = List([random.randint(0, 4294967295) for x in range(generators.tenmillion)])
Timer.stop("gen_pythonic with numba.typed list")

Timer.start("custom quicksort with numba and pythonic")
quicksort_numba(typed_a, 0, len(typed_a) - 1)
Timer.stop("custom quicksort with numba and pythonic")
