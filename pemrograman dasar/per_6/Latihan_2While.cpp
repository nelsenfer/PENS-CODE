#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    while (n > 0)
    {
        cout << "Hitung mundur: " << n << endl;
        n--;
    }
    cout << "BOOM!\n";

    /*
    Letakkan kode di bawah ini!
    Hitung naik dari 1 sampai 5 dengan while
    boleh deklarasi variabel baru atau menggunakan variabel n yang terakhir
    */

    while (n < 5)
    {
        n++;
        cout << "Hitung naik: " << n << endl;
    }

    return 0;
}