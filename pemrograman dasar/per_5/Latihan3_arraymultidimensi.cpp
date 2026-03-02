#include <iostream>
using namespace std;

int main()
{
    // array 3d dengan ukuran [2] [2] [3]
    // angka [blok] [baris] [kolom]

    int angka[2][2][3] = {
        // blok 1
        {
            {1, 2, 3}, // baris 1
            {4, 5, 6}  // baris 2
        },
        // blok 2
        {
            {7, 8, 9},   // baris 1
            {10, 11, 12} // baris 2
        }};

    // tampilkan semua elemen pada array ke layar
    cout << "data array 3d: " << endl;
    for (int i = 0; i < 2; i++) // blok
    {
        for (int j = 0; j < 2; j++) // baris
        {
            for (int k = 0; k < 3; k++) // kolom
            {
                cout << angka[i][j][k] << " ";
            }
            cout << endl; // ganti baris setelah mencetak semua kolom dalam satu baris
        }
    }
}