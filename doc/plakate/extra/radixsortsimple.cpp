void RadixSort(std::vector<unsigned int> &_vector) {
    unsigned int digitplace = 1;
    std::vector<unsigned int> result(_vector.size());
    unsigned int max = GetMax(_vector);
    
    while(max/digitplace > 0){
        std::vector<int> counters_array(10, 0);
        
        CountingRoutine(_vector, digitplace, 0, _vector.size(), counters_array, 0);

        PrefixSum(counters_array);

        for (int i = int(_vector.size()) - 1; i >= 0; i--) {
            unsigned int digit = (_vector[i]/digitplace) % 10;
            counters_array[ digit ]--;
            result[ counters_array[ digit ] ] = _vector[i];
        }

        for (unsigned long i = 0; i < _vector.size(); ++i) {
            _vector[i] = result[i];
        }

        unsigned long multiple = long(digitplace) * 10;
        if(multiple > std::numeric_limits<unsigned int>::max()){
            break;
        } else {
            digitplace = multiple;
        }
    }
}