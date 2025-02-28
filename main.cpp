#include "map.h"
#include "pacman.h"
#include <conio.h>  // Untuk _kbhit() dan _getch()
#include <chrono>
#include <thread>

void clearScreen() {
    std::cout << "\033[2J\033[H"; // ANSI escape untuk membersihkan layar di Windows/Linux
}

int main() {
    Map gameMap;
    Pacman pacman(8, 1);  // Pac-Man mulai di posisi (8,1)

    char input;
    while (true) {
        clearScreen();  // Gantilah system("cls") dengan metode ini
        gameMap.render(pacman.getX(), pacman.getY());

        std::cout << "\nGunakan WASD untuk bergerak, tekan Q untuk keluar.\n";

        if (_kbhit()) {  // Jika ada input keyboard
            input = _getch();
            if (input == 'q') break;  // Keluar dari game
            pacman.move(input, gameMap.grid);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Delay untuk mengurangi flickering
    }

    return 0;
}
