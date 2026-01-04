#pragma once

#include <SFML/Graphics.hpp>
#include "../GameState.hpp"
#include "Animation.hpp"
#include <array>
#include <optional>

class Grid {
public:
    Grid();
    ~Grid() = default;

    bool initialize(const sf::Font& font);
    void update(const std::vector<GuessResult>& history,
                const std::string& currentInput,
                int currentRow,
                const AnimationManager& animations);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getSize() const;

private:
    const sf::Font* font_;
    sf::Vector2f position_;

    struct Tile {
        sf::RectangleShape shape;
        std::optional<sf::Text> text;
        LetterResult result = LetterResult::Empty;
        float scaleY = 1.0f;
    };

    std::array<std::array<Tile, GameConfig::WORD_LENGTH>, GameConfig::MAX_ATTEMPTS> tiles_;

    void initializeTiles();
    void updateTile(int row, int col, char letter, LetterResult result, float scaleY = 1.0f);
    static sf::Color getColorForResult(LetterResult result);
    static sf::Color getTextColorForResult(LetterResult result);
};
