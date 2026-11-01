#ifndef MONOPOLYGAME_H
#define MONOPOLYGAME_H

#include <vector>
#include "Player.h"
#include "Board.h"
#include "Dice.h"

class MonopolyGame {
private:
    Board board;
    Dice dice;
    std::vector<Player> players; 

public:
    MonopolyGame() : dice(6) {}

    void addPlayer(const Player& player) {
        players.push_back(player);
    }

    void startGame() {
        Board::incrementGames();
        std::cout << "\n================ ОЙЫН БАСТАЛДЫ ================\n";
        std::cout << "Жалпы ойналған ойындар саны: " << Board::getTotalGames() << "\n\n";

        for (int turn = 1; turn <= 2; ++turn) { // 2 айналым симуляциясы
            std::cout << "=== Айналым " << turn << " ===\n";
            for (auto& player : players) {
                int roll = dice.roll();
                std::cout << player.getName() << " суйекті лақтырды: " << roll << "\n";
                
                player.move(roll, board.getSize());
                Cell* currentCell = board.getCell(player.getPosition());
                
                currentCell->onStepOn();

                // Егер мүлік ұяшығы болса, сатып алу логикасы
                PropertyCell* prop = dynamic_cast<PropertyCell*>(currentCell);
                if (prop && !prop->getIsOwned()) {
                    player.buyProperty(prop);
                }

                std::cout << "-----------------------------------\n";
            }
        }
    }

    void showResults() {
        std::cout << "\n================ ОЙЫН НӘТИЖЕСІ ================\n";
        for (const auto& player : players) {
            displayPlayerInfo(player); 
            std::cout << "\n";
        }
    }
};

#endif
