#pragma once

#include "include/raylib.h"

#include "pong.hpp"

class player
{
public:
  Rectangle posz;
  float speedy;
  Color color;
  int keyup;
  int keydown;

  void draw();
  void input();
  void posyadd();
  void posysub();
  void bordervertical();
  void collisionwithpong(pong *pong);
  void GODMODE(pong *pong);
};