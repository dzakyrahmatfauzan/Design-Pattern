#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
class Ghost; // forward declaration

class Map {
public:
    Map();
    void loadMap();
    // Render peta dengan menampilkan posisi Pacman dan ghost
    void render(int pacmanX, int pacmanY, const std::vector<Ghost*>& ghosts);
    char getTile(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
    
private:
    std::vector<std::string> mapData;
};

#endif // MAP_H
