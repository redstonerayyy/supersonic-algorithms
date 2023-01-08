function quicksort(array, start, ending)
    if start >= 0 && ending >= 0 && start < ending
        crossing = hoare_partition(array, start, ending)

        quicksort(array, start, crossing)
        quicksort(array, crossing + 1, ending)
    end
end

function hoare_partition(array, start, ending)
    pivot = array[trunc(UInt32, (start + ending) / 2)]

    i = start - 1
    j = ending + 1

    while true
        i += 1
        while array[i] < pivot
            i += 1
        end

        j -= 1
        while array[j] > pivot
            j -= 1
        end

        if i >= j
            return j
        end

        temp = array[i]
        array[i] = array[j]
        array[j] = temp
    end
end

# does not do much
# precompile(quicksort, ())
# precompile(hoare_partition, ())
using Profile

# gen takes ~0.3s
count = 10000000
array = rand(UInt32, count)

# custom sort takes ~1.2s
# quicksort(array, 1, count)

# std sort takes ~1.1s
sort(array)

# @profile quicksort(array, 1, count)
# Profile.print()