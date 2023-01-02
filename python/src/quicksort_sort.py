import generators
from timer import Timer
import os
import numpy as np

# quicksort implementation
# swap as utility function
def swap(array_, i1, i2):
	temp = array_[i1]
	array_[i1] = array_[i2]
	array_[i2] = temp

# partition
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
		
		# swap(array_, i, j)
		temp = array_[i]
		array_[i] = array_[j]
		array_[j] = temp

# quicksort
def quicksort(array_, start, end):
	if start >= 0 and end >= 0 and start < end:
		crossing = hoare_partition(array_, start, end)

		quicksort(array_, start, crossing)
		quicksort(array_, crossing + 1, end)


# bench
print(os.path.basename(__file__))
Timer.start("gen_numpy")
liste = np.random.randint(0, 4294967295, generators.onemillion)
Timer.stop("gen_numpy")

Timer.start("custom quicksort")
quicksort(liste, 0, len(liste) - 1)
Timer.stop("custom quicksort")

Timer.start("gen_pythonic")
liste_zwei = generators.gen_pythonic(generators.onemillion)
Timer.stop("gen_pythonic")

Timer.start("custom quicksort with pythonic")
quicksort(liste_zwei, 0, len(liste_zwei) - 1)
Timer.stop("custom quicksort with pythonic")
