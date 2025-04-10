#include "player.hpp"

#include "include/raylib.h"

#include "global.hpp"

void player::draw()
{
  DrawRectangleRec(this->posz, this->color);
}

void player::input()
{
  if (IsKeyDown(this->keydown))
  {
    player::posyadd();
  }
  if (IsKeyDown(this->keyup))
  {
    player::posysub();
  }
}

void player::posyadd()
{
  this->posz.y += this->speedy * WINDOW_DELTA_TIME;
}

void player::posysub()
{
  this->posz.y -= this->speedy * WINDOW_DELTA_TIME;
}
