#include <iostream>

using namespace std;

class GameManager {
private:
    HandGenerator handGenerator;
    ScoringRule scoringRule;
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
            HandRank rankResult = rootChecker->check(currentHand);
            int baseScore = scoringRule.convertRankToScore(rankResult);
            bool isWin = blindRule.checkBlind(baseScore);
            int reward = rewardRule.earnMoney(isWin, baseScore);

            money += reward;

            cout << "[SCORE] Base score: " << baseScore
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
