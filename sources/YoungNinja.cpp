#include "YoungNinja.hpp"

using namespace ariel;

YoungNinja::YoungNinja(string name, const Point& location) : Ninja(name, location, YOUNG_NINJA_HITS) {
    this->setSpeed(YOUNG_NINJA_SPEED);
}

YoungNinja::YoungNinja(const YoungNinja& other) : Ninja(other) {
    this->setSpeed(other.getSpeed());
}