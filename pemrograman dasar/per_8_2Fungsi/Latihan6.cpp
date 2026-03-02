#include <iostream>
using namespace std;

int tambahSkor(int skor, int bonus)
{
    return skor + bonus;
}

void tampilkanSkor(int skor)
{
    cout << "Skor Sekarang : " << skor << endl;
}

int main()
{
    int score = 100;

    score = tambahSkor(score, 50);
    tampilkanSkor(score);
    return 0;
}