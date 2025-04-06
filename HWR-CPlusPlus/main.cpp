#include "SFML/Graphics.hpp"
#include "src/game.h"
#include "src/board.h"
#include "src/player.h"
#include <optional>
#include <iostream>

using namespace sf;

int main() {
	// SFML-Version ausgeben
    std::cout << "SFML Version: " << SFML_VERSION_MAJOR << "." << SFML_VERSION_MINOR << std::endl;

    // Fenster erstellen
    sf::RenderWindow window(VideoMode({ 1920, 1080 }), "Infinite Tic Tac Toe");

    // Spielobjekt erstellen
    Game game;

    // Hauptschleife
    while (window.isOpen()) {
        while (const std::optional<Event> event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<Event::KeyPressed>()) {
                if (keyPressed->code == Keyboard::Key::Escape) {
                    window.close();
                }
            }

            // Eingaben an das Spiel weiterleiten
            game.handleInput(*event);
        }

        // Spielzustand aktualisieren
        game.update();

        // Alles rendern
        window.clear();
        game.render(window);
        window.display();
    }

    return 0;
}
