#pragma once

#include "HandChecker.h"

class HandSelector {
private:
    static std::vector<int> tieBreaker(const std::vector<Card>& cards);
    static bool isBetter(
        const EvaluationResult& candidate,
        const EvaluationResult& current);

public:
    EvaluationResult playHand(
        const Hand& source,
        PokerHandChecker& checker);
};
