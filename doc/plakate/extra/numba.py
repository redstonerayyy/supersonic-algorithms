from numba import jit

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
		
		temp = array_[i]
		array_[i] = array_[j]
		array_[j] = temp

@jit(nopython=True)
def quicksort_numba(array_, start, end):
	if start >= 0 and end >= 0 and start < end:
		crossing = hoare_partition(array_, start, end)

		quicksort_numba(array_, start, crossing)
		quicksort_numba(array_, crossing + 1, end)
