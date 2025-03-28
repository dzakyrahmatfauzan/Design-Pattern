#include "Map.h"
#include <iostream>
#include "Ghost.h"

Map::Map() {
    // Konstruktor bila diperlukan
}

void Map::loadMap() {
    // Layout peta: 7 baris x 40 kolom
    mapData.clear();
    mapData.push_back("########################################");
    mapData.push_back("#............##............##..........#");
    mapData.push_back("#.####.#####.##.#####.####.##.#######..#");
    mapData.push_back("#.......................................#");
    mapData.push_back("#.####.##.########.##.####.##.#######..#");
    mapData.push_back("#......##....##....##......##..........#");
    mapData.push_back("########################################");
}

void Map::render(int pacmanX, int pacmanY, const std::vector<Ghost*>& ghosts) {
    std::vector<std::string> buffer = mapData;
    
    // Sisipkan Pacman
    if(pacmanY >= 0 && pacmanY < static_cast<int>(buffer.size()) &&
       pacmanX >= 0 && pacmanX < static_cast<int>(buffer[pacmanY].size()))
    {
        buffer[pacmanY][pacmanX] = 'P';
    }
    
    // Sisipkan ghost (gunakan huruf awal nama ghost)
    for (auto ghost : ghosts) {
        int gx = ghost->x;
        int gy = ghost->y;
        if(gy >= 0 && gy < static_cast<int>(buffer.size()) &&
           gx >= 0 && gx < static_cast<int>(buffer[gy].size()))
        {
            // Jika posisi ghost sama dengan Pacman, prioritas tampilkan Pacman
            if(gx == pacmanX && gy == pacmanY)
                continue;
            char symbol = ghost->getName()[0]; // ambil huruf pertama
            buffer[gy][gx] = symbol;
        }
    }
    
    // Tampilkan peta
    for (const auto &line : buffer) {
        std::cout << line << std::endl;
    }
}

char Map::getTile(int x, int y) const {
    if(y >= 0 && y < static_cast<int>(mapData.size()) &&
       x >= 0 && x < static_cast<int>(mapData[y].size()))
    {
        return mapData[y][x];
    }
    return ' ';
}

int Map::getWidth() const {
    if(!mapData.empty()){
        return mapData[0].size();
    }
    return 0;
}

int Map::getHeight() const {
    return mapData.size();
}
