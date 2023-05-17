#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel{
    class Character {
        private:
            Point _location;
            int _hits;
            string _name;

        public:
            Character(string, const Point&, int);
            Character(const Character&);
            Character() = delete;
            Character(Character &&) = delete;
            Character& operator=(Character const &) = default;
            Character& operator=(Character &&) = default;
            virtual ~Character() = default;

            Point getLocation() const;
            string getName() const;
            int getHits() const;
            void setHits(int);
            double distance(const Character&) const;
            bool isAlive() const;
            void hit(int);
            virtual string print() const;

    };

}

#endif