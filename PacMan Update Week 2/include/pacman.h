#ifndef PACMAN_H
#define PACMAN_H

class Map; // Forward declaration

class Pacman {
public:
    int x, y; // posisi saat ini pada peta
    Pacman();
    // Menggerakkan Pacman berdasarkan input arah: 'w', 'a', 's', 'd'
    void move(char direction, const Map& map);
};

#endif // PACMAN_H
