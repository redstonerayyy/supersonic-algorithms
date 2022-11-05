// clang++ sortv1.cpp -O3 -march=native -o sortv1
#include <random>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

// generate
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

// radixsort algorithm
// https://www.codingeek.com/algorithms/radix-sort-explanation-pseudocode-and-implementation/

// find largest value in vector
inline unsigned int GetMax(std::vector<unsigned int> &_vector){
    unsigned int max = _vector[0];
    for (int i = 1; i < _vector.size(); ++i) {
        if(_vector[i] > max){
            max = _vector[i];
        }
    }
    return max;
}

// swap to elements, modifies the referenced vector
void SwapElements(std::vector<unsigned int> &_vector, int index1, int index2){
    // https://www.tutorialspoint.com/how-to-swap-two-arrays-without-using-temporary-variable-in-c-language
    // use in place swap trick without temporary variable
    _vector[index1] = _vector[index1] + _vector[index2];
    _vector[index2] = _vector[index1] - _vector[index2];
    _vector[index1] = _vector[index1] - _vector[index2];
}

// calculate prefixsum on a vector
void PrefixSum(std::vector<int> &_vector){
    for (int i = 1; i < _vector.size(); ++i) {
        _vector[i] = _vector[i - 1] + _vector[i];
    }
}

void PrintVector(std::vector<unsigned int> &_vector){
    for (unsigned int i : _vector) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

// count occurence of digit at certain positon determined by placedivider
void CountingRoutine(std::vector<unsigned int> &_vector, int placedivider, int start, int end, std::vector<int> &_counters_array, int counters_start){
    // count digits 0 - 9
    for (int i = start; i < end; ++i) {

        // get digit at certain place, e. g. 303/10 = 30.3, 30.3 % 10 = 0
        // digit at second position from the right is 0
        _counters_array[ counters_start + (_vector[i]/placedivider) % 10 ]++;
    }
}

// the one and only superfast radix sort
void RadixSort(std::vector<unsigned int> &_vector) {
    // start at right most digit
    unsigned int digitplace = 1;
    // resulting array, will be used in the algorithm to store partially
    // sorted copy of the original array
    std::vector<unsigned int> result(_vector.size());
    // get max value
    unsigned int max = GetMax(_vector);

    // stop if no digits are at this position
    while(max/digitplace > 0){
        std::vector<int> counters_array(10, 0);
        CountingRoutine(_vector, digitplace, 0, _vector.size(), counters_array, 0);

        // apply prefixsum to this vector
        PrefixSum(counters_array);

        //rebuilt the new array based on this sorting pass
        for (int i = int(_vector.size()) - 1; i >= 0; i--) {
            // get the value of the prefixsum array at the position
            // for the current digit and subtract 1 from it,
            // so it points to the true index
            unsigned int digit = (_vector[i]/digitplace) % 10;
            counters_array[ digit ]--;
            // place the element of the original vector at this position
            // which is now in the prefixsum array, so it is at the right
            // position for this digit pass
            result[ counters_array[ digit ] ] = _vector[i];
        }

        // copy to original array
        for (unsigned long i = 0; i < _vector.size(); ++i) {
            _vector[i] = result[i];
        }

        // increase digit place and check for arithmetic overflow
        unsigned long multiple = long(digitplace) * 10;
        if(multiple > std::numeric_limits<unsigned int>::max()){
            break;
        } else {
            digitplace = multiple;
        }
    }
}

int main(){
    // length of list to generate and sort
    unsigned int length = 10000000; // 10^7
    // unsigned int length = 100;

    // generate list of numbers
    auto genstart = std::chrono::high_resolution_clock::now();
    std::vector<unsigned int> nums = gen(length);
    auto genend = std::chrono::high_resolution_clock::now();
    auto gendiff = std::chrono::duration_cast<std::chrono::nanoseconds>(genend - genstart);
    auto gendiffmiliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(genend - genstart);
    auto gendiffseconds = std::chrono::duration_cast<std::chrono::seconds>(genend - genstart);

    // sort
    auto sortstart = std::chrono::high_resolution_clock::now();
    // std::sort(nums.begin(), nums.end());
    RadixSort(nums);
    auto sortend = std::chrono::high_resolution_clock::now();
    auto sortdiff = std::chrono::duration_cast<std::chrono::nanoseconds>(sortend - sortstart);
    auto sortdiffmiliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(sortend - sortstart);
    auto sortdiffseconds = std::chrono::duration_cast<std::chrono::seconds>(sortend - sortstart);

    // output
    std::cout << "Generation Time: " << gendiff.count() << " Nanoseconds or " << gendiffmiliseconds.count() << " Miliseconds or " << gendiffseconds.count() << " Seconds." << std::endl;
    std::cout << "Sorting Time: " << sortdiff.count() << " Nanoseconds or " << sortdiffmiliseconds.count() << " Miliseconds or " << sortdiffseconds.count() << " Seconds." << std::endl;
}
