#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //===========================
    // 1. array 1d tanpa ukuran
    //===========================

    int angka[] = {10, 20, 30, 40, 50}; // ukuran otomatis -
    for (int i = 0; i < 5; i++)
    {
        cout << "elemen ke-" << i + 1 << " = " << angka[i] << endl;
    };

    //===========================
    // 2. array 2d tanpa ukuran baris
    //===========================

    int matrik[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(3) << matrik[i][j];
        };
        cout << "\n";
    };
}
