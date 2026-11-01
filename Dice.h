# Monopoly
#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <ctime>

class Dice {
private:
    int faces;
public:
    Dice(int f = 6) : faces(f) {}
    int roll() const {
        return (std::rand() % faces) + 1;
    }
};

#endif
