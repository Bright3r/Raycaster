
#include "../include/Entity.hpp"

Entity::Entity(int x, int y, int width, int height, Color color) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->color = color;
  this->move_dir = { false, false, false, false };
}

Entity::~Entity() {
}

void Entity::update() {
  static const int MOVE_SPEED = 5;

  // Calculate the angle that the player is moving
  int move_x = -move_dir.left + move_dir.right;
  int move_y = -move_dir.up + move_dir.down;
  double move_angle = atan2((double) move_y, (double) move_x);

  // Calculate X and Y components of movement
  double move_dx = MOVE_SPEED * cos(move_angle);
  double move_dy = MOVE_SPEED * sin(move_angle);
  
  // Move Vertically
  if (move_dir.up) {
    this->y += move_dy;
  }
  if (move_dir.down) {
    this->y += move_dy;
  }

  // Move Horizontally
  if (!(move_dir.left && move_dir.right)) {
    if (move_dir.left) {
      this->x += move_dx;
    }
    if (move_dir.right) {
      this->x += move_dx;
    }
  }

  // Reset input directions
  this->move_dir = { false, false, false, false };
}
