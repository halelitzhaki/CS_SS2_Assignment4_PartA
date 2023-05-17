#include "OldNinja.hpp"

using namespace ariel;

OldNinja::OldNinja(string name, const Point& location) : Ninja(name, location, OLD_NINJA_HITS) {
    this->setSpeed(OLD_NINJA_SPEED);
}

OldNinja::OldNinja(const OldNinja& other) : Ninja(other) {
    this->setSpeed(other.getSpeed());
}