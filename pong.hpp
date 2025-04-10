#pragma once

#include "include/raylib.h"

class pong
{
public:
  float radius;
  Vector2 pos;
  float speedx;
  float speedy;
  Color color;

  void draw();
  void updatepos();
  void bordervertical();
};
