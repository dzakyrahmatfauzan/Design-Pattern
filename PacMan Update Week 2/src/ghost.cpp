#include "Ghost.h"
#include "GhostState.h"
#include <iostream>

Ghost::Ghost(const std::string& name) : name(name), state(nullptr), x(0), y(0) {}

Ghost::~Ghost() {
    if (state) {
        delete state;
    }
}

void Ghost::update(const Pacman &pacman, const Map &map) {
    if (state) {
        state->update(this, pacman, map);
    } else {
        std::cout << name << " tidak memiliki state, idle." << std::endl;
    }
}

void Ghost::setState(GhostState* newState) {
    if (state) {
        delete state;
    }
    state = newState;
}

std::string Ghost::getName() const {
    return name;
}
