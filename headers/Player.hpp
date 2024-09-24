#ifndef Player_hpp
#define Player_hpp
#include "Game.hpp"
#include "GameObject.hpp"

using std::string;

class Player : public GameObject 
{
protected:
    int Health;
    int Damage;
    string weapons; 
     string getWeapon() const;
    
    //void attack(Player *Ememy);
    void setWeapon(std::string w);
    int PosX; 
    int PosY;
    int Velocity;
    GameObject* player;



public:
    Player(int health, int damage,const char* texturesheet,int x,int y);
    ~Player();

    //void attack(Player *Enemey);
    void takeDamage(int dmg);

    void setHealth(int health);
    void setDamage(int damage);

    int getHealth() const;
    int getDamage() const;

    
};

#endif