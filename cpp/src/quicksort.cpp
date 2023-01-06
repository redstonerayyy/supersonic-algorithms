#include "quicksort.hpp"

#include <vector>
#include <cstdint>

std::uint64_t HoarePartition(std::vector<unsigned int> &vector, std::uint64_t start, std::uint64_t end){
    unsigned int pivot = vector.at( (int)((start + end) / 2) );
    std::uint64_t i = start - 1; // does overflow, but doesn't matter as 1 is added
    std::uint64_t j = end + 1;

    while(true){
        ++i;
        while(vector.at(i) < pivot){
            ++i;
        }

        --j;
        while(vector.at(j) > pivot){
            --j;
        }

        if(i >= j){
            return j;
        }
        
        unsigned int temp = vector.at(i);
        vector.at(i) = vector.at(j);
        vector.at(j) = temp;
    }
}


void QuickSort(std::vector<unsigned int> &vector, std::uint64_t start, std::uint64_t end){
    if ( start >= 0 and end >= 0 and start < end ){
        std::uint64_t crossing = HoarePartition(vector, start, end);

        QuickSort(vector, start, crossing);
        QuickSort(vector, crossing + 1, end);
    }
}
