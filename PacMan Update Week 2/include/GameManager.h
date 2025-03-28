#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Map.h"
#include "Pacman.h"
#include "Ghost.h"
#include <vector>

class GameManager {
public:
    GameManager();
    ~GameManager();
    void run();

private:
    Map map;
    Pacman pacman;
    std::vector<Ghost*> ghosts;

    void init();
    void update();
    void render();
    void handleInput(); // (Optional: bila ingin dipisah)
};

#endif // GAMEMANAGER_H
