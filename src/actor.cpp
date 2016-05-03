#include "actor.h"
#include "sdl_wrapper.h"
#include "feature_ai.h"
Actor::Actor(int x, int y, std::string name, char glyph, cColor c) :
  ai(NULL), _x(x), _y(y), _name(name), _glyph(glyph), _color(c){
  
}

Actor::~Actor(){
  if ( ai ) delete ai;
}

void Actor::Render(){
  engine.renderChar(_glyph, _x, _y, _color);
}

void Actor::Update(){
  if(ai) ai->Update(this);
}