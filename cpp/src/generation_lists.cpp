#include "gen.hpp"
#include <random>
#include <vector>

std::vector<unsigned int> gen(unsigned int length){
    std::random_device dev; // get random seed
    std::mt19937 rng(dev()); // can set seed here
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 4294967295); // range

    std::vector<unsigned int> numbers;
    for(int i = 0; i < length; ++i){
        numbers.emplace_back(dist(rng));
    }

    return numbers;
}
