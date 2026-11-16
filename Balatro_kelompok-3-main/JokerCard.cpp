class JokerCard {
private:
    bool triggered = false;
    int bonusMult = 1;

public:
    void onHandPlayed(const ScoringRule::ScoreResult&) {
        triggered = true;
    }

    ScoringRule::ScoreResult modifyScore(
        ScoringRule::ScoreResult score) {
        if (!triggered) return score;

        score.mult += bonusMult;
        score.total = score.chips * score.mult;
        triggered = false;
        return score;
    }
};
