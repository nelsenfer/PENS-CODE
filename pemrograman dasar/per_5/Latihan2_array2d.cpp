#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // deklarasi array 2d dengan 2 baris dan 3 kolom
    int data[2][3] = {
        {10, 20, 30},
        {40, 50, 60}};

    cout << "data array 2d: " << endl;
    cout << data[0][0] << " " << data[0][1] << " " << data[0][2] << endl;
    cout << data[1][0] << " " << data[1][1] << " " << data[1][2] << endl;

    // modifikasi data array pertama (menjadi 100)dan data array terakhir (menjadi 90)
    data[0][0] = 100;
    data[1][2] = 90;

    // jumlahkan semua data pada masing-masing baris, kemudian cari selisih keduanya dan tamplkan hasil ke layar
    int jumlah_baris1 = data[0][0] + data[0][1] + data[0][2];
    int jumlah_baris2 = data[1][0] + data[1][1] + data[1][2];
    int selisih = jumlah_baris1 - jumlah_baris2;

    cout << "jumlah baris 1 = " << jumlah_baris1 << endl;
    cout << "jumlah baris 2 = " << jumlah_baris2 << endl;
    cout << "selisih jumlah baris 1 dan baris 2 = " << abs(selisih) << endl;
}