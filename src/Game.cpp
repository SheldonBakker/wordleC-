#include "Game.hpp"
#include "Constants.hpp"

Game::Game()
    : isRunning_(false)
    , showInvalidMessage_(false)
    , invalidMessageTimer_(0.0f)
    , messageColor_(sf::Color::Black)
{
}

bool Game::initialize() {
    wordValidator_.initialize();

    if (!renderer_.initialize()) {
        return false;
    }

    startNewGame();
    isRunning_ = true;
    return true;
}

void Game::run() {
    while (isRunning_ && renderer_.isOpen()) {
        float deltaTime = clock_.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::RenderWindow& window = renderer_.getWindow();

    while (const std::optional event = window.pollEvent()) {
        InputResult input = inputHandler_.processEvent(*event);

        switch (input.action) {
            case InputAction::Quit:
                isRunning_ = false;
                window.close();
                break;

            case InputAction::AddLetter:
                if (gameState_.getStatus() == GameStatus::InProgress &&
                    !animations_.isAnimating()) {
                    gameState_.addLetter(input.letter);
                    showInvalidMessage_ = false;
                }
                break;

            case InputAction::RemoveLetter:
                if (gameState_.getStatus() == GameStatus::InProgress &&
                    !animations_.isAnimating()) {
                    gameState_.removeLetter();
                    showInvalidMessage_ = false;
                }
                break;

            case InputAction::SubmitGuess:
                if (!animations_.isAnimating()) {
                    if (gameState_.getStatus() == GameStatus::InProgress) {
                        handleGuessSubmission();
                    } else {
                        startNewGame();
                    }
                }
                break;

            case InputAction::NewGame:
                if (!animations_.isAnimating()) {
                    startNewGame();
                }
                break;

            case InputAction::None:
            default:
                break;
        }
    }
}

void Game::handleGuessSubmission() {
    const std::string& input = gameState_.getCurrentInput();

    if (input.length() != GameConfig::WORD_LENGTH) {
        currentMessage_ = "Not enough letters";
        messageColor_ = sf::Color(200, 50, 50);
        showInvalidMessage_ = true;
        invalidMessageTimer_ = INVALID_MESSAGE_DURATION;
        return;
    }

    if (!wordValidator_.isValidGuess(input)) {
        currentMessage_ = "Not in word list";
        messageColor_ = sf::Color(200, 50, 50);
        showInvalidMessage_ = true;
        invalidMessageTimer_ = INVALID_MESSAGE_DURATION;
        return;
    }

    int currentRow = gameState_.getCurrentAttempt();
    GuessResult result = gameState_.submitGuess(input);
    animations_.startRowAnimation(currentRow, result);
}

void Game::update(float deltaTime) {
    animations_.update(deltaTime);

    if (showInvalidMessage_) {
        invalidMessageTimer_ -= deltaTime;
        if (invalidMessageTimer_ <= 0.0f) {
            showInvalidMessage_ = false;
        }
    }
}

void Game::render() {
    renderer_.clear();
    renderer_.drawTitle();
    renderer_.drawGrid(gameState_, animations_);

    if (showInvalidMessage_) {
        renderer_.drawMessage(currentMessage_, messageColor_);
    } else if (gameState_.getStatus() != GameStatus::InProgress && !animations_.isAnimating()) {
        renderer_.drawGameOver(
            gameState_.getStatus() == GameStatus::Won,
            gameState_.getTargetWord()
        );
    }

    std::string instructions;
    if (gameState_.getStatus() == GameStatus::InProgress) {
        instructions = "Type a 5-letter word and press Enter";
    } else {
        instructions = "Press Enter for a new game, Esc to quit";
    }
    renderer_.drawInstructions(instructions);

    renderer_.display();
}

void Game::startNewGame() {
    gameState_.reset();
    animations_.clear();
    showInvalidMessage_ = false;

    std::string targetWord = wordValidator_.getRandomSolutionWord();
    gameState_.setTargetWord(targetWord);
}
