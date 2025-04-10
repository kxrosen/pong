#pragma once

#include "include/raylib.h"

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
};
