#pragma once

#include "../include/Utils.hpp"

bool checkCollision(Rectangle rect1, Rectangle rect2) {
  if (rect1.x < rect2.x + rect2.width && rect1.x + rect1.width > rect2.x && rect1.y < rect2.y + rect2.height && rect1.y + rect1.height > rect2.y) {
    return true;
  }

  return false;
}

bool checkMapCollisions(std::vector<std::vector<char>>& map, Rectangle& rect, int tile_size) {
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[0].size(); j++) {
      if (map[i][j] <= 0) {
        continue;
      }

      Rectangle map_rect = { j * tile_size, i * tile_size, tile_size, tile_size };
      if (checkCollision(map_rect, rect)) {
        return true;
      }
    }
  }

  return false;
}
