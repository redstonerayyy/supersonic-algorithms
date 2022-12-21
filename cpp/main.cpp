#include <iostream>
#include <vector>
#include "src/generation_lists.hpp"
#include "src/tests.hpp"
#include "src/timer.hpp"
#include "src/funcs.hpp"

int main(){
    std::cout << "test" << std::endl;
    std::vector<unsigned int> numbers = gen(hundredmillion, 4294967295);
    Timer::start("standard sort");
    standard_sort(numbers.begin(), numbers.end());
    Timer::stop("standard sort");
    Timer::start("radixsort");
    RadixSort(numbers);
    Timer::stop("radixsort");
    Timer::start("radixsort fast");
    RadixSortFast(numbers);
    Timer::stop("radixsort fast");
}
