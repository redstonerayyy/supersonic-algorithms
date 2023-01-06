#include "timer.hpp"

#include <iostream>
#include <string>
#include <vector>

struct Player {
    int hp;
    std::string name;
    float angle;
};

void vector_push(){
    std::vector<Player> players;
    players.reserve(100000);
    for(int i = 0; i < 100000; ++i){
        players.push_back(Player{i, "alex", 1.4f});
    }
}

void vector_emplace(){
    std::vector<Player> players(100000);
    // std::vector<Player> players;
    // players.reserve(100000);
    for(int i = 0; i < 100000; ++i){
        // players.emplace_back(Player{i, "alex", 1.4f});
        players.at(i) = Player{i, "alex", 1.4f};
    }
}

int main(){
    // push_back vs emplace_back
    int repeats = 1000;
    double pushtime = 0.0f;
    double emplacetime = 0.0f;
    for(int i = 0; i < repeats; ++i){
        Timer::start("push");
        vector_push();
        pushtime += Timer::stop("push", false);
        Timer::start("emplace");
        vector_emplace();
        emplacetime += Timer::stop("emplace", false);
    }
    std::cout << pushtime << "\n";
    std::cout << emplacetime << "\n";
}
