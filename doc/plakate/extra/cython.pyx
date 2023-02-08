#!python
#cython: language_level=3

import cython

def hoare_partition(array_, int start, int end):
	pivot = array_[(start + end) // 2]

	cdef int i = start - 1
	cdef int j = end + 1
	cdef long temp # makes it slower sometimes?

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
def quicksort(array_, int start, int end):
	cdef int crossing
	if start >= 0 and end >= 0 and start < end:
		crossing = hoare_partition(array_, start, end)

		quicksort(array_, start, crossing)
		quicksort(array_, crossing + 1, end)
