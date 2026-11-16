#include "HandGenerator.h"

#include <algorithm>

HandGenerator::HandGenerator() : randomEngine(std::random_device{}()) {
    resetDeck();
}

void HandGenerator::resetDeck() {
    deck.clear();
    const Suit suits[] = {
        Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades
    };

    for (Suit suit : suits) {
        for (int value = 2; value <= 14; ++value)
            deck.push_back({suit, static_cast<Rank>(value)});
    }
}

Hand HandGenerator::generateHand() {
    if (deck.size() < 8) resetDeck();
    std::shuffle(deck.begin(), deck.end(), randomEngine);

    Hand hand;
    hand.availableCards.assign(deck.begin(), deck.begin() + 8);
    deck.erase(deck.begin(), deck.begin() + 8);
    return hand;
}
