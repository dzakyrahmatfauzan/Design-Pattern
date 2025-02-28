#include "map.h"

void Map::render(int pacX, int pacY) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == pacX && j == pacY)
                std::cout << 'P' << " ";  // Tampilkan Pac-Man di posisi sekarang
            else
                std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
