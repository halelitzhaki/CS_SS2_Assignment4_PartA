#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {
        public:
            SmartTeam(Character*);
            SmartTeam() = delete;
            SmartTeam(SmartTeam const &) = delete;
            SmartTeam(SmartTeam &&) = delete;
            SmartTeam& operator=(SmartTeam const &) = delete;
            SmartTeam& operator=(SmartTeam &&) = delete;
            ~SmartTeam();

            void algoritm();

    };
}

#endif