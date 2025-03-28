#include "GhostState.h"
#include "Ghost.h"
#include "Pacman.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

// Fungsi pembantu untuk mengecek apakah pergerakan valid
bool isValidMove(int x, int y, const Map &map) {
    return (x >= 0 && x < map.getWidth() &&
            y >= 0 && y < map.getHeight() &&
            map.getTile(x, y) != '#');
}

void ChaseState::update(Ghost* ghost, const Pacman& pacman, const Map &map) {
    // Gerak 1 langkah menuju Pacman
    int dx = pacman.x - ghost->x;
    int dy = pacman.y - ghost->y;
    int stepX = 0, stepY = 0;
    if (std::abs(dx) > std::abs(dy)) {
        stepX = (dx > 0) ? 1 : -1;
    } else {
        stepY = (dy > 0) ? 1 : -1;
    }
    int newX = ghost->x + stepX;
    int newY = ghost->y + stepY;
    if(isValidMove(newX, newY, map)) {
        ghost->x = newX;
        ghost->y = newY;
    }
    std::cout << ghost->getName() << " (Chase) bergerak ke (" 
              << ghost->x << "," << ghost->y << ")" << std::endl;
}

void ScatterState::update(Ghost* ghost, const Pacman& pacman, const Map &map) {
    // Tentukan target scatter berdasarkan nama ghost
    int targetX = 0, targetY = 0;
    if (ghost->getName() == "Blinky") {
        targetX = map.getWidth() - 2; targetY = 1;
    } else if (ghost->getName() == "Pinky") {
        targetX = 1; targetY = 1;
    } else if (ghost->getName() == "Inky") {
        targetX = map.getWidth() - 2; targetY = map.getHeight() - 2;
    } else if (ghost->getName() == "Clyde") {
        targetX = 1; targetY = map.getHeight() - 2;
    }
    int dx = targetX - ghost->x;
    int dy = targetY - ghost->y;
    int stepX = 0, stepY = 0;
    if (std::abs(dx) > std::abs(dy)) {
        stepX = (dx > 0) ? 1 : -1;
    } else {
        stepY = (dy > 0) ? 1 : -1;
    }
    int newX = ghost->x + stepX;
    int newY = ghost->y + stepY;
    if(isValidMove(newX, newY, map)) {
        ghost->x = newX;
        ghost->y = newY;
    }
    std::cout << ghost->getName() << " (Scatter) bergerak ke (" 
              << ghost->x << "," << ghost->y << ")" << std::endl;
}

void FrightenedState::update(Ghost* ghost, const Pacman& pacman, const Map &map) {
    // Gerak secara acak
    int directions[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    int idx = rand() % 4;
    int newX = ghost->x + directions[idx][0];
    int newY = ghost->y + directions[idx][1];
    if(isValidMove(newX, newY, map)) {
        ghost->x = newX;
        ghost->y = newY;
    }
    std::cout << ghost->getName() << " (Frightened) bergerak ke (" 
              << ghost->x << "," << ghost->y << ")" << std::endl;
}
