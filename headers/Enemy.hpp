#ifndef Enemy_hpp
#define Enemy_hpp
#include "Player.hpp"
#include "GameObject.hpp"

using std::string;
class Enemey : public Player {
 protected:
 int EHealth;
 int EDamage;
 int EposX;
 int EposY;
 int Evlocity;
 public:

};
#endif 