#pragma once

#include <raylib.h>
#include <vector>
#include "../lib/Entity.cpp"
#include "../lib/Utils.cpp"

Color black = { 0, 0, 0, 255 };
Color aqua = { 0, 255, 255, 255 };
Color pink = { 200, 50, 50, 255 };

void drawEntity(Entity& ent);
void drawMap(std::vector<std::vector<char>>& map, int tile_size);
