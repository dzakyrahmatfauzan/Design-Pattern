#include "ghost.h"

Ghost::Ghost(int startX, int startY) : x(startX), y(startY) {}

int Ghost::getX() const { return x; }
int Ghost::getY() const { return y; }
