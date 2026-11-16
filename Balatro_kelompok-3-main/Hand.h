#pragma once

#include <string>
#include <vector>
#include "Card.h"

enum class HandRank {
    HighCard, Pair, TwoPair, ThreeOfAKind, Straight, Flush, FullHouse,
    FourOfAKind, StraightFlush, RoyalFlush, FiveOfAKind, FlushHouse, FlushFive
};

inline std::string handRankName(HandRank rank) {
    switch (rank) {
    case HandRank::HighCard: return "High Card";
    case HandRank::Pair: return "Pair";
    case HandRank::TwoPair: return "Two Pair";
    case HandRank::ThreeOfAKind: return "Three of a Kind";
    case HandRank::Straight: return "Straight";
    case HandRank::Flush: return "Flush";
    case HandRank::FullHouse: return "Full House";
    case HandRank::FourOfAKind: return "Four of a Kind";
    case HandRank::StraightFlush: return "Straight Flush";
    case HandRank::RoyalFlush: return "Royal Flush";
    case HandRank::FiveOfAKind: return "Five of a Kind";
    case HandRank::FlushHouse: return "Flush House";
    case HandRank::FlushFive: return "Flush Five";
    }
    return "";
}

class Hand {
public:
    std::vector<Card> availableCards;
    std::vector<Card> playedCards;
};

struct EvaluationResult {
    HandRank rank;
    std::vector<Card> playedCards;
};
