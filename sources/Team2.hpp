#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {
        public:
            Team2(Character*);
            Team2() = delete;
            Team2(Team2 const &) = delete;
            Team2(Team2 &&) = delete;
            Team2& operator=(Team2 const &) = delete;
            Team2& operator=(Team2 &&) = delete;
            ~Team2();

            void algoritm();

    };
}

#endif