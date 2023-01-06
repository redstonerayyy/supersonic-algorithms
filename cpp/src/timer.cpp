#include "timer.hpp"

// initialize
std::map<std::string, std::chrono::steady_clock::time_point> Timer::timers = std::map<std::string, std::chrono::steady_clock::time_point>();

void Timer::start(std::string name){
    auto timenow = std::chrono::steady_clock::now();
    timers[name] = timenow;
}

long long Timer::stop(std::string name){
    auto timenow = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timenow - timers[name]);
    auto diffseconds = std::chrono::duration_cast<std::chrono::duration<double>>(timenow - timers[name]);
    std::cout << name << " took Miliseconds: " << diff.count() << " " << "Seconds: " << diffseconds.count() << std::endl;
    return diff.count();
}
