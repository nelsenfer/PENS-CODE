#include "GameManager.h"
#include "HandChecker.h"

int main() {
    FlushFiveChecker c13;
    FlushHouseChecker c12;
    FiveOfAKindChecker c11;
    RoyalFlushChecker c10;
    StraightFlushChecker c9;
    FourOfAKindChecker c8;
    FullHouseChecker c7;
    FlushChecker c6;
    StraightChecker c5;
    ThreeOfAKindChecker c4;
    TwoPairChecker c3;
    PairChecker c2;
    HighCardChecker c1;

    c13.setNext(&c12);
    c12.setNext(&c11);
    c11.setNext(&c10);
    c10.setNext(&c9);
    c9.setNext(&c8);
    c8.setNext(&c7);
    c7.setNext(&c6);
    c6.setNext(&c5);
    c5.setNext(&c4);
    c4.setNext(&c3);
    c3.setNext(&c2);
    c2.setNext(&c1);

    GameManager game(&c13);
    game.runSession();
    return 0;
}
