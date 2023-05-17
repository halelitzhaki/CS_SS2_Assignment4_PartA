#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP


#include "Ninja.hpp"
#define TRAINED_NINJA_SPEED 12
#define TRAINED_NINJA_HITS 120

namespace ariel {
    class TrainedNinja : public Ninja{
        public:
            TrainedNinja(string,const Point&);
            TrainedNinja(const TrainedNinja&);
            TrainedNinja() = delete;
            TrainedNinja(TrainedNinja &&) = delete;
            TrainedNinja& operator=(TrainedNinja const &) = delete;
            TrainedNinja& operator=(TrainedNinja &&) = delete;
            ~TrainedNinja() override = default;
    };
}

#endif