#pragma once

#include "Hand.h"

class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker = nullptr;

    static bool isFlush(const std::vector<Card>& cards);
    static std::vector<int> rankCounts(const std::vector<Card>& cards);
    static bool isStraight(const std::vector<Card>& cards);
    static bool hasCount(const std::vector<int>& counts, int count);
    static bool matches(const std::vector<Card>& cards, HandRank rank);
    EvaluationResult continueOrReturn(
        const Hand& hand,
        HandRank rank);

public:
    virtual ~PokerHandChecker() = default;
    void setNext(PokerHandChecker* next);
    virtual EvaluationResult check(const Hand& hand) = 0;
};

class FlushFiveChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class FlushHouseChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class FiveOfAKindChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class RoyalFlushChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class StraightFlushChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class FourOfAKindChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class FullHouseChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class FlushChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class StraightChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class ThreeOfAKindChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class TwoPairChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class PairChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};

class HighCardChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override;
};
