#pragma once

#include <SFML/Window/Event.hpp>

enum class InputAction {
    None,
    AddLetter,
    RemoveLetter,
    SubmitGuess,
    NewGame,
    Quit
};

struct InputResult {
    InputAction action = InputAction::None;
    char letter = '\0';
};

class InputHandler {
public:
    InputHandler() = default;
    ~InputHandler() = default;

    InputResult processEvent(const sf::Event& event);

private:
    static bool isValidLetter(char c);
    static char keyToChar(sf::Keyboard::Key key);
};
