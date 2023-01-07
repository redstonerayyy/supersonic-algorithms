#pragma once

#include <map>
#include <string>
#include <chrono>

// timer
class Timer {
public:
    static std::map<std::string, std::chrono::steady_clock::time_point> timers;
    static void start(std::string);
    static double stop(std::string, bool print);
};