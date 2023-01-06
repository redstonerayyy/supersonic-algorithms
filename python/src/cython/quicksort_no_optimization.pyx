#!python
#cython: language_level=3
# http://docs.cython.org/en/latest/src/tutorial/cython_tutorial.html

# cython and numpy stuff
import cython
import numpy as np

import random
from timer import Timer

# quicksort implementation
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
def quicksort_no_optimization():
	# liste = [random.randint(0, 4294967295) for i in range(10000000)]
	liste = np.random.randint(0, 4294967295, 10000000)
	Timer.start("quicksort_with_types")
	quicksort(liste, 0, len(liste) - 1)
	Timer.stop("quicksort_with_types")