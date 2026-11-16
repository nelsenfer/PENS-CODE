#include "GameRules.h"

ScoringRule::ScoreResult ScoringRule::scoreHand(
    const EvaluationResult& evaluation) {
    int baseChips = 0;
    int baseMult = 1;

    switch (evaluation.rank) {
    case HandRank::HighCard: baseChips = 5; baseMult = 1; break;
    case HandRank::Pair: baseChips = 10; baseMult = 2; break;
    case HandRank::TwoPair: baseChips = 20; baseMult = 2; break;
    case HandRank::ThreeOfAKind: baseChips = 30; baseMult = 3; break;
    case HandRank::Straight: baseChips = 30; baseMult = 4; break;
    case HandRank::Flush: baseChips = 35; baseMult = 4; break;
    case HandRank::FullHouse: baseChips = 40; baseMult = 4; break;
    case HandRank::FourOfAKind: baseChips = 60; baseMult = 7; break;
    case HandRank::StraightFlush: baseChips = 100; baseMult = 8; break;
    case HandRank::RoyalFlush: baseChips = 100; baseMult = 8; break;
    case HandRank::FiveOfAKind: baseChips = 120; baseMult = 12; break;
    case HandRank::FlushHouse: baseChips = 140; baseMult = 14; break;
    case HandRank::FlushFive: baseChips = 160; baseMult = 16; break;
    }

    int cardChips = 0;
    for (const Card& card : evaluation.playedCards) {
        int value = static_cast<int>(card.rank);
        cardChips += value > 10 ? 10 : value;
    }

    int chips = baseChips + cardChips;
    return {chips, baseMult, chips * baseMult};
}

int RewardRule::earnMoney(bool win, int score) {
    if (win) return score / 10 + 2;
    return 0;
}

bool BlindRule::checkBlind(int score) {
    return score >= 30;
}
