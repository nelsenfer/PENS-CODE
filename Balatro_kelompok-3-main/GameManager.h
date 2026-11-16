#pragma once

#include "GameRules.h"
#include "HandGenerator.h"
#include "HandSelector.h"
#include "JokerCard.h"

class GameManager {
private:
    HandGenerator handGenerator;
    HandSelector selector;
    ScoringRule scoringRule;
    JokerCard jokerCard;
    RewardRule rewardRule;
    BlindRule blindRule;
    PokerHandChecker* rootChecker;
    int money;

public:
    explicit GameManager(PokerHandChecker* checker);
    void runSession();
};
