#include "pacman.h"

Pacman::Pacman(int startX, int startY) : x(startX), y(startY) {}

void Pacman::move(char direction, char map[][10]) {
    int newX = x, newY = y;

    if (direction == 'w') newX--;  // Atas
    if (direction == 's') newX++;  // Bawah
    if (direction == 'a') newY--;  // Kiri
    if (direction == 'd') newY++;  // Kanan

    if (map[newX][newY] != '#') {
        map[x][y] = '.';  // Hapus posisi lama
        x = newX;
        y = newY;
    }

    map[x][y] = 'P';  // Tempatkan Pac-Man di posisi baru
}

// **Tambahkan ini agar tidak error**
int Pacman::getX() const { return x; }
int Pacman::getY() const { return y; }
