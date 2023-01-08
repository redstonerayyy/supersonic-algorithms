#include <iostream>
#include <cstdint>
#include <vector>
#include <array>

#include <immintrin.h>

#include "timer.hpp"

const unsigned long tenmillion = 10000000;
const unsigned long hundredmillion = 100000000;
std::vector<unsigned int> gen(unsigned long length, unsigned int max);


// shift the integer and static cast to unsigned char to get the 8 rightmost bits
#define RADIXBYTE(num, pass) static_cast<std::uint8_t>((num >> (pass << 3)))

void RadixSort(std::vector<std::uint32_t> &vector){
    // create counters
    Timer::start("calc");

    bool sortedleft = true;
    bool sortedright = true;
    std::array<std::uint64_t, 256 * 4> counters = { 0 }; // store for all 4 passes in one array and use offset
    
    std::uint64_t vectorizedruns = ((std::uint64_t) vector.size() / 4) * 4;
    std::uint8_t remaining = vector.size() % 4; // 3 or less
    
    __m256i_u passes = _mm256_setr_epi16(
        256 * 3, 256 * 2, 256 * 1, 256 * 0, 
        256 * 3, 256 * 2, 256 * 1, 256 * 0, 
        256 * 3, 256 * 2, 256 * 1, 256 * 0, 
        256 * 3, 256 * 2, 256 * 1, 256 * 0
    );

    for(std::uint64_t i = 0; i < vectorizedruns; i += 4){
        // check if array is already fully sorted in either direction
        if(i > 0 && ( vector.at(i - 1) > vector.at(i))) sortedleft = false;
        if(i > 0 && ( vector.at(i - 1) < vector.at(i))) sortedright = false;
        // vector magic
        // __m256i_u test = _mm256_setr_epi32(0U, vector.at(i), 0U, vector.at(i + 1), 0U, vector.at(i + 2), 0U, vector.at(i + 3));
        __m256i_u values = _mm256_setr_epi32(0U, vector.at(i), 0U, vector.at(i + 1), 0U, vector.at(i + 2), 0U, vector.at(i + 3));
        // https://www.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/compiler-reference/intrinsics/intrinsics-for-avx2/intrinsics-for-shuffle-operations-1/mm256-shuffle-epi8.html
        __m256i_u shufflevector = _mm256_setr_epi8(
            // settings the leftmost bit results in 0 because of some kind of prevention (see link)
            0b00000111, 0b10000000, 0b00000110, 0b10000000,
            0b00000101, 0b10000000, 0b00000100, 0b10000000,
            0b00001111, 0b10000000, 0b00001110, 0b10000000,
            0b00001101, 0b10000000, 0b00001100, 0b10000000,
            0b00000111, 0b10000000, 0b00000110, 0b10000000,
            0b00000101, 0b10000000, 0b00000100, 0b10000000,
            0b00001111, 0b10000000, 0b00001110, 0b10000000,
            0b00001101, 0b10000000, 0b00001100, 0b10000000
        ); // 255 makes it zero
        __m256i_u shuffled =  _mm256_shuffle_epi8(values, shufflevector);
        __m256i_u result = _mm256_adds_epu16(shuffled, passes);

        short *resultpointer = (short*)&result;
        for(std::uint8_t j = 0; j < 16; j++){
            counters.at((unsigned short)resultpointer[j])++;
        }
    }

    // calculate remaining values
    for(std::uint64_t i = vectorizedruns; i < vector.size(); ++i){
        // check if array is already fully sorted in either direction
        if(i > 0 && ( vector.at(i - 1) > vector.at(i))) sortedleft = false;
        if(i > 0 && ( vector.at(i - 1) < vector.at(i))) sortedright = false;
        // passes 0, 1, 2, 3
        counters.at(256 * 0 + RADIXBYTE(vector.at(i), 0))++;
        counters.at(256 * 1 + RADIXBYTE(vector.at(i), 1))++;
        counters.at(256 * 2 + RADIXBYTE(vector.at(i), 2))++;
        counters.at(256 * 3 + RADIXBYTE(vector.at(i), 3))++;
    }
    
    // abort if sorted
    if(sortedleft || sortedright) return;

    // calculate prefixsum in 4 passes
    std::array<bool, 4> skips = { false };
    for(std::uint8_t offset = 0; offset < 4; ++offset){
        // check if all elements in this pass are zero
        if(counters.at(256 * offset) == vector.size()){
            skips.at(offset) = true;
            continue;;
        }
        for(std::uint16_t i = 1; i < 256; ++i){
            counters.at(256 * offset + i) += counters.at(256 * offset + i - 1);
        }
    }

    Timer::stop("calc", true);
    Timer::start("build");

    //rebuilt in 4 passes
    std::vector<std::uint32_t> output(vector.size());
    for(std::uint8_t pass = 0; pass < 4; ++pass){
        // check skip
        if(skips.at(pass)){
            continue;
        }
        // one iteration
        //https://stackoverflow.com/questions/5458204/unsigned-int-reverse-iteration-with-for-loops
        for(std::uint64_t i = vector.size(); i-- > 0;){
            // std::uint8_t radix = RADIXBYTE(vector.at(i), pass);
            std::uint16_t pos = 256 * pass + RADIXBYTE(vector.at(i), pass);
            // decrement counter to make it point to right index
            // counters.at(256 * pass + radix)--;
            output.at( --counters.at(pos) ) = vector.at(i);
        }
        // swap references
        std::swap(vector, output);
    }

    Timer::stop("build", true);
}

int main(){
    unsigned int maximum = 0xFFFFFFFF; // 4294967295
    // unsigned int maximum = 0x00FFFFFF; // 16777215
    // unsigned int maximum = 0x0000FFFF; // 65535
    // unsigned int maximum = 0x000000FF; // 255
    std::vector<std::uint32_t> liste = gen(tenmillion, maximum);
    Timer::start("terdimann");
    RadixSort(liste);
    Timer::stop("terdimann", true);
}
