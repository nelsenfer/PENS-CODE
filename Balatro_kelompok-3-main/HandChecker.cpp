#include <algorithm>
#include <string>
#include <vector>

using namespace std;

enum class Suit { Hearts, Diamonds, Clubs, Spades };

enum class Rank {
    Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King, Ace
};

struct Card {
    Suit suit;
    Rank rank;
};

string suitName(Suit suit) {
    switch (suit) {
    case Suit::Hearts: return "Hearts";
    case Suit::Diamonds: return "Diamonds";
    case Suit::Clubs: return "Clubs";
    case Suit::Spades: return "Spades";
    }
    return "";
}

string rankName(Rank rank) {
    switch (rank) {
    case Rank::Two: return "2";
    case Rank::Three: return "3";
    case Rank::Four: return "4";
    case Rank::Five: return "5";
    case Rank::Six: return "6";
    case Rank::Seven: return "7";
    case Rank::Eight: return "8";
    case Rank::Nine: return "9";
    case Rank::Ten: return "10";
    case Rank::Jack: return "J";
    case Rank::Queen: return "Q";
    case Rank::King: return "K";
    case Rank::Ace: return "A";
    }
    return "";
}

string cardName(const Card& card) {
    return rankName(card.rank) + " of " + suitName(card.suit);
}

enum class HandRank {
    HighCard, Pair, TwoPair, ThreeOfAKind, Straight, Flush, FullHouse,
    FourOfAKind, StraightFlush, RoyalFlush, FiveOfAKind, FlushHouse, FlushFive
};

string handRankName(HandRank rank) {
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
    vector<Card> availableCards;
    vector<Card> playedCards;
};

struct EvaluationResult {
    HandRank rank;
    vector<Card> playedCards;
};

class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker = nullptr;

    static bool isFlush(const vector<Card>& cards) {
        for (size_t i = 1; i < cards.size(); ++i)
            if (cards[i].suit != cards[0].suit) return false;
        return true;
    }

    static vector<int> rankCounts(const vector<Card>& cards) {
        vector<int> counts(15, 0);
        for (const Card& card : cards) ++counts[static_cast<int>(card.rank)];
        return counts;
    }

    static bool isStraight(const vector<Card>& cards) {
        vector<int> values;
        for (const Card& card : cards) values.push_back(static_cast<int>(card.rank));
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        if (values.size() != 5) return false;
        if (values == vector<int>{2, 3, 4, 5, 14}) return true;
        for (size_t i = 1; i < values.size(); ++i)
            if (values[i] != values[i - 1] + 1) return false;
        return true;
    }

    static bool hasCount(const vector<int>& counts, int count) {
        return find(counts.begin(), counts.end(), count) != counts.end();
    }

    static bool matches(const vector<Card>& cards, HandRank rank) {
        vector<int> counts = rankCounts(cards);
        bool flush = isFlush(cards);
        bool straight = isStraight(cards);
        bool fullHouse = hasCount(counts, 3) && hasCount(counts, 2);
        bool four = hasCount(counts, 4);
        bool three = hasCount(counts, 3);
        int pairs = static_cast<int>(count(counts.begin(), counts.end(), 2));
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

    EvaluationResult continueOrReturn(const Hand& hand, HandRank rank) {
        if (matches(hand.playedCards, rank)) {
            return {rank, hand.playedCards};
        }
        if (nextChecker) return nextChecker->check(hand);
        return {HandRank::HighCard, hand.playedCards};
    }

public:
    virtual ~PokerHandChecker() = default;

    void setNext(PokerHandChecker* next) {
        nextChecker = next;
    }

    virtual EvaluationResult check(const Hand& hand) = 0;
};

#define DEFINE_CHECKER(className, rankValue)                         \
class className : public PokerHandChecker {                          \
public:                                                               \
    EvaluationResult check(const Hand& hand) override {               \
        return continueOrReturn(hand, rankValue);                    \
    }                                                                  \
};

DEFINE_CHECKER(FlushFiveChecker, HandRank::FlushFive)
DEFINE_CHECKER(FlushHouseChecker, HandRank::FlushHouse)
DEFINE_CHECKER(FiveOfAKindChecker, HandRank::FiveOfAKind)
DEFINE_CHECKER(RoyalFlushChecker, HandRank::RoyalFlush)
DEFINE_CHECKER(StraightFlushChecker, HandRank::StraightFlush)
DEFINE_CHECKER(FourOfAKindChecker, HandRank::FourOfAKind)
DEFINE_CHECKER(FullHouseChecker, HandRank::FullHouse)
DEFINE_CHECKER(FlushChecker, HandRank::Flush)
DEFINE_CHECKER(StraightChecker, HandRank::Straight)
DEFINE_CHECKER(ThreeOfAKindChecker, HandRank::ThreeOfAKind)
DEFINE_CHECKER(TwoPairChecker, HandRank::TwoPair)
DEFINE_CHECKER(PairChecker, HandRank::Pair)

class HighCardChecker : public PokerHandChecker {
public:
    EvaluationResult check(const Hand& hand) override {
        return {HandRank::HighCard, hand.playedCards};
    }
};
