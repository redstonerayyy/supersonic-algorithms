#!python
#cython: language_level=3
# http://docs.cython.org/en/latest/src/tutorial/numpy.html
# http://docs.cython.org/en/latest/src/tutorial/cython_tutorial.html

# cython and numpy stuff
import cython

import numpy as np
cimport numpy as np # additional informaton
np.import_array() # necessary

DTYPE = np.int_ # set array data type
ctypedef np.int_t DTYPE_t # typedef for compiling
cimport cython
# @cython.boundscheck(False) # turn off bounds-checking for entire function
# @cython.wraparound(False)  # turn off negative index wrapping for entire function
# use it for functions

import random
from timer import Timer

# quicksort implementation
# partition
# no effect, because it does not occur i presume
@cython.boundscheck(False) # turn off bounds-checking for entire function
@cython.wraparound(False)  # turn off negative index wrapping for entire function
def hoare_partition(np.ndarray[DTYPE_t] array_, int start, int end):
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
# no effect, because it does not occur i presume
@cython.boundscheck(False) # turn off bounds-checking for entire function
@cython.wraparound(False)  # turn off negative index wrapping for entire function
def quicksort(np.ndarray[DTYPE_t] array_, int start, int end):
	cdef DTYPE_t crossing
	if start >= 0 and end >= 0 and start < end:
		crossing = hoare_partition(array_, start, end)

		quicksort(array_, start, crossing)
		quicksort(array_, crossing + 1, end)


# bench
def quicksort_full_optimization():
	# liste = [random.randint(0, 4294967295) for i in range(10000000)]
	cdef np.ndarray[DTYPE_t] liste = np.random.randint(0, 4294967295, 10000000)
	Timer.start("quicksort_full_optimization")
	quicksort(liste, 0, len(liste) - 1)
	Timer.stop("quicksort_full_optimization")