#include <iostream>
using namespace std;

int hitungBonus(int level)
{
    if (level >= 10)
    {
        return 500;
    }
    else if (level >= 5)
    {
        return 200;
    }
    else
    {
        return 50;
    }
}

int HitungTotalScore(int awal, int bonus)
{
    return awal + bonus;
}

void tampilkanSkorAkhir(string pemain, int totalScore)
{
    cout << "===== Skor Akhir Pemain =====" << endl;
    cout << "Pemain: " << pemain << endl;
    cout << "Total Score: " << totalScore << endl;
}

int main()
{
    string pemain;
    int ScoreAwal, ScoreBonus, ScoreTotal, Level;

    cout << "Masukkan Nama Pemain: ";
    getline(cin, pemain);
    cout << "Masukkan Score Awal: ";
    cin >> ScoreAwal;
    cout << "Masukkan Level Pemain: ";
    cin >> Level;

    ScoreBonus = hitungBonus(Level);
    ScoreTotal = HitungTotalScore(ScoreAwal, ScoreBonus);
    tampilkanSkorAkhir(pemain, ScoreTotal);
    return 0;
}