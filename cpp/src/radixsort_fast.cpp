#include <vector>
#include <limits>
#include "funcs.hpp"

// the one and only superfast radix sort
void RadixSortFast(std::vector<unsigned int> &_vector) {
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
        // for (unsigned long i = 0; i < _vector.size(); ++i) {
        //     _vector[i] = result[i];
        // }
        
        // swap vectors
        std::swap(result, _vector);
        
        //result span, makes wrong values
        // std::span rspan = std::span(result.begin(), result.size());
        // // vector span
        // std::span vspan = std::span(_vector.begin(), _vector.size());

        // test with default constructuro, slow
        // std::vector<unsigned int> temp = std::move(result);
        // result = std::vector<unsigned int>(_vector.begin(), _vector.end());
        // _vector = std::vector<unsigned int>(temp.begin(), temp.end());

        // use std::move        
        // std::vector<unsigned int> temp = std::move(result);
        // result = std::move(_vector);
        // _vector = std::move(temp);

        // increase digit place and check for arithmetic overflow
        unsigned long multiple = long(digitplace) * 10;
        if(multiple > std::numeric_limits<unsigned int>::max()){
            break;
        } else {
            digitplace = multiple;
        }
    }
}