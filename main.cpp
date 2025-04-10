
// todo: make the player better


#include "include/raylib.h"

#include "global.hpp"
#include "pong.hpp"
#include "player.hpp"

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

  player player1;
  player1.posz.width = 10;
  player1.posz.height = 100;
  player1.speedy = 500;
  player1.color = WHITE;
  player1.keyup = KEY_W;
  player1.keydown = KEY_S;

  while (!WindowShouldClose())
  {
    pong.updatepos();
    pong.bordervertical();

    player1.input();

    BeginDrawing();
    ClearBackground(BLUE);

    pong.draw();
    player1.draw();

    DrawFPS(0, 0);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
