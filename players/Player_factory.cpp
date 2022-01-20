#include "Player_factory.h"
#include "Random_player.h"
#include "Console_player.h"
#include "Optimal_player.h"

bool Player_factory::contains_player(std::string &player_type) {
    return creators.end() != creators.find(player_type);
}

std::unique_ptr<Player> Player_factory::create(const std::string &id) {
    return creators[id]();
}

Player_factory::Player_factory() {
    creators.insert(std::make_pair(std::string("random"), [] { return std::unique_ptr<Random_player>(); }));
    creators.insert(std::make_pair(std::string("console"), [] { return std::unique_ptr<Console_player>(); }));
    creators.insert(std::make_pair(std::string("optimal"), [] { return std::unique_ptr<Optimal_player>(); }));
}
