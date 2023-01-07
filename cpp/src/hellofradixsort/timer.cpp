#include "timer.hpp"

#include <map>
#include <string>
#include <chrono>
#include <iostream>

std::map<std::string, std::chrono::steady_clock::time_point> Timer::timers = std::map<std::string, std::chrono::steady_clock::time_point>();

void Timer::start(std::string name){
    auto timenow = std::chrono::steady_clock::now();
    timers[name] = timenow;
}

double Timer::stop(std::string name, bool print){
    auto timenow = std::chrono::steady_clock::now();
    auto diffns = std::chrono::duration_cast<std::chrono::microseconds>(timenow - timers[name]);
    auto diffms = std::chrono::duration_cast<std::chrono::milliseconds>(timenow - timers[name]);
    auto diffs = std::chrono::duration_cast<std::chrono::duration<double>>(timenow - timers[name]);
    if(print) std::cout << name << ": " << diffns.count() << "micros " << diffms.count() << "milis " << diffs.count() << "s " << std::endl;
    return diffs.count();
}