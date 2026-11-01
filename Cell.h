#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>

// Базалық класс (Мұрагерлік)
class Cell {
protected:
    std::string name;
    int position;
public:
    Cell(const std::string& n, int pos) : name(n), position(pos) {}
    virtual ~Cell() {}

    std::string getName() const { return name; }
    int getPosition() const { return position; }

    virtual void onStepOn() = 0; // Виртуалды әдіс
};

// Туынды класс 1: Мүлік ұяшығы
class PropertyCell : public Cell {
private:
    int price;
    int rent;
    bool isOwned;
    std::string ownerName;
public:
    PropertyCell(const std::string& n, int pos, int p, int r)
        : Cell(n, pos), price(p), rent(r), isOwned(false), ownerName("Ешкім") {}

    int getPrice() const { return price; }
    int getRent() const { return rent; }
    bool getIsOwned() const { return isOwned; }
    std::string getOwnerName() const { return ownerName; }

    void setOwner(const std::string& owner) {
        ownerName = owner;
        isOwned = true;
    }

    void onStepOn() override {
        std::cout << "[Ұяшық] " << name << " мүлігіне тоқтадыңыз. Бағасы: " 
                  << price << ", Жалдау ақысы: " << rent << "\n";
    }
};

// Туынды класс 2: Арнайы ұяшық (мысалы, Старт немесе Салық)
class SpecialCell : public Cell {
private:
    int bonusOrPenalty;
public:
    SpecialCell(const std::string& n, int pos, int value)
        : Cell(n, pos), bonusOrPenalty(value) {}

    void onStepOn() override {
        std::cout << "[Арнайы ұяшық] " << name << " ұяшығына түстіңіз. Әсері: " 
                  << bonusOrPenalty << "\n";
    }
};

#endif
