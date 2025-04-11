#include <stdio.h>
#include <stdbool.h>
#include "include/raylib.h"

#include "global.hpp"
#include "pong.hpp"
#include "player.hpp"

int main()
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(WINDOW_FPS);

  bool isinmenu = true;

  pong pong;
  pong.radius = 25;
  pong.pos.x = WINDOW_WIDTH / 2 - pong.radius / 2;
  pong.pos.y = WINDOW_HEIGHT / 2 - pong.radius / 2;
  pong.speedx = 500;
  pong.speedy = 80;
  pong.color = WHITE;

  player player1;
  player1.posz.width = 20;
  player1.posz.height = 150;
  player1.posz.x = 0;
  player1.posz.y = 0;
  player1.speedy = 500;
  player1.color = WHITE;
  player1.keyup = KEY_W;
  player1.keydown = KEY_S;

  player player2;
  player2.posz.width = 20;
  player2.posz.height = 150;
  player2.posz.x = WINDOW_WIDTH - player2.posz.width;
  player2.posz.y = 0;
  player2.speedy = 500;
  player2.color = WHITE;
  player2.keyup = KEY_P;
  player2.keydown = KEY_L;

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLUE);

    if (isinmenu == true)
    {
      DrawText("press enter", 0, 0, 50, WHITE);
      if (IsKeyPressed(KEY_ENTER))
      {
        isinmenu = false;
      }
    }

    if (isinmenu == false)
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

      pong.draw();
      player1.draw();
      player2.draw();

      DrawFPS(0, 0);
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}