#include "ui/Grid.hpp"
#include "Constants.hpp"

Grid::Grid()
    : font_(nullptr)
    , position_(0.0f, 0.0f)
{
}

bool Grid::initialize(const sf::Font& font) {
    font_ = &font;
    initializeTiles();
    return true;
}

void Grid::initializeTiles() {
    for (int row = 0; row < GameConfig::MAX_ATTEMPTS; ++row) {
        for (int col = 0; col < GameConfig::WORD_LENGTH; ++col) {
            auto& tile = tiles_[row][col];

            tile.shape.setSize({GameConfig::TILE_SIZE, GameConfig::TILE_SIZE});
            tile.shape.setFillColor(WordleColors::TILE_BG);
            tile.shape.setOutlineColor(WordleColors::EMPTY);
            tile.shape.setOutlineThickness(GameConfig::TILE_BORDER);

            tile.text.emplace(*font_, "", GameConfig::TILE_FONT_SIZE);
            tile.text->setFillColor(WordleColors::TEXT_DARK);
        }
    }
}

void Grid::update(const std::vector<GuessResult>& history,
                  const std::string& currentInput,
                  int currentRow,
                  const AnimationManager& animations) {
    for (int row = 0; row < GameConfig::MAX_ATTEMPTS; ++row) {
        for (int col = 0; col < GameConfig::WORD_LENGTH; ++col) {
            updateTile(row, col, '\0', LetterResult::Empty, 1.0f);
        }
    }

    for (int row = 0; row < static_cast<int>(history.size()); ++row) {
        const auto& guess = history[row];
        for (int col = 0; col < GameConfig::WORD_LENGTH; ++col) {
            const TileAnimation* anim = animations.getTileAnimation(row, col);
            if (anim && !anim->isComplete()) {
                float scaleY = anim->getScaleY();
                LetterResult result = anim->shouldShowResult() ?
                    anim->getResult() : LetterResult::Empty;
                updateTile(row, col, guess.word[col], result, scaleY);
            } else {
                updateTile(row, col, guess.word[col], guess.results[col], 1.0f);
            }
        }
    }

    if (currentRow < GameConfig::MAX_ATTEMPTS) {
        for (int col = 0; col < static_cast<int>(currentInput.length()); ++col) {
            updateTile(currentRow, col, currentInput[col], LetterResult::Empty, 1.0f);
        }
    }
}

void Grid::updateTile(int row, int col, char letter, LetterResult result, float scaleY) {
    auto& tile = tiles_[row][col];

    sf::Color bgColor = getColorForResult(result);
    tile.shape.setFillColor(bgColor);

    if (result == LetterResult::Empty) {
        if (letter != '\0') {
            tile.shape.setOutlineColor(sf::Color(135, 138, 140));
        } else {
            tile.shape.setOutlineColor(WordleColors::EMPTY);
        }
    } else {
        tile.shape.setOutlineThickness(0);
    }

    if (tile.text) {
        if (letter != '\0') {
            tile.text->setString(std::string(1, letter));
            tile.text->setFillColor(getTextColorForResult(result));
        } else {
            tile.text->setString("");
        }
    }

    tile.result = result;
    tile.scaleY = scaleY;
}

void Grid::setPosition(float x, float y) {
    position_ = {x, y};
}

void Grid::draw(sf::RenderWindow& window) const {
    for (int row = 0; row < GameConfig::MAX_ATTEMPTS; ++row) {
        for (int col = 0; col < GameConfig::WORD_LENGTH; ++col) {
            const auto& tile = tiles_[row][col];

            float x = position_.x + col * (GameConfig::TILE_SIZE + GameConfig::TILE_GAP);
            float y = position_.y + row * (GameConfig::TILE_SIZE + GameConfig::TILE_GAP);

            float scaleY = tile.scaleY;
            float tileHeight = GameConfig::TILE_SIZE * scaleY;
            float yOffset = (GameConfig::TILE_SIZE - tileHeight) / 2.0f;

            sf::RectangleShape shape = tile.shape;
            shape.setPosition({x, y + yOffset});
            shape.setSize({GameConfig::TILE_SIZE, tileHeight});

            if (tile.result == LetterResult::Empty) {
                shape.setOutlineThickness(GameConfig::TILE_BORDER);
            }

            window.draw(shape);

            if (tile.text && scaleY > 0.1f && tile.text->getString().getSize() > 0) {
                sf::Text text = *tile.text;

                sf::FloatRect textBounds = text.getLocalBounds();
                float textX = x + (GameConfig::TILE_SIZE - textBounds.size.x) / 2.0f - textBounds.position.x;
                float textY = y + yOffset + (tileHeight - textBounds.size.y) / 2.0f - textBounds.position.y;

                text.setScale({1.0f, scaleY});
                text.setPosition({textX, textY});

                window.draw(text);
            }
        }
    }
}

sf::Vector2f Grid::getSize() const {
    float width = GameConfig::WORD_LENGTH * GameConfig::TILE_SIZE +
                  (GameConfig::WORD_LENGTH - 1) * GameConfig::TILE_GAP;
    float height = GameConfig::MAX_ATTEMPTS * GameConfig::TILE_SIZE +
                   (GameConfig::MAX_ATTEMPTS - 1) * GameConfig::TILE_GAP;
    return {width, height};
}

sf::Color Grid::getColorForResult(LetterResult result) {
    switch (result) {
        case LetterResult::Correct:
            return WordleColors::CORRECT;
        case LetterResult::Present:
            return WordleColors::PRESENT;
        case LetterResult::Absent:
            return WordleColors::ABSENT;
        case LetterResult::Empty:
        default:
            return WordleColors::TILE_BG;
    }
}

sf::Color Grid::getTextColorForResult(LetterResult result) {
    if (result == LetterResult::Empty) {
        return WordleColors::TEXT_DARK;
    }
    return WordleColors::TEXT_LIGHT;
}
