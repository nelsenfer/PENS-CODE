#include <iostream>
using namespace std;

int main()
{
    // dekralasi array 1d berisi 5 elemen

    int angka[5] = {10, 20, 30, 40, 50};

    // tampilkan semua elemen pada array ke layar menggunakan perulangan for
    cout << "data pada array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "elemen ke-" << i + 1 << " = " << angka[i] << endl;
    };

    return 0;
}