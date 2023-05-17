#include "TrainedNinja.hpp"

using namespace ariel;

TrainedNinja::TrainedNinja(string name, const Point& location) : Ninja(name, location, TRAINED_NINJA_HITS) {
    this->setSpeed(TRAINED_NINJA_SPEED);
}

TrainedNinja::TrainedNinja(const TrainedNinja& other) : Ninja(other) {
    this->setSpeed(other.getSpeed());
}