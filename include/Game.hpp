#pragma once

#include "GameState.hpp"
#include "WordValidator.hpp"
#include "ui/Renderer.hpp"
#include "ui/InputHandler.hpp"
#include "ui/Animation.hpp"
#include <string>

class Game {
public:
    Game();
    ~Game() = default;

    bool initialize();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void startNewGame();
    void handleGuessSubmission();

    GameState gameState_;
    WordValidator wordValidator_;
    Renderer renderer_;
    InputHandler inputHandler_;
    AnimationManager animations_;

    bool isRunning_;
    bool showInvalidMessage_;
    float invalidMessageTimer_;

    std::string currentMessage_;
    sf::Color messageColor_;
    sf::Clock clock_;

    static constexpr float INVALID_MESSAGE_DURATION = 1.5f;
};
