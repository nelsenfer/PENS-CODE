#include <iostream>
using namespace std;

void tampilkanStatus(string name, int hp, int score)
{
    cout << "Nama: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Skor: " << score << endl;
}

int main()
{
    tampilkanStatus("Hero", 100, 250);
    return 0;
}