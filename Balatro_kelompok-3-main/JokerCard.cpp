#include "JokerCard.h"

void JokerCard::onHandPlayed(
    const ScoringRule::ScoreResult&) {
    triggered = true;
}

ScoringRule::ScoreResult JokerCard::modifyScore(
    ScoringRule::ScoreResult score) {
    if (!triggered) return score;

    score.mult += bonusMult;
    score.total = score.chips * score.mult;
    triggered = false;
    return score;
}
