#include <iostream>

using namespace std;

enum class HandRank {
    HighCard, Pair, TwoPair, ThreeOfAKind, Straight, Flush, FullHouse,
    FourOfAKind, StraightFlush, RoyalFlush, FiveOfAKind, FlushHouse, FlushFive
};

class Hand {
public:
    HandRank simulatedRank;
};

class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker = nullptr;

public:
    virtual ~PokerHandChecker() = default;

    void setNext(PokerHandChecker* next) {
        nextChecker = next;
    }

    virtual HandRank check(const Hand& hand) = 0;
};

class FlushFiveChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Flush Five...\n";
        if (hand.simulatedRank == HandRank::FlushFive) {
            cout << ">> Hand ditemukan: Flush Five!\n";
            return HandRank::FlushFive;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class FlushHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Flush House...\n";
        if (hand.simulatedRank == HandRank::FlushHouse) {
            cout << ">> Hand ditemukan: Flush House!\n";
            return HandRank::FlushHouse;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class FiveOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Five of a Kind...\n";
        if (hand.simulatedRank == HandRank::FiveOfAKind) {
            cout << ">> Hand ditemukan: Five of a Kind!\n";
            return HandRank::FiveOfAKind;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class RoyalFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Royal Flush...\n";
        if (hand.simulatedRank == HandRank::RoyalFlush) {
            cout << ">> Hand ditemukan: Royal Flush!\n";
            return HandRank::RoyalFlush;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class StraightFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Straight Flush...\n";
        if (hand.simulatedRank == HandRank::StraightFlush) {
            cout << ">> Hand ditemukan: Straight Flush!\n";
            return HandRank::StraightFlush;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class FourOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Four of a Kind...\n";
        if (hand.simulatedRank == HandRank::FourOfAKind) {
            cout << ">> Hand ditemukan: Four of a Kind!\n";
            return HandRank::FourOfAKind;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class FullHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Full House...\n";
        if (hand.simulatedRank == HandRank::FullHouse) {
            cout << ">> Hand ditemukan: Full House!\n";
            return HandRank::FullHouse;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class FlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Flush...\n";
        if (hand.simulatedRank == HandRank::Flush) {
            cout << ">> Hand ditemukan: Flush!\n";
            return HandRank::Flush;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class StraightChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Straight...\n";
        if (hand.simulatedRank == HandRank::Straight) {
            cout << ">> Hand ditemukan: Straight!\n";
            return HandRank::Straight;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class ThreeOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Three of a Kind...\n";
        if (hand.simulatedRank == HandRank::ThreeOfAKind) {
            cout << ">> Hand ditemukan: Three of a Kind!\n";
            return HandRank::ThreeOfAKind;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class TwoPairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Two Pair...\n";
        if (hand.simulatedRank == HandRank::TwoPair) {
            cout << ">> Hand ditemukan: Two Pair!\n";
            return HandRank::TwoPair;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class PairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        cout << "[CHECKER] Memeriksa Pair...\n";
        if (hand.simulatedRank == HandRank::Pair) {
            cout << ">> Hand ditemukan: Pair!\n";
            return HandRank::Pair;
        }
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HighCard;
    }
};

class HighCardChecker : public PokerHandChecker {
public:
    HandRank check(const Hand&) override {
        cout << "[CHECKER] Memeriksa High Card...\n";
        cout << ">> Hand ditemukan: High Card!\n";
        return HandRank::HighCard;
    }
};
