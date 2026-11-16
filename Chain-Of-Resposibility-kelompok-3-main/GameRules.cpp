class ScoringRule {
public:
    int convertRankToScore(HandRank rank) {
        return (static_cast<int>(rank) + 1) * 10;
    }
};

class RewardRule {
public:
    int earnMoney(bool win, int score) {
        if (win) return score / 10 + 2;
        return 0;
    }
};

class BlindRule {
public:
    bool checkBlind(int score) {
        return score >= 30;
    }
};
