#include <vector>
#include <iostream>

// find largest value in vector
unsigned int GetMax(std::vector<unsigned int> &_vector){
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
        _vector[i] += _vector[i - 1];
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
