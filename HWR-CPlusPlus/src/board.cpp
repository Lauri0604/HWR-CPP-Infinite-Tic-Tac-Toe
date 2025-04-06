// Board.cpp
#include "Board.h"
#include <iostream>

Board::Board() {
    // Initialisierung des Spielfelds
    if (!font.openFromFile("assets/ARIAL.TTF")) {
        // Fehlerbehandlung
        throw std::runtime_error("Konnte Schriftart nicht laden");
    }
    else {
		// Schriftart erfolgreich geladen
        // Ausgabe Schriftart laden erfolreich
		std::cout << "Schriftart erfolgreich geladen" << std::endl;
    }
}

// Methode zur Rückgabe der Zellgröße
unsigned int Board::getCellSize() const {
    return cellSize;
}

// Platzieren eines Marks auf dem Spielfeld
bool Board::placeMark(int x, int y, char mark) {
    std::cout << "Versuche Markierung zu setzen bei (" << x << ", " << y << ")" << std::endl;
    if (grid[x][y] == '\0') {
        grid[x][y] = mark;
		std::cout << "Markierung gesetzt: " << mark << " bei (" << x << ", " << y << ")" << std::endl;
        return true;
	}
	else {
		std::cout << "Platz bereits belegt!" << std::endl;
	}
    return false;
}

// Überprüfen, ob ein Spieler gewonnen hat
bool Board::checkWin(char mark) {
    for (const auto& row : grid) {
        for (const auto& cell : row.second) {
            int x = row.first;
            int y = cell.first;
            if (cell.second == mark) {
                if (checkDirection(x, y, 1, 0, mark) || // Horizontal
                    checkDirection(x, y, 0, 1, mark) || // Vertikal
                    checkDirection(x, y, 1, 1, mark) || // Diagonal nach unten rechts
                    checkDirection(x, y, 1, -1, mark)) { // Diagonal nach oben rechts
					std::cout << "Gewonnen: " << mark << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}

// Überprüfen der Richtung auf eine bestimmte Anzahl von aufeinanderfolgenden Markierungen
bool Board::checkDirection(int x, int y, int dx, int dy, char mark) {
    int count = 0;
    for (int i = 0; i < winCondition; ++i) {
        if (grid[x + i * dx][y + i * dy] == mark) {
            count++;
			std::cout << "Überprüfung: " << mark << " bei (" << x + i * dx << ", " << y + i * dy << ")" << std::endl;
        }
        else {
			std::cout << "Überprüfung fehlgeschlagen: " << mark << " bei (" << x + i * dx << ", " << y + i * dy << ")" << std::endl;
            break;
        }
    }
    return count == winCondition;
}

void Board::render(sf::RenderWindow& window) {
    // Raster zeichnen
    sf::RectangleShape line;
    line.setFillColor(sf::Color::Black);
	// Ausgabe Rastergröße
	std::cout << "Rastergröße: " << grid.size() << std::endl;

    // Vertikale Linien
    for (unsigned int x = 0; x <= window.getSize().x; x += cellSize) {
        line.setSize(sf::Vector2f(1, window.getSize().y));
        line.setPosition(sf::Vector2f(static_cast<float>(x), 0));
        window.draw(line);
    }

    // Horizontale Linien
    for (unsigned int y = 0; y <= window.getSize().y; y += cellSize) {
        line.setSize(sf::Vector2f(window.getSize().x, 1));
        line.setPosition(sf::Vector2f(0, static_cast<float>(y)));
        window.draw(line);
    }

    // Markierungen zeichnen
    for (const auto& row : grid) {
        for (const auto& cell : row.second) {
            int x = row.first;
            int y = cell.first;
            char mark = cell.second;

            sf::Text text(font);
            text.setFont(font);
            text.setString(mark);
            text.setCharacterSize(cellSize - 2);
            text.setFillColor(sf::Color::Red);
            text.setPosition(sf::Vector2f(x * cellSize, y * cellSize));


            window.draw(text);
			// Ausgabe Markierung
			std::cout << "Markierung: " << mark << " bei (" << x << ", " << y << ")" << std::endl;
			// Ausgabe Position der Markierung
			std::cout << "Position: (" << x * cellSize << ", " << y * cellSize << ")" << std::endl;
			// Ausgabe Schriftgröße
			std::cout << "Schriftgröße: " << text.getCharacterSize() << std::endl;

        }
    }
}



