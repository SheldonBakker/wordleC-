#pragma once

#include <SFML/Graphics/Color.hpp>

namespace WordleColors {
    const sf::Color CORRECT   = sf::Color(106, 170, 100);
    const sf::Color PRESENT   = sf::Color(201, 180, 88);
    const sf::Color ABSENT    = sf::Color(120, 124, 126);
    const sf::Color EMPTY     = sf::Color(211, 214, 218);
    const sf::Color TILE_BG   = sf::Color(255, 255, 255);
    const sf::Color TEXT_LIGHT = sf::Color(255, 255, 255);
    const sf::Color TEXT_DARK  = sf::Color(0, 0, 0);
    const sf::Color BACKGROUND = sf::Color(255, 255, 255);
    const sf::Color TITLE_TEXT = sf::Color(0, 0, 0);
    const sf::Color MESSAGE    = sf::Color(50, 50, 50);
}

namespace GameConfig {
    constexpr unsigned int WINDOW_WIDTH = 400;
    constexpr unsigned int WINDOW_HEIGHT = 650;
    constexpr const char* WINDOW_TITLE = "Wordle";
    constexpr int MAX_ATTEMPTS = 6;
    constexpr int WORD_LENGTH = 5;
    constexpr float TILE_SIZE = 62.0f;
    constexpr float TILE_GAP = 5.0f;
    constexpr float GRID_TOP = 80.0f;
    constexpr float TILE_BORDER = 2.0f;
    constexpr float FLIP_DURATION = 0.3f;
    constexpr float FLIP_DELAY = 0.1f;
    constexpr unsigned int TITLE_FONT_SIZE = 36;
    constexpr unsigned int TILE_FONT_SIZE = 32;
    constexpr unsigned int MESSAGE_FONT_SIZE = 18;
    constexpr const char* FONT_PATH = "resources/fonts/ClearSans-Bold.ttf";
    constexpr const char* VALID_GUESSES_PATH = "resources/words/valid_guesses.txt";
}
