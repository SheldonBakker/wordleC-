#include "GameState.hpp"
#include <algorithm>
#include <cctype>

GameState::GameState()
    : status_(GameStatus::InProgress)
{
}

void GameState::setTargetWord(const std::string& word) {
    targetWord_ = word;
    std::transform(targetWord_.begin(), targetWord_.end(), targetWord_.begin(),
                   [](unsigned char c) { return std::toupper(c); });
}

const std::string& GameState::getTargetWord() const {
    return targetWord_;
}

GuessResult GameState::submitGuess(const std::string& guess) {
    std::string normalizedGuess = guess;
    std::transform(normalizedGuess.begin(), normalizedGuess.end(), normalizedGuess.begin(),
                   [](unsigned char c) { return std::toupper(c); });

    GuessResult result = evaluateGuess(normalizedGuess);
    guessHistory_.push_back(result);

    bool allCorrect = true;
    for (int i = 0; i < GameConfig::WORD_LENGTH; ++i) {
        if (result.results[i] != LetterResult::Correct) {
            allCorrect = false;
            break;
        }
    }

    if (allCorrect) {
        status_ = GameStatus::Won;
    } else if (guessHistory_.size() >= GameConfig::MAX_ATTEMPTS) {
        status_ = GameStatus::Lost;
    }

    currentInput_.clear();
    return result;
}

GuessResult GameState::evaluateGuess(const std::string& guess) const {
    GuessResult result;
    result.word = guess;
    result.results.fill(LetterResult::Absent);

    std::array<int, 26> targetLetterCounts{};
    for (char c : targetWord_) {
        if (c >= 'A' && c <= 'Z') {
            targetLetterCounts[c - 'A']++;
        }
    }

    for (int i = 0; i < GameConfig::WORD_LENGTH; ++i) {
        if (guess[i] == targetWord_[i]) {
            result.results[i] = LetterResult::Correct;
            targetLetterCounts[guess[i] - 'A']--;
        }
    }

    for (int i = 0; i < GameConfig::WORD_LENGTH; ++i) {
        if (result.results[i] != LetterResult::Correct) {
            char c = guess[i];
            if (c >= 'A' && c <= 'Z') {
                int letterIndex = c - 'A';
                if (targetLetterCounts[letterIndex] > 0) {
                    result.results[i] = LetterResult::Present;
                    targetLetterCounts[letterIndex]--;
                }
            }
        }
    }

    return result;
}

void GameState::addLetter(char letter) {
    if (status_ != GameStatus::InProgress) {
        return;
    }
    if (currentInput_.length() < GameConfig::WORD_LENGTH) {
        currentInput_ += static_cast<char>(std::toupper(static_cast<unsigned char>(letter)));
    }
}

void GameState::removeLetter() {
    if (!currentInput_.empty()) {
        currentInput_.pop_back();
    }
}

GameStatus GameState::getStatus() const {
    return status_;
}

int GameState::getCurrentAttempt() const {
    return static_cast<int>(guessHistory_.size());
}

const std::vector<GuessResult>& GameState::getGuessHistory() const {
    return guessHistory_;
}

const std::string& GameState::getCurrentInput() const {
    return currentInput_;
}

void GameState::reset() {
    targetWord_.clear();
    guessHistory_.clear();
    currentInput_.clear();
    status_ = GameStatus::InProgress;
}
