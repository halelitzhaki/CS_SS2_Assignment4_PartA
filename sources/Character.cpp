#include "Character.hpp"

using namespace ariel;

Character::Character(string name, const Point& location, int hits) {
    _name = string(name);
    _location = Point(location);
    _hits = hits;
}

Character::Character(const Character &other) {
    *this = Character(other.getName(), other.getLocation(), other.getHits());
}

Point Character::getLocation() const {
    return _location;
}

string Character::getName() const {
    return _name;
}

int Character::getHits() const {
    return _hits;
}
void Character::setHits(int hits) {
    _hits = hits;
}

double Character::distance(const Character& other) const {
    return _location.distance(other.getLocation());
}

bool Character::isAlive() const {
    return _hits > 0;
}

void Character::hit(int n) {
    _hits -= n;
}

string Character::print() const {
    return string();
}