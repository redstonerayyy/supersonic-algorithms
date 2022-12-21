#include "generation_lists.hpp"
#include <random>
#include <vector>

// generate
std::vector<unsigned int> gen(unsigned long length, unsigned int max){
    std::random_device dev; // get random seed
    std::mt19937 rng(dev()); // can set seed here
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, max); // range

    std::vector<unsigned int> numbers(length, 0);
    for(int i = 0; i < length; ++i){
        numbers.at(i) = (dist(rng));
    }

    return numbers;
}
