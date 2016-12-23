#include "menustate.h"
#include "state.h"

MenuState::MenuState(){
  current = CONTINUE;
}

void MenuState::Draw(){
  io::printMsg("Continue", 32, 18, 30, (current == CONTINUE) ? Green: Grey);
  io::printMsg("Help", 32, 20, 30, (current == HELP) ? Green: Grey);
  io::printMsg("Quit", 32, 22, 30, (current == QUIT) ? Green: Grey);
  
  io::flip();
}

void MenuState::Update(){
  // Handle menu navigation
  Keys key = io::Input();
  switch(key){
  case E_QUIT:
    Game::isRunning = false;
    states::pop();
    break;

  case K_UP:
    switch(current){
    case CONTINUE:
      current = QUIT;
      break;
    case HELP:
      current = CONTINUE;
      break;
    case QUIT:
      current = HELP;
      break;
    default:
      break;
    }    
    break;
    
  case K_DOWN:
    switch(current){
    case CONTINUE:
      current = HELP;
      break;
    case HELP:
      current = QUIT;
      break;
    case QUIT:
      current = CONTINUE;
    default:
      break;
    }
    break;
    
  case K_RETURN:
    switch(current){
    case CONTINUE:
      states::pop();
      break;
    case HELP:
      break;
    case QUIT:
      Game::isRunning = false;
      states::pop();
      break;
    default:
      break;
    }
    break;
  default:
    break;
  }
}
