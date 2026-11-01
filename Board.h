#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include "Cell.h"

class Board {
private:
    std::vector<Cell*> cells; // Агрегация (көрсеткіштер векторы)
    
    // Статикалық өріс
    static int totalGamesPlayed;

public:
    Board() {
        // Ойын алаңын құру
        cells.push_back(new SpecialCell("Start", 0, 200));
        cells.push_back(new PropertyCell("Park", 1, 100, 10));
        cells.push_back(new PropertyCell("Street", 2, 150, 15));
        cells.push_back(new SpecialCell("Tax", 3, -50));
        cells.push_back(new PropertyCell("Hotel", 4, 300, 30));
    }

    ~Board() {
        for (auto cell : cells) {
            delete cell;
        }
    }

    int getSize() const { return cells.size(); }
    Cell* getCell(int index) { return cells[index % cells.size()]; }

    static static void incrementGames() {
        totalGamesPlayed++;
    }

    static int getTotalGames() {
        return totalGamesPlayed;
    }
};

#endif
