#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

using namespace std;

namespace ariel {
    class Point {
        private:
            double _x, _y;
        
        public:
            Point(double,double);
            Point();
            Point(const Point&);
            Point(Point &&) = default;
            Point& operator=(Point const &) = default;
            Point& operator=(Point &&) = default;
            ~Point() = default;
            double getX() const;
            double getY() const;
            string print() const ;
            double distance(const Point&) const;
            Point moveTowards(const Point&,const Point&, double) const;
            bool operator==(const Point&) const;
    };

}


#endif