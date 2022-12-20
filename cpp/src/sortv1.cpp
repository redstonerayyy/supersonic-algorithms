// clang++ sortv1.cpp -O3 -march=native -o sortv1
#include <random>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<unsigned int> gen(unsigned int length){
    std::random_device dev; // get random seed
    std::mt19937 rng(dev()); // can set seed here
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 4294967295); // range

    std::vector<unsigned int> numbers;
    for(int i = 0; i < length; ++i){
        numbers.push_back(dist(rng));
    }

    return numbers;
}

int main(){
    // length of list to generate and sort
    unsigned int length = 10000000; // 10^7
    
    // generate list of numbers
    std::chrono::_V2::high_resolution_clock::time_point = std::chrono::high_resolution_clock::now();
    std::vector<unsigned int> nums = gen(length);
    auto genend = std::chrono::high_resolution_clock::now();
    auto gendiff = std::chrono::duration_cast<std::chrono::nanoseconds>(genend - genstart);
    auto gendiffmiliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(genend - genstart);
    auto gendiffseconds = std::chrono::duration_cast<std::chrono::seconds>(genend - genstart);

    // sort
    auto sortstart = std::chrono::high_resolution_clock::now();
    std::sort(nums.begin(), nums.end());
    auto sortend = std::chrono::high_resolution_clock::now();
    auto sortdiff = std::chrono::duration_cast<std::chrono::nanoseconds>(sortend - sortstart);
    auto sortdiffmiliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(sortend - sortstart);
    auto sortdiffseconds = std::chrono::duration_cast<std::chrono::seconds>(sortend - sortstart);

    // output
    std::cout << "Generation Time: " << gendiff.count() << " Nanoseconds or " << gendiffmiliseconds.count() << " Miliseconds or " << gendiffseconds.count() << " Seconds." << std::endl;
    std::cout << "Sorting Time: " << sortdiff.count() << " Nanoseconds or " << sortdiffmiliseconds.count() << " Miliseconds or " << sortdiffseconds.count() << " Seconds." << std::endl;
}
