#ifndef TEAM_HPP
#define TEAM_HPP

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>

namespace ariel {
    class Team {
        protected:
            Character *_leader;
            vector<Character*> _warriors;

        public:
            Team(Character*);
            Team() = delete;
            Team(Team const &) = delete;
            Team(Team &&) = delete;
            Team& operator=(Team const &) = delete;
            Team& operator=(Team &&) = delete;
            ~Team();

            void add(Character*);
            void attack(Team *);
            int stillAlive() const;
            void print() const;
            void algorithm();
            vector<Character*> getTeam() const;
            Character* getLeader() const;
    };
}

#endif