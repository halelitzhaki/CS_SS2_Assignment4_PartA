#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#define BULLETS 6
#define COWBOY_HITS 110

namespace ariel {
    class Cowboy : public Character{
        private:
            int _bullets;

        public:
            Cowboy(string, const Point&);
            Cowboy(const Cowboy&);
            Cowboy() = delete;
            Cowboy(Cowboy &&) = delete;
            Cowboy& operator=(Cowboy const &) = delete;
            Cowboy& operator=(Cowboy &&) = delete;
            ~Cowboy() override = default;
            string print() const override;
            bool hasBullets();
            void shoot(Character*);
            void reload();
            
    };
}

#endif