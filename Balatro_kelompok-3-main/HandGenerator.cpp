#include <algorithm>
#include <random>

class HandGenerator {
private:
    vector<Card> deck;
    mt19937 randomEngine;

public:
    HandGenerator() : randomEngine(random_device{}()) {
        resetDeck();
    }

    void resetDeck() {
        deck.clear();
        const Suit suits[] = {
            Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades
        };
        for (Suit suit : suits) {
            for (int value = 2; value <= 14; ++value)
                deck.push_back({suit, static_cast<Rank>(value)});
        }
    }

    Hand generateHand() {
        if (deck.size() < 8) resetDeck();
        shuffle(deck.begin(), deck.end(), randomEngine);

        Hand hand;
        hand.availableCards.assign(deck.begin(), deck.begin() + 8);
        deck.erase(deck.begin(), deck.begin() + 8);
        return hand;
    }
};
