#include <string>
#include <vector>

struct Player {
    int hp;
    std::string name;
    float angle;
};

void vector_reserve_emplace(){
    std::vector<Player> players;
    players.reserve(100000);
    for(int i = 0; i < 100000; ++i){
        players.emplace_back(Player{i, "alex", 1.4f});
    }
}

void vector_reserve_push(){
    std::vector<Player> players;
    players.reserve(100000);
    for(int i = 0; i < 100000; ++i){
        players.push_back(Player{i, "alex", 1.4f});
    }
}

void vector_index_based(){
    std::vector<Player> players(100000);
    for(int i = 0; i < 100000; ++i){
        players.at(i) = Player{i, "alex", 1.4f};
    }
}
