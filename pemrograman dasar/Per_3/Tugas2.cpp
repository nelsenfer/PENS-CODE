#include <iostream>
using namespace std;

int main()
{
    int umur;

    cout << "Masukkan umur anda: ";
    cin >> umur;
    cout << "Apakah anda remaja (13 - 19 Tahun)? " << (umur >= 13 && umur <= 19) << endl;
    return 0;
}