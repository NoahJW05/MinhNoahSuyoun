#ifndef Player_hpp
#define Player_hpp
#include "Game.hpp"
using std::string;

class Player
{
protected:
    int Health;
    int Damage;

    // location of player
    // scale of player
    // size of player

public:
    Player(int health, int damage);
    virtual ~Player() {}

    void attack(Player *Enemey);
    void takeDamage(int dmg);

    void setHealth(int health);
    void setDamage(int damage);

    int getHealth() const;
    int getDamage() const;

    // weapons ( know what weapons the player has)
};

#endif