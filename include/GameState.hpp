#pragma once

#include "Constants.hpp"
#include <string>
#include <vector>
#include <array>

enum class LetterResult {
    Correct,
    Present,
    Absent,
    Empty
};

struct GuessResult {
    std::string word;
    std::array<LetterResult, GameConfig::WORD_LENGTH> results;

    GuessResult() : results{} {
        results.fill(LetterResult::Empty);
    }
};

enum class GameStatus {
    InProgress,
    Won,
    Lost
};

class GameState {
public:
    GameState();
    ~GameState() = default;

    void setTargetWord(const std::string& word);
    const std::string& getTargetWord() const;
    GuessResult submitGuess(const std::string& guess);
    void addLetter(char letter);
    void removeLetter();
    GameStatus getStatus() const;
    int getCurrentAttempt() const;
    const std::vector<GuessResult>& getGuessHistory() const;
    const std::string& getCurrentInput() const;
    void reset();

private:
    std::string targetWord_;
    std::vector<GuessResult> guessHistory_;
    std::string currentInput_;
    GameStatus status_;

    GuessResult evaluateGuess(const std::string& guess) const;
};
