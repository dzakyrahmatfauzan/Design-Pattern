#ifndef GHOSTSTATE_H
#define GHOSTSTATE_H

class Ghost;
class Pacman;
class Map;

// Abstract state untuk ghost
class GhostState {
public:
    virtual ~GhostState() {}
    // Update dengan mempertimbangkan posisi Pacman dan peta
    virtual void update(Ghost* ghost, const Pacman& pacman, const Map &map) = 0;
};

// State ketika ghost mengejar Pacman
class ChaseState : public GhostState {
public:
    void update(Ghost* ghost, const Pacman& pacman, const Map &map) override;
};

// State ketika ghost menyebar ke target scatter (ditentukan berdasarkan nama ghost)
class ScatterState : public GhostState {
public:
    void update(Ghost* ghost, const Pacman& pacman, const Map &map) override;
};

// State ketika ghost dalam keadaan ketakutan (bergerak acak)
class FrightenedState : public GhostState {
public:
    void update(Ghost* ghost, const Pacman& pacman, const Map &map) override;
};

#endif // GHOSTSTATE_H
