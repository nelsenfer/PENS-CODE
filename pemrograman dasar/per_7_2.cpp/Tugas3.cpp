#include <iostream>
#include <iomanip>
using namespace std;

float hitungRata(float total, int n)
{
    return total / n;
}

int hitungHebat(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 80)
        {
            count++;
        }
    }
    return count;
}

int cariMaks(int arr[], int n)
{
    int maks = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maks)
        {
            maks = arr[i];
        }
    }
    return maks;
}

int cariMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

string performa(int rata)
{
    if (rata >= 80)
        return "Luar Biasa";
    else if (rata <= 79 && rata > 60)
        return "Baik";
    else
        return "Perlu latihan lagi";
}

int main()
{
    const int MAX = 20;
    int score[MAX];
    int jumlahRonde;
    float totalScore = 0;
    float rataRata = 0;

    cout << "Masukkan jumlah ronde: ";
    cin >> jumlahRonde;

    for (int i = 0; i < jumlahRonde; i++)
    {
        cout << "Masukkan skor ronde ke-" << (i + 1) << ": ";
        cin >> score[i];
        if (score[i] < 0 || score[i] > 100)
        {
            cout << "Skor tidak valid. Masukkan skor antara 0 dan 100." << endl;
            i--;
            continue;
        }

        totalScore += score[i];
    }

    cout << "Total skor: " << fixed << setprecision(2) << totalScore << endl;
    rataRata = hitungRata(totalScore, jumlahRonde);
    cout << "Rata-rata: " << rataRata << endl;
    cout << "Jumlah ronde hebat: " << hitungHebat(score, jumlahRonde) << endl;
    cout << "Skor maksimum: " << cariMaks(score, jumlahRonde) << endl;
    cout << "Skor minimum: " << cariMin(score, jumlahRonde) << endl;
    cout << "Performa: " << performa(rataRata) << endl;
    return 0;
}