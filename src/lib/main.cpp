
#include "../include/main.hpp"

int main(int argc, char *argv[]) {
  InitWindow(800, 800, "Raylib");
  SetTargetFPS(60);

  Entity player(250, 250, 50, 50, pink);

  bool is_running = true;
  while (WindowShouldClose() == false && is_running) {
    if (IsKeyPressed(KEY_ENTER)) {
      is_running = false;
    }

    if (IsKeyDown(KEY_W)) {
      player.move_dir.up = true;
    }
    if (IsKeyDown(KEY_S)) {
      player.move_dir.down = true;
    }
    if (IsKeyDown(KEY_A)) {
      player.move_dir.left = true;
    }
    if (IsKeyDown(KEY_D)) {
      player.move_dir.right = true;
    }

    // Game Logic
    player.update();

    // Start Drawing
    BeginDrawing();
    ClearBackground(aqua);

    drawEntity(player);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void drawEntity(Entity& ent) {
  DrawRectangle(ent.x, ent.y, ent.width, ent.height, ent.color);
}
