#include "GameManager.h"
#include "GhostFactory.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>  // Khusus Windows: _kbhit() dan _getch()

GameManager::GameManager() {
    init();
}

GameManager::~GameManager() {
    for (auto ghost : ghosts) {
        delete ghost;
    }
}

void GameManager::init() {
    // Inisialisasi peta yang sedikit disesuaikan agar lebih playable
    map.loadMap();
    
    // Buat 4 ghost dengan tipe yang berbeda
    ghosts.push_back(GhostFactory::createGhost("Blinky"));
    ghosts.push_back(GhostFactory::createGhost("Pinky"));
    ghosts.push_back(GhostFactory::createGhost("Inky"));
    ghosts.push_back(GhostFactory::createGhost("Clyde"));
}

void GameManager::run() {
    bool running = true;
    while (running) {
        if (_kbhit()) {
            char input = _getch();
            if (input == 'x' || input == 'X') {
                running = false;
                break;
            }
            pacman.move(input, map);
        }
        
        update();
        render();

        // Cek tabrakan antara Pacman dan ghost
        for (auto ghost : ghosts) {
            if (ghost->x == pacman.x && ghost->y == pacman.y) {
                system("cls");
                map.render(pacman.x, pacman.y, ghosts);
                std::cout << "\nGame Over! Pacman tertangkap oleh " << ghost->getName() << "!" << std::endl;
                running = false;
                break;
            }
        }
        
        // Tambahkan delay agar tampilan tidak berkedip terlalu cepat
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void GameManager::update() {
    // Update ghost dengan posisi Pacman dan peta
    for (auto ghost : ghosts) {
        ghost->update(pacman, map);
    }
}

void GameManager::render() {
    system("cls");
    // Panggil render baru yang juga menampilkan ghost
    map.render(pacman.x, pacman.y, ghosts);
    std::cout << "\nGunakan WASD untuk bergerak, X untuk keluar." << std::endl;
}
