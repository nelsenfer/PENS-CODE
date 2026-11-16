#include <iostream>

using namespace std;

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
    explicit GameManager(PokerHandChecker* checker)
        : rootChecker(checker), money(0) {}

    void runSession() {
        cout << "=== RUN START ===\n";

        for (int round = 1; round <= 5; ++round) {
            cout << "\nRound " << round << "\n";

            Hand currentHand = handGenerator.generateHand();
            cout << "[CARDS] Available cards:\n";
            for (const Card& card : currentHand.availableCards)
                cout << "  - " << cardName(card) << "\n";

            EvaluationResult selected =
                selector.playHand(currentHand, *rootChecker);
            currentHand.playedCards = selected.playedCards;
            cout << "[CARDS] Played cards:\n";
            for (const Card& card : currentHand.playedCards)
                cout << "  - " << cardName(card) << "\n";

            EvaluationResult evaluation = rootChecker->check(currentHand);
            cout << "[HAND] Combination: " << handRankName(evaluation.rank)
                 << "\n";
            ScoringRule::ScoreResult score =
                scoringRule.scoreHand(evaluation);
            jokerCard.onHandPlayed(score);
            score = jokerCard.modifyScore(score);
            bool isWin = blindRule.checkBlind(score.total);
            int reward = rewardRule.earnMoney(isWin, score.total);

            money += reward;

            cout << "[SCORE] Chips: " << score.chips
                 << " | Mult: " << score.mult << " (Joker +1)"
                 << " | Total: " << score.total
                 << " | Lolos Blind? " << (isWin ? "Ya" : "Tidak") << "\n";
            cout << "[REWARD] Gain: " << reward
                 << " | Money: " << money << "\n";

            if (!isWin) {
                cout << "\n>> GAME OVER! Anda gagal melewati target Blind.\n";
                break;
            }
        }

        cout << "\n=== RUN END ===\n";
        cout << "Final money: " << money << "\n";
    }
};
