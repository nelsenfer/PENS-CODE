#pragma once

#include <random>
#include <vector>

#include "Hand.h"

class HandGenerator {
private:
    std::vector<Card> deck;
    std::mt19937 randomEngine;

public:
    HandGenerator();
    void resetDeck();
    Hand generateHand();
};
