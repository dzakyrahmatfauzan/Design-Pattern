#include "GhostFactory.h"
#include "Ghost.h"
#include "GhostState.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Ghost* GhostFactory::createGhost(const std::string& type) {
    Ghost* ghost = new Ghost(type);
    
    // Tentukan state awal dan posisi berdasarkan tipe ghost
    if(type == "Blinky") {
        ghost->setState(new ChaseState());
        ghost->x = 37; ghost->y = 1; // misal pojok kanan atas (dalam peta 40 kolom)
    } else if (type == "Pinky") {
        ghost->setState(new ScatterState());
        ghost->x = 37; ghost->y = 5; // misal pojok kanan bawah
    } else if (type == "Inky") {
        ghost->setState(new FrightenedState());
        ghost->x = 2; ghost->y = 5; // misal pojok kiri bawah
    } else if (type == "Clyde") {
        ghost->setState(new ChaseState());
        ghost->x = 20; ghost->y = 3; // posisi tengah
    }
    
    std::cout << "Ghost " << type << " telah dibuat di (" 
              << ghost->x << "," << ghost->y << ")." << std::endl;
    return ghost;
}
