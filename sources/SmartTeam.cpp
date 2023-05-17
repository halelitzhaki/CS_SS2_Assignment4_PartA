#include "SmartTeam.hpp"

using namespace ariel;

SmartTeam::SmartTeam(Character* leader) : Team (leader){ }

SmartTeam::~SmartTeam() { 
    for(Character * warrior : _warriors) {
        delete warrior;
    }
    _warriors.clear();
}

void SmartTeam::algoritm() {
    // TO DO
}