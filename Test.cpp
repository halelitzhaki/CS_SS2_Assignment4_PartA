#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;
using namespace doctest;


TEST_CASE("Testing Point class") {
    Point p;
    CHECK(p.getX() == 0.0);
    CHECK(p.getY() == 0.0);

    Point a(3, 4), b(1, 2), c(4, 6);

    CHECK(a.getX() == 3);
    CHECK(a.getY() == 4);
    

    CHECK(b.distance(c) == Approx(5.0));

    Point src(1.0, 2.0), dst(5.0, 6.0);
    double dist = 3.0;
    
    Point result = src.moveTowards(src, dst, dist);
    CHECK((int)result.getX() == 2);
    CHECK((int)result.getY() == 4);
}

TEST_CASE("Testing Character class") {
    Point location(3, 4);
    Character character("Adam", location, 10);

    CHECK(character.getName() == "Adam");
    CHECK(character.getLocation() == location);
    CHECK(character.getHits() == 10);

    character.hit(5);

    CHECK(character.getHits() == 5);
    CHECK(character.isAlive());

    character.hit(10);

    CHECK(character.getHits() == -5);
    CHECK_FALSE(character.isAlive());
}

TEST_CASE("Testing Ninja class") {
    Point location(3, 4);
    Ninja ninja("Panda", location, 10);
    Character target("Enemy", Point(5, 6), 10);

    CHECK(ninja.getName() == "Panda");
    CHECK(ninja.getLocation() == location);
    CHECK(ninja.getHits() == 10);
    CHECK(ninja.getSpeed() == 0);
    
    ninja.move(&target);

    ninja.slash(&target);

    CHECK(target.getHits() < 10);

    ninja.setSpeed(5);

    CHECK(ninja.getSpeed() == 5);
}

TEST_CASE("Testing OldNinja class") {
    Point location(3, 4);
    OldNinja oldNinja("Panda", location);
    Character target("Enemy", Point(5, 6), 10);

    CHECK(oldNinja.getName() == "Panda");
    CHECK(oldNinja.getLocation() == location);
    CHECK(oldNinja.getHits() == OLD_NINJA_HITS);
    CHECK(oldNinja.getSpeed() == OLD_NINJA_SPEED);
    
    oldNinja.move(&target);
    oldNinja.slash(&target);

    CHECK(target.getHits() < 10);
}

TEST_CASE("Testing YoungNinja class") {
    Point location(3, 4);
    YoungNinja youngNinja("Panda", location);
    Character target("Enemy", Point(5, 6), 10);

    CHECK(youngNinja.getName() == "Panda");
    CHECK(youngNinja.getLocation() == location);
    CHECK(youngNinja.getHits() == YOUNG_NINJA_HITS);
    CHECK(youngNinja.getSpeed() == YOUNG_NINJA_SPEED);
    
    youngNinja.move(&target);
    youngNinja.slash(&target);

    CHECK(target.getHits() < 10);
}

TEST_CASE("Testing TrainedNinja class") {
    Point location(3, 4);
    TrainedNinja trainedNinja("Panda", location);
    Character target("Enemy", Point(5, 6), 10);

    CHECK(trainedNinja.getName() == "Panda");
    CHECK(trainedNinja.getLocation() == location);
    CHECK(trainedNinja.getHits() == TRAINED_NINJA_HITS);
    CHECK(trainedNinja.getSpeed() == TRAINED_NINJA_SPEED);
    
    trainedNinja.move(&target);
    trainedNinja.slash(&target);

    CHECK(target.getHits() < 10);
}

TEST_CASE("Checking Ninjas differences") {
    OldNinja oldNinja("old", Point(5, 6));
    YoungNinja youngNinja("young", Point(7, 6));
    TrainedNinja trainedNinja("trained", Point());

    CHECK_NE(oldNinja.getSpeed(), youngNinja.getSpeed());
    CHECK_NE(trainedNinja.getSpeed(), youngNinja.getSpeed());
    CHECK_NE(oldNinja.getSpeed(), trainedNinja.getSpeed());
    CHECK_NE(oldNinja.getHits(), youngNinja.getHits());
    CHECK_NE(trainedNinja.getHits(), youngNinja.getHits());
    CHECK_NE(trainedNinja.getHits(), oldNinja.getHits());
}

TEST_CASE("Testing Cowboy class") {
    Point location(3, 4);
    Cowboy cowboy("Woody", location);
    Character target("Enemy", Point(3.5, 4), 65);

    CHECK(cowboy.getName() == "Woody");
    CHECK(cowboy.getLocation() == location);
    CHECK(cowboy.getHits() == COWBOY_HITS);
    CHECK(cowboy.hasBullets());

    for(int i = 0; i < BULLETS; i++) cowboy.shoot(&target);

    CHECK(target.getHits() < 10);
    CHECK_FALSE(cowboy.hasBullets());

    cowboy.reload();

    CHECK(cowboy.hasBullets());
    cowboy.shoot(&target);
    CHECK_FALSE(target.isAlive());
}

