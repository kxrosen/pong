#include <stdio.h>
#include "include/raylib.h"

#include "global.hpp"
#include "pong.hpp"
#include "player.hpp"

int main()
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(WINDOW_FPS);

  pong pong;
  pong.radius = 30;
  pong.pos.x = WINDOW_WIDTH / 2 - pong.radius / 2;
  pong.pos.y = WINDOW_HEIGHT / 2 - pong.radius / 2;
  pong.speedx = 500;
  pong.speedy = 80;
  pong.color = WHITE;

  player player1;
  player1.posz.width = 15;
  player1.posz.height = 100;
  player1.posz.x = 0;
  player1.posz.y = 0;
  player1.speedy = 500;
  player1.color = WHITE;
  player1.keyup = KEY_W;
  player1.keydown = KEY_S;

  player player2;
  player2.posz.width = 15;
  player2.posz.height = 100;
  player2.posz.x = WINDOW_WIDTH - player2.posz.width;
  player2.posz.y = 0;
  player2.speedy = 500;
  player2.color = WHITE;
  player2.keyup = KEY_P;
  player2.keydown = KEY_L;

  while (!WindowShouldClose())
  {
    pong.updatepos();
    pong.bordervertical();

    player1.input();
    player2.input();

    player1.collisionwithpong(&pong);
    player2.collisionwithpong(&pong);

    player1.GODMODE(&pong);
    player2.GODMODE(&pong);

    player1.bordervertical();
    player2.bordervertical();

    BeginDrawing();
    ClearBackground(BLUE);

    pong.draw();
    player1.draw();
    player2.draw();

    DrawFPS(0, 0);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
