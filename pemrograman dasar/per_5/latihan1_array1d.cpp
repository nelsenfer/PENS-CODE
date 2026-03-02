#include <iostream>
using namespace std;

int main()
{

    // deklarasi array berisi 5 data nilai
    int nilai[6] = {80, 77, 91, 60, 83, 82};

    cout << "data awal:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Nilai ke-" << (i + 1) << " = " << nilai[i] << endl;
    }

    // ubah nilai ke-3 menujadi 100, ubah nilai ke 6 mejadi 50
    nilai[2] = 100;
    nilai[5] = 50;

    // tampilkan semua nilai setelah di modifikasi
    cout << "data setelah di ubah : " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Nilai ke-" << (i + 1) << " = " << nilai[i] << endl;
    }

    // cari rata-rata dari nilai ke-1, le-3, dan ke-6. tampilkan ke layar
    float rata_rata = (nilai[0] + nilai[2] + nilai[5]) / 3.0;
    cout << "Rata-rata nilai ke-1, ke-3, dan ke-6 = " << rata_rata << endl;
}