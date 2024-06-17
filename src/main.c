#include <raylib.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "template");
  SetTargetFPS(60);

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
