#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "Cell.h"

class Player {
private:
    std::string name;
    int money;
    int currentPosition;
    std::vector<PropertyCell*> ownedProperties; // Агрегация

    // Кірістірілген класс (Nested Class)
    class PlayerStats {
    public:
        int turnsPlayed;
        int totalSpent;
        PlayerStats() : turnsPlayed(0), totalSpent(0) {}
    } stats;

public:
    Player(const std::string& n, int initialMoney = 1500)
        : name(n), money(initialMoney), currentPosition(0) {}

    std::string getName() const { return name; }
    int getMoney() const { return money; }
    int getPosition() const { return currentPosition; }

    void move(int steps, int boardSize) {
        currentPosition = (currentPosition + steps) % boardSize;
        stats.turnsPlayed++;
    }

    void buyProperty(PropertyCell* prop) {
        if (money >= prop->getPrice() && !prop->getIsOwned()) {
            money -= prop->getPrice();
            stats.totalSpent += prop->getPrice();
            prop->setOwner(name);
            ownedProperties.push_back(prop);
            std::cout << name << " " << prop->getName() << " мүлігін сатып алды!\n";
        } else {
            std::cout << name << " мүлікті сатып ала алмады.\n";
        }
    }

    void payRent(int amount) {
        money -= amount;
        stats.totalSpent += amount;
    }

    void addMoney(int amount) {
        money += amount;
    }

    friend void displayPlayerInfo(const Player& player);
};

inline void displayPlayerInfo(const Player& player) {
    std::cout << "--- " << player.name << " туралы ақпарат ---\n";
    std::cout << "Баланс: " << player.money << "$\n";
    std::cout << "Орналасқан орны: " << player.currentPosition << "-ұяшық\n";
    std::cout << "Жасалған жүрістер саны: " << player.stats.turnsPlayed << "\n";
    std::cout << "Жалпы жұмсалған ақша: " << player.stats.totalSpent << "$\n";
    std::cout << "Сатып алған мүліктері: " << player.ownedProperties.size() << "\n";
}

#endif
