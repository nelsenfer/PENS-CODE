#include "GameManager.h"

#include <iostream>

GameManager::GameManager(PokerHandChecker* checker)
    : rootChecker(checker), money(0) {}

void GameManager::runSession() {
    std::cout << "=== RUN START ===\n";

    for (int round = 1; round <= 5; ++round) {
        std::cout << "\nRound " << round << "\n";

        Hand currentHand = handGenerator.generateHand();
        std::cout << "[CARDS] Available cards:\n";
        for (const Card& card : currentHand.availableCards)
            std::cout << "  - " << cardName(card) << "\n";

        EvaluationResult selected =
            selector.playHand(currentHand, *rootChecker);
        currentHand.playedCards = selected.playedCards;

        std::cout << "[CARDS] Played cards:\n";
        for (const Card& card : currentHand.playedCards)
            std::cout << "  - " << cardName(card) << "\n";

        EvaluationResult evaluation = rootChecker->check(currentHand);
        std::cout << "[HAND] Combination: "
                  << handRankName(evaluation.rank) << "\n";

        ScoringRule::ScoreResult score =
            scoringRule.scoreHand(evaluation);
        jokerCard.onHandPlayed(score);
        score = jokerCard.modifyScore(score);

        bool isWin = blindRule.checkBlind(score.total);
        int reward = rewardRule.earnMoney(isWin, score.total);
        money += reward;

        std::cout << "[SCORE] Chips: " << score.chips
                  << " | Mult: " << score.mult
                  << " (Joker +1)"
                  << " | Total: " << score.total
                  << " | Lolos Blind? " << (isWin ? "Ya" : "Tidak")
                  << "\n";
        std::cout << "[REWARD] Gain: " << reward
                  << " | Money: " << money << "\n";

        if (!isWin) {
            std::cout
                << "\n>> GAME OVER! Anda gagal melewati target Blind.\n";
            break;
        }
    }

    std::cout << "\n=== RUN END ===\n";
    std::cout << "Final money: " << money << "\n";
}
