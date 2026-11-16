#include <cstdlib>

class Hand;
enum class HandRank;

class HandGenerator {
public:
    Hand generateHand();
};

Hand HandGenerator::generateHand() {
    Hand newHand;
    int randomRank = rand() % 13;
    newHand.simulatedRank = static_cast<HandRank>(randomRank);
    return newHand;
}
