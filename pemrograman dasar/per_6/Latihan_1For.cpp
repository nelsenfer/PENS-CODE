#include <iostream>
using namespace std;

int main()
{
    // cetak angka 1 sampai 10

    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }

    cout << endl;

    /*
    Letakkan di bawah sini. cetak ke layar dengan urutan terbalik 10 sampai 1
    */

    for (int i = 10; i >= 1; i--)
    {
        cout << i << " ";
    }

    cout << "\nselesai";
}