#include "GameManager.h"
#include <cstdlib>
#include <ctime>

int main() {
    // Seed untuk fungsi random (berguna untuk FrightenedState)
    srand(static_cast<unsigned int>(time(NULL)));
    GameManager game;
    game.run();
    return 0;
}
