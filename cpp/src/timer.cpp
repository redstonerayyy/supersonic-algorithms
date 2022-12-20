#include "timer.hpp"

void Timer::start(std::string name){
    auto timenow = std::chrono::high_resolution_clock::now();
}

void Timer::stop(std::string name){
    auto timenow = std::chrono::high_resolution_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(timenow - Timer::timers[name]);
    auto diffseconds = std::chrono::duration_cast<std::chrono::seconds>(diff);
}
