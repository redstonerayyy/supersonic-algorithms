#include <iostream>
#include <vector>
#include "src/generation_lists.hpp"
#include "src/standard_sort.hpp"
#include "src/timer.hpp"
#include "src/funcs.hpp"

int main(){
    unsigned int maximum = 4294967295; //maxiumum of unsigned int: 4294967295
    // 1.
    std::vector<unsigned int> numbers1 = gen(tenmillion, maximum);
    Timer::start("standard sort");
    standard_sort(numbers1.begin(), numbers1.end());
    Timer::stop("standard sort");
    // 2.
    std::vector<unsigned int> numbers2 = gen(tenmillion, maximum);
    Timer::start("radixsort");
    RadixSort(numbers2);
    Timer::stop("radixsort");
    // 3.
    std::vector<unsigned int> numbers3 = gen(tenmillion, maximum);
    Timer::start("radixsort faster");
    RadixSortFast(numbers3);
    Timer::stop("radixsort faster");
}
