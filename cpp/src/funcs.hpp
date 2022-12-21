#include <vector>

// find largest value in vector
unsigned int GetMax(std::vector<unsigned int> &_vector);

// swap to elements, modifies the referenced vector
void SwapElements(std::vector<unsigned int> &_vector, int index1, int index2);

// calculate prefixsum on a vector
void PrefixSum(std::vector<int> &_vector);

// output vector
void PrintVector(std::vector<unsigned int> &_vector);

// count occurence of digit at certain positon determined by placedivider
void CountingRoutine(std::vector<unsigned int> &_vector, int placedivider, int start, int end, std::vector<int> &_counters_array, int counters_start);

void RadixSortFast(std::vector<unsigned int> &_vector);
void RadixSort(std::vector<unsigned int> &_vector);