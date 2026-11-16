#pragma once

#include "GameRules.h"

class JokerCard {
private:
    bool triggered = false;
    int bonusMult = 1;

public:
    void onHandPlayed(const ScoringRule::ScoreResult& score);
    ScoringRule::ScoreResult modifyScore(
        ScoringRule::ScoreResult score);
};
