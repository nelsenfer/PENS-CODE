#include <iostream>
using namespace std;

int main()
{
    int angka;
    // do
    // {
    //     cout << "Masukkan angka (0 untuk berhenti): ";
    //     cin >> angka;

    //     if (angka != 0)
    //     {
    //         cout << "Anda memasukkan: " << angka << endl;
    //     }

    // } while (angka != 0);

    // cout << "selesai\n";

    while (angka != 0)
    {
        cout << "Masukkan angka (0 untuk berhenti): ";
        cin >> angka;

        if (angka != 0)
        {
            cout << "Anda memasukkan: " << angka << endl;
        }
    }

    cout << "selesai\n";

    return 0;
}