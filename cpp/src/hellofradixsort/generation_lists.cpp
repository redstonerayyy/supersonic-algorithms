#include <random>
#include <vector>

// generate
std::vector<unsigned int> gen(unsigned long length, unsigned int max){
    std::random_device dev; // get random seed
    // std::mt19937 rng(dev());
    std::mt19937 rng(100); // set seed
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, max); // range

    std::vector<unsigned int> numbers;
    numbers.reserve(length);
    for(int i = 0; i < length; ++i){
        numbers.emplace_back(dist(rng));
    }

    return numbers;
}
