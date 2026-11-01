# «Монополия» үстел ойыны C++ ООП Жобасы

ТАӘ: Жартыбай Аңсар Ермұратұлы
Тобы:Монополия
Нұсқа: 2 (Үстел ойыны «Монополия»)

Архитектура:
1. Статикалық мүше: `Board::totalGamesPlayed` және `Board::getTotalGames()`
2. Дос функция: `displayPlayerInfo(const Player& player)`
3. Кірістірілген класс: `Player::PlayerStats`
4. Объектілер жиыны: `std::vector<Player>` және `std::vector<Cell*>`
5. Композиция: `MonopolyGame` құрамында `Board` және `Dice`
6. Агрегация: `Board` құрамында `Cell*` pointer-лері
7. Мұрагерлік: Базалық `Cell` класы -> `PropertyCell` және `SpecialCell` туынды кластары
