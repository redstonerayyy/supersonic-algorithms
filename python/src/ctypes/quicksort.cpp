extern "C" {
    unsigned long HoarePartition(int *array_, unsigned long start, unsigned long end);
    void QuickSort(int *array_, unsigned long start, unsigned long end);
}

unsigned long HoarePartition(int *array_, unsigned long start, unsigned long end){
    unsigned int pivot = array_[ (int) ( (start + end) / 2 ) ];
    unsigned long i = start - 1;
    unsigned long j = end + 1;

    while(true){
        ++i;
        while(array_[i] < pivot){
            ++i;
        }

        --j;
        while(array_[j] > pivot){
            --j;
        }

        if(i >= j){
            return j;
        }
        
        unsigned int temp = array_[i];
        array_[i] = array_[j];
        array_[j] = temp;
    }
}

void QuickSort(int *array_, unsigned long start, unsigned long end){
    if ( start >= 0 and end >= 0 and start < end ){
        unsigned long crossing = HoarePartition(array_, start, end);

        QuickSort(array_, start, crossing);
        QuickSort(array_, crossing + 1, end);
    }
}
