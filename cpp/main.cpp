#include <iostream>
#include <vector>
#include "src/generation_lists.hpp"
#include "src/standard_sort.hpp"
#include "src/quicksort.hpp"
#include "src/timer.hpp"
#include "src/funcs.hpp"

void radixsort(unsigned int arr[], unsigned long n);
void print(unsigned int arr[], unsigned long n);

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
    std::cout << numbers3.at(0) << " " << numbers3.at(1) << " " << numbers3.at(numbers3.size() - 2) << " " << numbers3.at(numbers3.size() - 1) << "\n";
    // 4.
    std::vector<unsigned int> numbers4 = gen(tenmillion, maximum);
    Timer::start("custom quicksort");
    QuickSort(numbers4, 0, numbers4.size() - 1);
    Timer::stop("custom quicksort");
}
