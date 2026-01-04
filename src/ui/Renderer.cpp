#include "ui/Renderer.hpp"
#include "Constants.hpp"

Renderer::Renderer()
    : fontLoaded_(false)
{
}

bool Renderer::initialize() {
    window_.create(sf::VideoMode({GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT}),
                   GameConfig::WINDOW_TITLE,
                   sf::Style::Titlebar | sf::Style::Close);
    window_.setFramerateLimit(60);

    sf::Image icon;
    if (icon.loadFromFile("resources/icon.png") || icon.loadFromFile("resources/icon.ico")) {
        window_.setIcon(icon);
    }

    if (!font_.openFromFile(GameConfig::FONT_PATH)) {
        if (!font_.openFromFile("ClearSans-Bold.ttf")) {
            if (!font_.openFromFile("../resources/fonts/ClearSans-Bold.ttf")) {
                if (!font_.openFromFile("C:/Windows/Fonts/arial.ttf")) {
                    return false;
                }
            }
        }
    }

    fontLoaded_ = true;

    if (!grid_.initialize(font_)) {
        return false;
    }

    sf::Vector2f gridSize = grid_.getSize();
    float gridX = (GameConfig::WINDOW_WIDTH - gridSize.x) / 2.0f;
    grid_.setPosition(gridX, GameConfig::GRID_TOP);

    return true;
}

bool Renderer::isOpen() const {
    return window_.isOpen();
}

sf::RenderWindow& Renderer::getWindow() {
    return window_;
}

void Renderer::clear() {
    window_.clear(WordleColors::BACKGROUND);
}

void Renderer::display() {
    window_.display();
}

void Renderer::drawTitle() {
    sf::Text title(font_, GameConfig::WINDOW_TITLE, GameConfig::TITLE_FONT_SIZE);
    title.setFillColor(WordleColors::TITLE_TEXT);
    title.setStyle(sf::Text::Bold);

    float x = getCenteredX(title);
    title.setPosition({x, 15.0f});

    window_.draw(title);

    sf::RectangleShape line({static_cast<float>(GameConfig::WINDOW_WIDTH) - 40.0f, 1.0f});
    line.setFillColor(sf::Color(200, 200, 200));
    line.setPosition({20.0f, 60.0f});
    window_.draw(line);
}

void Renderer::drawGrid(const GameState& state, const AnimationManager& animations) {
    grid_.update(state.getGuessHistory(),
                 state.getCurrentInput(),
                 state.getCurrentAttempt(),
                 animations);
    grid_.draw(window_);
}

void Renderer::drawMessage(const std::string& message, sf::Color color) {
    sf::Text text(font_, message, GameConfig::MESSAGE_FONT_SIZE);
    text.setFillColor(color);

    float x = getCenteredX(text);
    float y = GameConfig::GRID_TOP + grid_.getSize().y + 20.0f;
    text.setPosition({x, y});

    window_.draw(text);
}

void Renderer::drawGameOver(bool won, const std::string& answer) {
    std::string message;
    sf::Color color;

    if (won) {
        message = "Congratulations! You won!";
        color = WordleColors::CORRECT;
    } else {
        message = "Game Over! The word was: " + answer;
        color = sf::Color(200, 50, 50);
    }

    drawMessage(message, color);
}

void Renderer::drawInstructions(const std::string& text) {
    sf::Text instructions(font_, text, 14);
    instructions.setFillColor(sf::Color(120, 120, 120));

    float x = getCenteredX(instructions);
    float y = GameConfig::WINDOW_HEIGHT - 30.0f;
    instructions.setPosition({x, y});

    window_.draw(instructions);
}

float Renderer::getCenteredX(const sf::Text& text) const {
    sf::FloatRect bounds = text.getLocalBounds();
    return (GameConfig::WINDOW_WIDTH - bounds.size.x) / 2.0f - bounds.position.x;
}
