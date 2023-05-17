#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP


#include "Ninja.hpp"
#define YOUNG_NINJA_SPEED 14
#define YOUNG_NINJA_HITS 100

namespace ariel {
    class YoungNinja : public Ninja{
        public:
            YoungNinja(string,const Point&);
            YoungNinja(const YoungNinja&);
            YoungNinja() = delete;
            YoungNinja(YoungNinja &&) = delete;
            YoungNinja& operator=(YoungNinja const &) = delete;
            YoungNinja& operator=(YoungNinja &&) = delete;
            ~YoungNinja() override = default;
    };
}

#endif