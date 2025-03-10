#ifndef MAP_H
#define MAP_H

#include <iostream>

const int WIDTH = 10;
const int HEIGHT = 10;

class Map {
public:
    char grid[HEIGHT][WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '.', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', 'P', '.', '#', '#', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    void render(int pacX, int pacY);
};

#endif
