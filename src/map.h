#ifndef MAP_H
#define MAP_H

#include "globals.h"
#include "helper.h"
#include <memory>

class Entity;

struct Cell{

  Cell();
  ~Cell();

  void Reset();
  void Replace(Cell c);

  bool isExplored;
  bool isSeen;
  int lightLevel;
  
  P pos;
  std::string _description;
  char _glyph;
  cColor _color;
  bool _block;
  
};
 
struct Door : public Cell{
  Door(bool open);
  ~Door();
public:
  bool _open;
  
};

namespace Map{

  extern Cell cells[g::MAP_WIDTH][g::MAP_HEIGHT];

  extern int dungeonLevel;

  void Init();
  void nextLevel();
  void createMap();
  void createRandomMap();
  void cleanMap();
  void clearVision();
  void computeFov();
  void doFov(float x, float y);
  
  void renderMap();
  
  // map interaction
  void openDoor(P pos);
  bool closeDoor(P pos);

  _DIR pickDir();  
  
} //namespace Map

#endif
