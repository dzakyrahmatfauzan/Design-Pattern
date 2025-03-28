#ifndef GHOST_H
#define GHOST_H

#include <string>
#include "GhostState.h"
#include "Pacman.h"
#include "Map.h"

class Ghost {
public:
    int x, y; // posisi ghost
    Ghost(const std::string& name);
    ~Ghost();
    
    // Update ghost berdasarkan posisi Pacman dan peta
    void update(const Pacman &pacman, const Map &map);
    void setState(GhostState* state);
    std::string getName() const;
    
private:
    std::string name;
    GhostState* state;
};

#endif // GHOST_H
