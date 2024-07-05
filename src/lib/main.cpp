
#include "../include/main.hpp"

const int tile_size = 50;

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> map = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  };
  Entity player(250, 250, tile_size / 2, tile_size / 2, pink);

  InitWindow(map[0].size() * tile_size, map.size() * tile_size, "Raylib");
  SetTargetFPS(60);

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
    player.update(map, tile_size);

    // Start Drawing
    BeginDrawing();
    ClearBackground(aqua);

    drawMap(map, tile_size);
    drawEntity(player);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void drawEntity(Entity& ent) {
  DrawRectangle(ent.x, ent.y, ent.width, ent.height, ent.color);
}

void drawMap(std::vector<std::vector<char>>& map, int tile_size) {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[0].size(); j++) {
      if (map[i][j] > 0) {
        DrawRectangle(j * tile_size, i * tile_size, tile_size, tile_size, black);
      }
    }
  }
}




