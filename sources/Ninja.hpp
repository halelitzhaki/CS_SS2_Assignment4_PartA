#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character{
        private:
            int _speed;
        
        public:
            Ninja(string, const Point&, int);
            Ninja(const Ninja&);
            Ninja() = delete;
            Ninja(Ninja &&) = delete;
            Ninja& operator=(Ninja const &) = delete;
            Ninja& operator=(Ninja &&) = delete;
            ~Ninja() override = default;

            void move(const Character*);
            void slash(Character*);
            int getSpeed() const;
            void setSpeed(int);
            string print() const override;
    };
}

#endif