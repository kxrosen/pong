#include "include/raylib.h"

int main()
{
  InitWindow(100, 100, "test");

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLUE);

    DrawText("I'M WORKING", 0, 0, 20, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
