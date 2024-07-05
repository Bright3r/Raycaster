#pragma once

#include <cmath>
#include <iostream>
#include "../lib/Utils.cpp"

typedef struct Move_Direction {
  bool up, down, left, right;
} Move_Direction;

class Entity {
  public:
    int x, y;
    int width, height;
    Rectangle rect;
    Color color;
    Move_Direction move_dir;

    Entity(int x, int y, int width, int height, Color color);
    ~Entity();
    void update(std::vector<std::vector<char>>& map, int tile_size);
};



