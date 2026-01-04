#pragma once

#include "../GameState.hpp"
#include <vector>

class TileAnimation {
public:
    TileAnimation(int row, int col, LetterResult result, float delay = 0.0f);

    bool update(float deltaTime);
    float getScaleY() const;
    bool shouldShowResult() const;
    LetterResult getResult() const;
    int getRow() const { return row_; }
    int getCol() const { return col_; }
    bool isComplete() const { return complete_; }
    bool hasStarted() const { return started_; }

private:
    int row_;
    int col_;
    LetterResult result_;
    float delay_;
    float progress_;
    float duration_;
    bool started_;
    bool complete_;
    bool pastMidpoint_;
};

class AnimationManager {
public:
    AnimationManager() = default;

    void startRowAnimation(int row, const GuessResult& result);
    void update(float deltaTime);
    const TileAnimation* getTileAnimation(int row, int col) const;
    bool isAnimating() const;
    void clear();

private:
    std::vector<TileAnimation> animations_;
};
