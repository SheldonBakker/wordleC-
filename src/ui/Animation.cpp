#include "ui/Animation.hpp"
#include "Constants.hpp"
#include <algorithm>

TileAnimation::TileAnimation(int row, int col, LetterResult result, float delay)
    : row_(row)
    , col_(col)
    , result_(result)
    , delay_(delay)
    , progress_(0.0f)
    , duration_(GameConfig::FLIP_DURATION)
    , started_(false)
    , complete_(false)
    , pastMidpoint_(false)
{
}

bool TileAnimation::update(float deltaTime) {
    if (complete_) {
        return false;
    }

    if (delay_ > 0.0f) {
        delay_ -= deltaTime;
        return true;
    }

    started_ = true;
    progress_ += deltaTime / duration_;

    if (progress_ >= 0.5f && !pastMidpoint_) {
        pastMidpoint_ = true;
    }

    if (progress_ >= 1.0f) {
        progress_ = 1.0f;
        complete_ = true;
        return false;
    }

    return true;
}

float TileAnimation::getScaleY() const {
    if (!started_) {
        return 1.0f;
    }

    if (progress_ < 0.5f) {
        return 1.0f - (progress_ * 2.0f);
    } else {
        return (progress_ - 0.5f) * 2.0f;
    }
}

bool TileAnimation::shouldShowResult() const {
    return pastMidpoint_;
}

LetterResult TileAnimation::getResult() const {
    return result_;
}

void AnimationManager::startRowAnimation(int row, const GuessResult& result) {
    for (int col = 0; col < GameConfig::WORD_LENGTH; ++col) {
        float delay = col * GameConfig::FLIP_DELAY;
        animations_.emplace_back(row, col, result.results[col], delay);
    }
}

void AnimationManager::update(float deltaTime) {
    animations_.erase(
        std::remove_if(animations_.begin(), animations_.end(),
            [deltaTime](TileAnimation& anim) {
                anim.update(deltaTime);
                return anim.isComplete();
            }),
        animations_.end()
    );
}

const TileAnimation* AnimationManager::getTileAnimation(int row, int col) const {
    for (const auto& anim : animations_) {
        if (anim.getRow() == row && anim.getCol() == col) {
            return &anim;
        }
    }
    return nullptr;
}

bool AnimationManager::isAnimating() const {
    return !animations_.empty();
}

void AnimationManager::clear() {
    animations_.clear();
}
