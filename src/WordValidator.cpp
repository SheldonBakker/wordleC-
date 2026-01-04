#include "WordValidator.hpp"
#include "EmbeddedWords.hpp"
#include "Constants.hpp"
#include <fstream>
#include <algorithm>
#include <cctype>

WordValidator::WordValidator()
    : rng_(std::random_device{}())
{
}

void WordValidator::initialize() {
    loadEmbeddedWords();
    loadValidGuessesFromFile(GameConfig::VALID_GUESSES_PATH);
}

void WordValidator::loadEmbeddedWords() {
    for (const auto& word : EmbeddedWords::SOLUTION_WORDS) {
        std::string normalized(word);
        solutionWords_.insert(normalized);
        validGuesses_.insert(normalized);
        solutionWordList_.push_back(normalized);
    }

    for (const auto& word : EmbeddedWords::EXTRA_VALID_WORDS) {
        std::string normalized(word);
        validGuesses_.insert(normalized);
    }
}

bool WordValidator::loadValidGuessesFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return false;
    }

    std::string word;
    while (std::getline(file, word)) {
        word.erase(0, word.find_first_not_of(" \t\r\n"));
        word.erase(word.find_last_not_of(" \t\r\n") + 1);

        if (word.length() == GameConfig::WORD_LENGTH) {
            validGuesses_.insert(normalize(word));
        }
    }

    return true;
}

bool WordValidator::isValidGuess(const std::string& word) const {
    if (word.length() != GameConfig::WORD_LENGTH) {
        return false;
    }
    return validGuesses_.count(normalize(word)) > 0;
}

std::string WordValidator::getRandomSolutionWord() {
    if (solutionWordList_.empty()) {
        return "ERROR";
    }
    std::uniform_int_distribution<size_t> dist(0, solutionWordList_.size() - 1);
    return solutionWordList_[dist(rng_)];
}

size_t WordValidator::getSolutionWordCount() const {
    return solutionWords_.size();
}

size_t WordValidator::getValidGuessCount() const {
    return validGuesses_.size();
}

std::string WordValidator::normalize(const std::string& word) {
    std::string result = word;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}
