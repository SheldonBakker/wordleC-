#pragma once

#include <SFML/Graphics.hpp>
#include "../GameState.hpp"
#include "Grid.hpp"
#include "Animation.hpp"
#include <string>

class Renderer {
public:
    Renderer();
    ~Renderer() = default;

    bool initialize();
    bool isOpen() const;
    sf::RenderWindow& getWindow();
    void clear();
    void display();
    void drawTitle();
    void drawGrid(const GameState& state, const AnimationManager& animations);
    void drawMessage(const std::string& message, sf::Color color = sf::Color::Black);
    void drawGameOver(bool won, const std::string& answer);
    void drawInstructions(const std::string& text);

private:
    sf::RenderWindow window_;
    sf::Font font_;
    Grid grid_;
    bool fontLoaded_;

    float getCenteredX(const sf::Text& text) const;
};
