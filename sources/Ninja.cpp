#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(string name, const Point& location, int hits) : Character(name, location, hits) { }

Ninja::Ninja(const Ninja& other) : Character(other) { 
    this->setHits(other.getHits());
}

void Ninja::move(const Character* enemy) {
    this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), _speed);
}

void Ninja::slash(Character* enemy) {
    if(enemy == nullptr) throw runtime_error("null character");
    if(!enemy->isAlive()) throw runtime_error("dead character");
    if(enemy == this) throw runtime_error("can't attack myself!");
    if(isAlive() ) enemy->hit(40);
}

int Ninja::getSpeed() const {
    return _speed;
}

void Ninja::setSpeed(int speed) {
    _speed = speed;
}

string Ninja::print() const {
    string str = "N";
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