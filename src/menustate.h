#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "sdl_wrapper.h"
#include "globals.h"
#include "helper.h"
#include "game.h"
#include "sdl_wrapper.h"
#include <memory.h>
#include "state.h"


const int _CONTINUE = 0;
const int _QUIT     = 1;

enum MENUITEMS{
  CONTINUE,
  HELP,
  QUIT,
  LAST_ENUM
};

class MenuState : public State{

 public:
  MenuState();
  void Update();
  void Draw();
  bool draw_overlayed() const{
    return true;
  }

  MENUITEMS current;
  
};

#endif
