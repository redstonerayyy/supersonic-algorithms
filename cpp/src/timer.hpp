#include <chrono>
#include <iostream>
#include <map>
#include <string>

class Timer {
public:
    std::map<std::string, std::chrono::_V2::high_resolution_clock::time_point> timers;
    // sort
    
    static void start(std::string);
    static void stop(std::string);
};