TEST_CASE("Testing Team class") {
    Team team1(new Cowboy("Woody", Point(1, 1)));

    CHECK(team1.stillAlive() == 1);
    CHECK(team1.getTeam().at(0)->getName() == "Woody");

    team1.add(new YoungNinja("Ping Xiao Po", Point(2, 2)));
    team1.add(new TrainedNinja("Master Shifu", Point(3, 3)));

    CHECK(team1.stillAlive() == 3);

    ;
    Team team2(new OldNinja("Grand Master Oogway", Point(2, 2)));
    team2.add(new Cowboy("John", Point(4, 4)));

    team1.attack(&team2);

    CHECK(team1.stillAlive() == 3);
    CHECK(team2.stillAlive() == 0);
}

TEST_CASE("Testing Team2 class") {
    Team2 team1(new Cowboy("Woody", Point(1, 1)));

    CHECK(team1.stillAlive() == 1);
    CHECK(team1.getTeam().at(0)->getName() == "Woody");

    team1.add(new YoungNinja("Ping Xiao Po", Point(2, 2)));
    team1.add(new TrainedNinja("Master Shifu", Point(3, 3)));

    CHECK(team1.stillAlive() == 3);

    Team2 team2(new OldNinja("Grand Master Oogway", Point(2, 2)));
    team2.add(new Cowboy("John", Point(4, 4)));

    team1.attack(&team2);

    CHECK(team1.stillAlive() == 3);
    CHECK(team2.stillAlive() == 0);

}

TEST_CASE("Testing SmartTeam class") {
    SmartTeam team1(new Cowboy("Woody", Point(1, 1)));

    CHECK(team1.stillAlive() == 1);
    CHECK(team1.getTeam().at(0)->getName() == "Woody");

    team1.add(new YoungNinja("Ping Xiao Po", Point(2, 2)));
    team1.add(new TrainedNinja("Master Shifu", Point(3, 3)));

    CHECK(team1.stillAlive() == 3);

    SmartTeam team2(new OldNinja("Grand Master Oogway", Point(2, 2)));
    team2.add(new Cowboy("John", Point(4, 4)));

    team1.attack(&team2);

    CHECK(team1.stillAlive() == 3);
    CHECK(team2.stillAlive() == 0);
}

TEST_CASE("Testing dual-attack") {
    Team team1(new Cowboy("Woody", Point(1, 1)));
    team1.add(new YoungNinja("Ping Xiao Po", Point(2, 2)));
    team1.add(new TrainedNinja("Master Shifu", Point(3, 3)));

    Team team2(new OldNinja("Grand Master Oogway", Point(2, 2)));
    team2.add(new Cowboy("John", Point(4, 4)));

    while(team1.stillAlive() > 0 && team2.stillAlive() > 0){
        team1.attack(&team2);
        team2.attack(&team1);
        team1.print();
        team2.print();
    }
}

TEST_CASE("Testing Cowboys VS. Ninjas") {
    Team team1(new Cowboy("Woody", Point(2, 2)));
    team1.add(new Cowboy("John", Point(4, 4)));

    Team team2(new OldNinja("Grand Master Oogway", Point(1, 1)));
    team2.add(new YoungNinja("Ping Xiao Po", Point(2, 2)));
    team2.add(new TrainedNinja("Master Shifu", Point(3, 3)));

    while(team1.stillAlive() > 0 && team2.stillAlive() > 0){
        team1.attack(&team2);
        team2.attack(&team1);
        team1.print();
        team2.print();
    }
}

TEST_CASE("Testing Team VS. Team2") {
    Team team1(new Cowboy("Woody", Point(1, 1)));
    team1.add(new YoungNinja("Ping Xiao Po", Point(2, 2)));
    team1.add(new TrainedNinja("Master Shifu", Point(3, 3)));

    Team2 team2(new OldNinja("Grand Master Oogway", Point(2, 2)));
    team2.add(new Cowboy("John", Point(4, 4)));

    team1.attack(&team2);
}

TEST_SUITE("Testing cowboy can't shoot :") {
    TEST_CASE("Testing cowboy can't shoot himself") {
        Cowboy cowboy("Woody", Point());
        CHECK_THROWS(cowboy.shoot(&cowboy));
    }
    TEST_CASE("Testing cowboy can't shoot dead characters") {
        Cowboy cowboy("Woody", Point());
        OldNinja ninja("ninja", Point(1, 2));
        while(ninja.isAlive()) {
            cowboy.shoot(&ninja);
            cowboy.reload();
        }
        CHECK_THROWS(cowboy.shoot(&ninja));
    }
    TEST_CASE("Testing cowboy can't shoot null character") {
        Cowboy cowboy("Woody", Point());
        CHECK_THROWS(cowboy.shoot(nullptr));
    }
}

TEST_SUITE("Testing ninja can't slash :") {
    TEST_CASE("Testing ninja can't slash himself") {
        OldNinja ninja("ninja", Point(1, 2));
        CHECK_THROWS(ninja.slash(&ninja));
    }
    TEST_CASE("Testing ninja can't slash dead characters") {
        Cowboy cowboy("Woody", Point());
        OldNinja ninja("ninja", Point(1, 2));
        while(cowboy.isAlive()) ninja.slash(&cowboy);
        CHECK_THROWS(ninja.slash(&cowboy));
    }
    TEST_CASE("Testing ninja can't slash null character") {
        OldNinja ninja("ninja", Point(1, 2));
        CHECK_THROWS(ninja.slash(nullptr));
    }
}