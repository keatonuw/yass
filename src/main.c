#include "yass.h"

#include "yass.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "template");
  SetTargetFPS(60);

  Snake *snake = create_snake((WorldPoint){0, 0}, (WorldPoint){3, 0});
  for (int i = snake->head; i < snake->tail; i++) {
    WorldPoint p = snake->positions_queue[i];
    printf("(%d, %d) ", p.x, p.y);
  }

  while (!WindowShouldClose()) {
    // Update

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello world!", 100, 100, 12, RED);
    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
