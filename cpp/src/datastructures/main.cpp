#include "timer.hpp"

#include <iostream>

void vector_reserve_emplace();
void vector_reserve_push();
void vector_index_based();

int main(){
    // push_back vs emplace_back
    int repeats = 1000;
    double emplacetime = 0.0f;
    double pushtime = 0.0f;
    double indextime = 0.0f;
    for(int i = 0; i < repeats; ++i){
        Timer::start("emplace");
        vector_reserve_emplace();
        emplacetime += Timer::stop("emplace", false);
        Timer::start("push");
        vector_reserve_push();
        pushtime += Timer::stop("push", false);
        Timer::start("index");
        vector_index_based();
        indextime += Timer::stop("index", false);
    }
    std::cout << "Emplace: " << emplacetime << "\n";
    std::cout << "Push: " << pushtime << "\n";
    std::cout << "Index: " << indextime << "\n";
}
