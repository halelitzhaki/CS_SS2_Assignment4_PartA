#include "Point.hpp"

using namespace ariel;

Point::Point() {
    _x = 0.0;
    _y = 0.0;
}

Point::Point(double x,double y) {
    _x = x;
    _y = y;
}

Point::Point(const Point &other) {
    _x = other.getX();
    _y = other.getY();
}

string Point::print() const {
    string str = "(";
    str.append(to_string(_x));
    str.append(",");
    str.append(to_string(_y));
    str.append(")");
    return str;
}

double Point::distance(const Point &other) const {
    return sqrt(pow((other.getX() - _x), 2) + pow(other.getY()- _y, 2));
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

Point Point::moveTowards(const Point &src, const Point &dst ,double dist) const{
    if(src.distance(dst) <= dist) return dst;
    double totalDist = src.distance(dst), factor = dist / totalDist,
    newX = src.getX() + factor * (dst.getX() - src.getY()),
    newY = src.getY() + factor * (dst.getY() - src.getY());
    return Point{newX, newY};
}

bool Point::operator==(const Point& other) const {
    return other.getX() == _x && other.getY() == _y;
}