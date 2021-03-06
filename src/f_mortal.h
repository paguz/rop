#include <string>
class Entity;
class Actor;
class Fighter;

class Mortal{

 public:
  int maxHp;
  int hp;
  int armor;
  int dodgeRating;
  std::string corpseName;
  unsigned int xp;
  bool isAlive;
  int decayTimer;
  
  
  Mortal(int maxHp, int armor, std::string corpseName, int xp);
  virtual  ~Mortal() {};
  inline bool isDead() {return hp <= 0; }
  int takeDmg(Entity &a, int dmg);
  int Heal(int amount);
  virtual void die(Entity &a);
  
 protected:
  
};

class MonsterMortal : public Mortal{

 public:
  MonsterMortal(int maxHp, int armor, std::string corpseName, int xp);
  void die(Entity &a); 
};

class PlayerMortal : public Mortal{

 public:
  PlayerMortal(int maxHp, int armor, std::string corpseName);
  void die(Entity &a); 
};
