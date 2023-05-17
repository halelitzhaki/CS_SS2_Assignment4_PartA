#include "Team.hpp"

using namespace ariel;

Team::Team(Character* leader) {
    _leader = leader;
    _warriors.push_back(leader);
}

Team::~Team() {
    for(Character * warrior : _warriors) {
        delete warrior;
    }
    _warriors.clear();
}

void Team::add(Character* warrior) {
    _warriors.push_back(warrior);
}

void Team::attack(Team * enemies) {
    // TO DO
    if(dynamic_cast<Cowboy*>(_leader)) {
        Cowboy * Cleader = dynamic_cast<Cowboy*>(_leader);
        for(Character * enemy : enemies->getTeam()) {
            while(enemy->isAlive()) {
                Cleader->shoot(enemy);
                Cleader->reload();
            }
        }
    }
    else{
        Ninja * Nleader = dynamic_cast<Ninja*>(_leader);
        for(Character * enemy : enemies->getTeam()) {
            Nleader->move(enemy);
            Nleader->slash(enemy);
        }
    }
}

int Team::stillAlive() const {
    int i = 0;
    for(Character* warrior : _warriors) {
        if(warrior->isAlive()) i++;
    }
    return i;
}

void Team::print() const {
   // to do
}

void Team::algorithm() {
    // TO DO
}

vector<Character*> Team::getTeam() const {
    return _warriors;
}

Character* Team::getLeader() const {
    return _leader;
}