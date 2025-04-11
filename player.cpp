#include "player.hpp"

#include "include/raylib.h"

#include "global.hpp"
#include "pong.hpp"

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

void player::bordervertical()
{
  if (this->posz.y > WINDOW_HEIGHT - this->posz.height)
  {
    this->posz.y = WINDOW_HEIGHT - this->posz.height;
  }

  if (this->posz.y < 0)
  {
    this->posz.y = 0;
  }
}

void player::collisionwithpong(pong *pong)
{
  if (CheckCollisionCircleRec(pong->pos, pong->radius, this->posz))
  {
    pong->speedx *= -1;
  }
}

void player::GODMODE(pong *pong)
{
  this->posz.y = pong->pos.y - this->posz.height / 2;
}
