#include <iostream>
using namespace std;

int main()
{
    int score = 50;
    int *pScore = &score;

    cout << "Score awal: " << score << endl; // menampilkan nilai score

    *pScore = 100; // mengubah nilai score melalui pointer

    cout << "Score setelah diubah melalui pointer: " << score << endl; // menampilkan nilai score setelah diubah
    return 0;
}