#ifndef GHOST_H
#define GHOST_H

class Ghost {
private:
    int x, y;
public:
    Ghost(int startX, int startY);
    int getX() const;
    int getY() const;
};

#endif
