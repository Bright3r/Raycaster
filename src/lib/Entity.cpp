
#include "../include/Entity.hpp"

Entity::Entity(int x, int y, int width, int height, Color color) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->color = color;
  this->move_dir = { false, false, false, false };
  this->rect = { x, y, width, height };
}

Entity::~Entity() {
}

void Entity::update(std::vector<std::vector<char>>& map, int tile_size) {
    static const int MOVE_SPEED = 5;

    // Calculate the angle that the player is moving
    int move_x = -move_dir.left + move_dir.right;
    int move_y = -move_dir.up + move_dir.down;

    if (move_x == 0 && move_y == 0) {
        return;  // No movement
    }

    double move_angle = atan2(static_cast<double>(move_y), static_cast<double>(move_x));

    // Calculate X and Y components of movement
    double move_dx = MOVE_SPEED * cos(move_angle);
    double move_dy = MOVE_SPEED * sin(move_angle);

    // Move Vertically
    if (move_dir.up || move_dir.down) {
        this->y += static_cast<int>(move_dy);
        this->rect.y += static_cast<int>(move_dy);

        if (checkMapCollisions(map, this->rect, tile_size)) {
            this->y -= static_cast<int>(move_dy);
            this->rect.y -= static_cast<int>(move_dy);
        }
    }

    // Move Horizontally
    if (move_dir.left || move_dir.right) {
        this->x += static_cast<int>(move_dx);
        this->rect.x += static_cast<int>(move_dx);

        if (checkMapCollisions(map, this->rect, tile_size)) {
            this->x -= static_cast<int>(move_dx);
            this->rect.x -= static_cast<int>(move_dx);
        }
    }

    // Reset input directions
    this->move_dir = { false, false, false, false };
}
