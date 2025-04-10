#include "include/raylib.h"

#include "global.hpp"
#include "pong.hpp"

int main()
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(WINDOW_FPS);

  pong pong;
  pong.radius = 20;
  pong.pos.x = WINDOW_WIDTH / 2 - pong.radius / 2;
  pong.pos.y = WINDOW_HEIGHT / 2 - pong.radius / 2;
  pong.speedx = 500;
  pong.speedy = 100;
  pong.color = WHITE;

  while (!WindowShouldClose())
  {
    pong.updatepos();
    pong.bordervertical();

    BeginDrawing();
    ClearBackground(BLUE);

    pong.draw();

    DrawFPS(0, 0);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
