#include <iostream>
using namespace std;

int main()
{
    int Pilihan;

    cout << "==== Menu Makanan ====" << endl;
    cout << "1. Nasi Goreng" << endl;
    cout << "2. Mie Ayam" << endl;
    cout << "3. Sate Ayam" << endl;
    cout << "4. Bakso" << endl;
    cout << "pilih menu (1-4): ";
    cin >> Pilihan;

    switch (Pilihan)
    {
    case 1:
        cout << "Anda memilih Nasi Goreng." << endl;
        break;
    case 2:
        cout << "Anda memilih Mie Ayam." << endl;
        break;
    case 3:
        cout << "Anda memilih Sate Ayam." << endl;
        break;
    case 4:
        cout << "Anda memilih Bakso." << endl;
        break;
    default:
        cout << "Pilihan tidak Tersedia." << endl;
        break;
    }

    return 0;
}