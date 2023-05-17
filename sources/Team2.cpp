#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character* leader) : Team (leader){ }

Team2::~Team2() { 
    for(Character * warrior : _warriors) {
        delete warrior;
    }
    _warriors.clear();
}

void Team2::algoritm() {
    // TO DO
}