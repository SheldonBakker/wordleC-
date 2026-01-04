#include "ui/InputHandler.hpp"

InputResult InputHandler::processEvent(const sf::Event& event) {
    InputResult result;

    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        sf::Keyboard::Key key = keyPressed->code;

        if (key == sf::Keyboard::Key::Enter) {
            result.action = InputAction::SubmitGuess;
            return result;
        }

        if (key == sf::Keyboard::Key::Backspace) {
            result.action = InputAction::RemoveLetter;
            return result;
        }

        if (key == sf::Keyboard::Key::Escape) {
            result.action = InputAction::NewGame;
            return result;
        }

        char c = keyToChar(key);
        if (isValidLetter(c)) {
            result.action = InputAction::AddLetter;
            result.letter = c;
            return result;
        }
    }

    if (event.is<sf::Event::Closed>()) {
        result.action = InputAction::Quit;
        return result;
    }

    return result;
}

bool InputHandler::isValidLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

char InputHandler::keyToChar(sf::Keyboard::Key key) {
    if (key >= sf::Keyboard::Key::A && key <= sf::Keyboard::Key::Z) {
        return 'A' + static_cast<int>(key) - static_cast<int>(sf::Keyboard::Key::A);
    }
    return '\0';
}
