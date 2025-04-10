#include "pong.hpp"

#include "include/raylib.h"

#include "global.hpp"

void pong::draw()
{
  DrawCircleV(this->pos, this->radius, this->color);
}

void pong::updatepos()
{
  this->pos.x += this->speedx * WINDOW_DELTA_TIME;
  this->pos.y += this->speedy * WINDOW_DELTA_TIME;
}

void pong::bordervertical()
{
  if (this->pos.y > WINDOW_HEIGHT - this->radius)
  {
    this->pos.y = WINDOW_HEIGHT - this->radius;
    this->speedy *= -1;
  }
  if (this->pos.y < 0 + this->radius)
  {
    this->pos.y = 0 + this->radius;
    this->speedy *= -1;
  }

  // todo: remove this when not debugging
  if (this->pos.x > WINDOW_WIDTH - this->radius)
  {
    this->pos.x = WINDOW_WIDTH - this->radius;
    this->speedx *= -1;
  }
  if (this->pos.x < 0 + this->radius)
  {
    this->pos.x = 0 + this->radius;
    this->speedx *= -1;
  }
}
