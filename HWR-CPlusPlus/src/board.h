#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Board {
public:
    Board();
    bool placeMark(int x, int y, char mark);
    bool checkWin(char mark);
    void render(sf::RenderWindow& window);
    unsigned int getCellSize() const; // Methode zur R�ckgabe der Zellgr��e

private:
    std::unordered_map<int, std::unordered_map<int, char>> grid;
    bool checkDirection(int x, int y, int dx, int dy, char mark);
    const int winCondition = 5; // Anzahl der aufeinanderfolgenden Markierungen f�r einen Sieg
    const unsigned int cellSize = 20; // Gr��e einer Zelle im Raster
    sf::Font font; // Schriftart f�r die Markierungen
};

