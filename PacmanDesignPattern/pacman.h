#ifndef PACMAN_H
#define PACMAN_H

class Pacman {
private:
    int x, y; // Posisi Pac-Man
public:
    Pacman(int startX, int startY);
    void move(char direction, char map[][10]); // Tambahkan parameter map untuk validasi
    int getX() const;
    int getY() const;
};

#endif
