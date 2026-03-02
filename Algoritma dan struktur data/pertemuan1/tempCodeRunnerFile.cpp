#include <iostream>
using namespace std;

struct dtnilai
{
    char nrp[10];
    char nama[20];
    double nilai;
};

dtnilai mahasiswa[10];
int j = 0;

void tambah_data()
{
    char jawab;

    while (true)
    {
        cout << "Masukkan NRP: ";
        cin >> mahasiswa[j].nrp;

        cout << "Masukkan Nama: ";
        cin >> mahasiswa[j].nama;

        cout << "Masukkan Nilai: ";
        cin >> mahasiswa[j].nilai;

        cout << "Input data lagi? (y/t): ";
        cin >> jawab;

        if (jawab == 'y' || jawab == 'Y')
        {
            j++;
        }
        else
        {
            break;
        }

        if (j >= 10)
        {
            cout << "Data penuh!\n";
            break;
        }
    }
}

void tampil()
{
    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i <= j; i++)
    {
        cout << "NRP: " << mahasiswa[i].nrp
             << ", Nama: " << mahasiswa[i].nama
             << ", Nilai: " << mahasiswa[i].nilai << endl;
    }
}

int main()
{
    tambah_data();
    tampil();
    return 0;
}
