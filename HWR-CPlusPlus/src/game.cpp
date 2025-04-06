// Game.cpp
#include "Game.h"
#include <iostream>

Game::Game() : player1('X'), player2('O'), currentPlayer(&player1) {
    // Initialisierung des Spiels
    std::cout << "Spiel gestartet" << std::endl;
}

void Game::handleInput(const sf::Event& event) {
    if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        int x = mouseButtonPressed->position.x / board.getCellSize();
        int y = mouseButtonPressed->position.y / board.getCellSize();
        std::cout << "Mausklick bei (" << x << ", " << y << ")" << std::endl;
        if (board.placeMark(x, y, currentPlayer->getMark())) {
            std::cout << "Markierung gesetzt bei (" << x << ", " << y << ")" << std::endl;
            if (checkWin()) {
                std::cout << "Spieler " << currentPlayer->getMark() << " hat gewonnen!" << std::endl;
                // Siegeslogik hier hinzufügen
            }
            else {
                switchPlayer();
            }
        }
    }
}


void Game::update() {
    // Aktualisierungslogik hier hinzufügen
}

void Game::render(sf::RenderWindow& window) {
    board.render(window);
}

bool Game::checkWin() {
    // Siegesbedingungen prüfen
    return board.checkWin(currentPlayer->getMark());
}

void Game::switchPlayer() {
    if (currentPlayer == &player1) {
        currentPlayer = &player2;
    }
    else {
        currentPlayer = &player1;
    }
    std::cout << "Spieler gewechselt zu " << currentPlayer->getMark() << std::endl;
}
