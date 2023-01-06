package main

import (
	"fmt"
	"math/rand"
	"time"
)

func hoare_partition(array []int, start int, end int) int {
	pivot := array[int((start+end)/2)]

	i := start - 1
	j := start + 1

	for {
		i++
		for array[i] < pivot {
			i++
		}

		j--
		for array[i] < pivot {
			j--
		}

		if i >= j {
			return j
		}

		temp := array[i]
		array[i] = array[j]
		array[j] = temp
	}
}

func quicksort(array []int, start int, end int) {
	if start >= 0 && end >= 0 && start < end {
		crossing := hoare_partition(array, start, end)

		quicksort(array, start, crossing)
		quicksort(array, crossing+1, end)
	}
}

func main() {
	length := 8000000 // 7000000 is working (less than 1GB)
	array := make([]int, 8000000)
	maximum := 4294967295

	for i := 0; i < length; i++ {
		array[i] = rand.Intn(maximum)
	}

	start := time.Now()
	quicksort(array, 0, len(array)-1)
	t := time.Now()
	fmt.Println(t.Sub(start))
	// time.Sleep(10 * time.Second)
}
