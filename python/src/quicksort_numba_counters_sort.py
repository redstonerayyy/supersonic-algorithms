import generators
from timer import Timer
from numba import jit
import os
import cProfile

# quicksort implementation with numba
# swap as utility function

partitioncount = 0
quicksortcount = 0

@jit(nopython=True)
def swap(array_, i1, i2):
	temp = array_[i1]
	array_[i1] = array_[i2]
	array_[i2] = temp
	return array_

# partition
def hoare_partition(array_, start, end):
	global partitioncount
	partitioncount += 1
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
def quicksort_numba(array_, start, end):
	global quicksortcount 
	quicksortcount += 1
	if start >= 0 and end >= 0 and start < end:
		crossing = hoare_partition(array_, start, end)

		quicksort_numba(array_, start, crossing)
		quicksort_numba(array_, crossing + 1, end)


liste = generators.gen_numpy(generators.tenmillion)
quicksort_numba(liste, 0, len(liste) - 1)
print(f"Partition called {partitioncount}, Quicksort called {quicksortcount}")