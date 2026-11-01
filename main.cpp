#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MonopolyGame.h"

int main() {
    std::srand(std::time(0)); // Кездейсоқ сандар генераторын іске қосу

    MonopolyGame game;

    game.addPlayer(Player("Асан", 1500));
    game.addPlayer(Player("Үсен", 1500));

  
    game.startGame();
    game.showResults();
    return 0;
}
