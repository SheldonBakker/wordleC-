#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include <random>

class WordValidator {
public:
    WordValidator();
    ~WordValidator() = default;

    void initialize();
    bool loadValidGuessesFromFile(const std::string& filepath);
    bool isValidGuess(const std::string& word) const;
    std::string getRandomSolutionWord();
    size_t getSolutionWordCount() const;
    size_t getValidGuessCount() const;

private:
    std::unordered_set<std::string> solutionWords_;
    std::unordered_set<std::string> validGuesses_;
    std::vector<std::string> solutionWordList_;
    std::mt19937 rng_;

    void loadEmbeddedWords();
    static std::string normalize(const std::string& word);
};
