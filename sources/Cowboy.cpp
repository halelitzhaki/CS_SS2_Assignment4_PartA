#include "Cowboy.hpp"

using namespace ariel;

Cowboy::Cowboy(string name, const Point& location) : Character(name, location, COWBOY_HITS) {
    _bullets = BULLETS;
 }

Cowboy::Cowboy(const Cowboy &other) : Character(other) { }

string Cowboy::print() const {
    string str = "C";
    if(isAlive() == 1) {
        str.append(this->getName());
        str.append(", ");
        str.append(to_string(this->getHits()));
        str.append(", ");
        str.append(this->getLocation().print());
    }
    else {
        str.append("(");
        str.append(this->getName());
        str.append(")");
    }
    return str;
}

void Cowboy::shoot(Character * enemy) {
    if(enemy == nullptr) throw runtime_error("null character");
    if(!enemy->isAlive()) throw runtime_error("dead character");
    if(enemy == this) throw runtime_error("can't attack myself!");
    if(isAlive() && hasBullets()) {
        enemy->hit(10);
        _bullets--;
    }
}

bool Cowboy::hasBullets() {
    return _bullets != 0;
}

void Cowboy::reload() {
    _bullets += BULLETS;
}