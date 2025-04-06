#pragma once
// Game.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

class Game {
public:
    Game();
    void handleInput(const sf::Event& event);
    void update();
    void render(sf::RenderWindow& window);

private:
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;
    bool checkWin();
    void switchPlayer();
};