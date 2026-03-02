#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string nama[5];
    int Jumlah[5];
    string izin;
    int jenis_barang = 0;
    int total = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Apakah Anda ingin belanja? (y/n): ";
        cin >> izin;

        if (izin != "y" && izin != "Y")
        {
            break;
        }

        cout << "Masukkan nama barang: ";
        cin >> nama[i];
        cout << "Masukkan jumlah: ";
        cin >> Jumlah[i];
        cout << endl;

        total += Jumlah[i];
        jenis_barang++;
    }

    cout << "\n\nDaftar belanja (" << jenis_barang << " item);" << endl;
    cout << left << setw(19) << "Nama" << setw(20) << "Jumlah" << endl;
    cout << "-------------------------" << endl;

    int i = 0;
    while (i < jenis_barang)
    {
        cout << left << setw(15) << nama[i] << right << setw(10) << Jumlah[i] << endl;
        i++;
    }
    cout << "-------------------------" << endl;
    cout << "Total quantity: " << total << endl;

    return 0;
}