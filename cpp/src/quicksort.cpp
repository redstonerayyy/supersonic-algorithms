#include "quicksort.hpp"

#include <vector>
#include <cstdint>

std::uint64_t HoarePartition(std::vector<unsigned int> &vector, std::uint64_t start, std::uint64_t end){
    
}


void QuickSort(std::vector<unsigned int> &vector, std::uint64_t start, std::uint64_t end){
    if ( start >= 0 and end >= 0 and start < end ){
        std::uint64_t crossing = HoarePartition(vector, start, end);

        QuickSort(vector, start, crossing);
        QuickSort(vector, crossing + 1, end);
    }
}
