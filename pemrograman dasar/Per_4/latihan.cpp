#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int nilai, absensi;

    cout << "Masukkan nilai akhir: ";
    cin >> nilai;
    cout << "Masukkan jumlah absensi: ";
    cin >> absensi;

    if (nilai >= 70)
    {
        if (absensi >= 12)
        {
            cout << "Selamat, Anda lulus!" << endl;
        }
        else
        {
            cout << "Maaf, Anda tidak lulus karena absensi kurang dari 12." << endl;
        }
    }
    else
    {
        cout << "Maaf, Anda tidak lulus karena nilai kurang dari 70." << endl;
    }
}