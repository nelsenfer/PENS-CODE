#include "HandSelector.h"

#include <algorithm>

std::vector<int> HandSelector::tieBreaker(
    const std::vector<Card>& cards) {
    std::vector<int> values;
    for (const Card& card : cards)
        values.push_back(static_cast<int>(card.rank));
    std::sort(values.rbegin(), values.rend());
    return values;
}

bool HandSelector::isBetter(
    const EvaluationResult& candidate,
    const EvaluationResult& current) {
    if (candidate.rank != current.rank)
        return static_cast<int>(candidate.rank) >
               static_cast<int>(current.rank);
    return tieBreaker(candidate.playedCards) >
           tieBreaker(current.playedCards);
}

EvaluationResult HandSelector::playHand(
    const Hand& source,
    PokerHandChecker& checker) {
    EvaluationResult best{HandRank::HighCard, {}};
    bool hasBest = false;

    for (int a = 0; a < 4; ++a) {
        for (int b = a + 1; b < 5; ++b) {
            for (int c = b + 1; c < 6; ++c) {
                for (int d = c + 1; d < 7; ++d) {
                    for (int e = d + 1; e < 8; ++e) {
                        Hand combination;
                        const int indexes[] = {a, b, c, d, e};
                        for (int index : indexes)
                            combination.playedCards.push_back(
                                source.availableCards[index]);

                        EvaluationResult result =
                            checker.check(combination);
                        if (!hasBest || isBetter(result, best)) {
                            best = result;
                            hasBest = true;
                        }
                    }
                }
            }
        }
    }
    return best;
}
