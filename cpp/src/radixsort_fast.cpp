#include <vector>
#include <limits>
#include "funcs.hpp"

// the one and only superfast radix sort
void RadixSortFast(std::vector<unsigned int> &_vector) {
    // resulting array, will be used in the algorithm to store partially
    // sorted copy of the original array
    std::vector<unsigned int> result(_vector.size());
    
    // get max value
    unsigned int max = GetMax(_vector);
    // start at right most digit
    unsigned int digitplace = 1;

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

        std::swap(result, _vector);

        // increase digit place and check for arithmetic overflow
        unsigned long multiple = long(digitplace) * 10;
        if(multiple > std::numeric_limits<unsigned int>::max()){
            break;
        } else {
            digitplace = multiple;
        }
    }
}