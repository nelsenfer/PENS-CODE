#include <iostream>
using namespace std;

int main()
{
    int nilai;
    cout << "Masukkan nilai akhir: ";
    cin >> nilai;

    if (nilai >= 60)
    {
        cout << "Selamat, Anda lulus!" << endl;
    }
    else
    {
        cout << "Maaf, Anda tidak lulus." << endl;
    }
    return 0;
}