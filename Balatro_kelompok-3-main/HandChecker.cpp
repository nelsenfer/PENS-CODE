#include "HandChecker.h"

#include <algorithm>

bool PokerHandChecker::isFlush(const std::vector<Card>& cards) {
    for (size_t i = 1; i < cards.size(); ++i)
        if (cards[i].suit != cards[0].suit) return false;
    return true;
}

std::vector<int> PokerHandChecker::rankCounts(
    const std::vector<Card>& cards) {
    std::vector<int> counts(15, 0);
    for (const Card& card : cards)
        ++counts[static_cast<int>(card.rank)];
    return counts;
}

bool PokerHandChecker::isStraight(const std::vector<Card>& cards) {
    std::vector<int> values;
    for (const Card& card : cards)
        values.push_back(static_cast<int>(card.rank));

    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    if (values.size() != 5) return false;
    if (values == std::vector<int>{2, 3, 4, 5, 14}) return true;

    for (size_t i = 1; i < values.size(); ++i)
        if (values[i] != values[i - 1] + 1) return false;
    return true;
}

bool PokerHandChecker::hasCount(
    const std::vector<int>& counts,
    int count) {
    return std::find(counts.begin(), counts.end(), count) != counts.end();
}

bool PokerHandChecker::matches(
    const std::vector<Card>& cards,
    HandRank rank) {
    std::vector<int> counts = rankCounts(cards);
    bool flush = isFlush(cards);
    bool straight = isStraight(cards);
    bool fullHouse = hasCount(counts, 3) && hasCount(counts, 2);
    bool four = hasCount(counts, 4);
    bool three = hasCount(counts, 3);
    int pairs = static_cast<int>(
        std::count(counts.begin(), counts.end(), 2));
    bool royal = flush && counts[10] && counts[11] && counts[12] &&
                 counts[13] && counts[14];
    bool five = hasCount(counts, 5);

    switch (rank) {
    case HandRank::FlushFive: return flush && five;
    case HandRank::FlushHouse: return flush && fullHouse;
    case HandRank::FiveOfAKind: return five;
    case HandRank::RoyalFlush: return royal;
    case HandRank::StraightFlush: return flush && straight;
    case HandRank::FourOfAKind: return four;
    case HandRank::FullHouse: return fullHouse;
    case HandRank::Flush: return flush;
    case HandRank::Straight: return straight;
    case HandRank::ThreeOfAKind: return three;
    case HandRank::TwoPair: return pairs >= 2;
    case HandRank::Pair: return pairs >= 1;
    case HandRank::HighCard: return true;
    }
    return false;
}

EvaluationResult PokerHandChecker::continueOrReturn(
    const Hand& hand,
    HandRank rank) {
    if (matches(hand.playedCards, rank))
        return {rank, hand.playedCards};
    if (nextChecker) return nextChecker->check(hand);
    return {HandRank::HighCard, hand.playedCards};
}

void PokerHandChecker::setNext(PokerHandChecker* next) {
    nextChecker = next;
}

#define DEFINE_CHECKER_METHOD(className, rankValue) \
EvaluationResult className::check(const Hand& hand) { \
    return continueOrReturn(hand, rankValue); \
}

DEFINE_CHECKER_METHOD(FlushFiveChecker, HandRank::FlushFive)
DEFINE_CHECKER_METHOD(FlushHouseChecker, HandRank::FlushHouse)
DEFINE_CHECKER_METHOD(FiveOfAKindChecker, HandRank::FiveOfAKind)
DEFINE_CHECKER_METHOD(RoyalFlushChecker, HandRank::RoyalFlush)
DEFINE_CHECKER_METHOD(StraightFlushChecker, HandRank::StraightFlush)
DEFINE_CHECKER_METHOD(FourOfAKindChecker, HandRank::FourOfAKind)
DEFINE_CHECKER_METHOD(FullHouseChecker, HandRank::FullHouse)
DEFINE_CHECKER_METHOD(FlushChecker, HandRank::Flush)
DEFINE_CHECKER_METHOD(StraightChecker, HandRank::Straight)
DEFINE_CHECKER_METHOD(ThreeOfAKindChecker, HandRank::ThreeOfAKind)
DEFINE_CHECKER_METHOD(TwoPairChecker, HandRank::TwoPair)
DEFINE_CHECKER_METHOD(PairChecker, HandRank::Pair)

EvaluationResult HighCardChecker::check(const Hand& hand) {
    return {HandRank::HighCard, hand.playedCards};
}
