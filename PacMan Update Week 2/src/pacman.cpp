#include "Pacman.h"
#include "Map.h"
#include <iostream>

Pacman::Pacman() {
    // Posisi awal Pacman (pastikan tidak berada di dinding)
    x = 1;
    y = 1;
}

void Pacman::move(char direction, const Map& map) {
    int newX = x;
    int newY = y;
    switch(direction) {
        case 'w': case 'W':
            newY -= 1;
            break;
        case 'a': case 'A':
            newX -= 1;
            break;
        case 's': case 'S':
            newY += 1;
            break;
        case 'd': case 'D':
            newX += 1;
            break;
        default:
            return;
    }
    // Cek apakah posisi baru valid (bukan dinding)
    if(newX >= 0 && newX < map.getWidth() &&
       newY >= 0 && newY < map.getHeight() &&
       map.getTile(newX, newY) != '#') {
        x = newX;
        y = newY;
        std::cout << "Pacman bergerak ke " << direction << std::endl;
    } else {
        std::cout << "Gerakan " << direction << " terhalang dinding." << std::endl;
    }
}
