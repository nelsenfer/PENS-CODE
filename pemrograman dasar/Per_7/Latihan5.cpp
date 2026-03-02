#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = a;
    b = b + 10;
    cout << "Nilai a: " << a << endl; // Output: 5
    cout << "Nilai b: " << b << endl; // Output: 15

    cout << endl;
    int x = 5;

    int *y = &x;                          // y menyimpan alamat dari x
    cout << "variable y = " << y << endl; // alamat dari x karena tidak pakai *
    cout << "isi dari alamat yang di tunjukkan variable y = " << *y << endl;

    *y = 8;
    cout << "Nilai x = " << x << endl;
    cout << "Nilai y = " << *y << endl;

    x = 12;
    cout << "Nilai x = " << x << endl;
    cout << "Nilai y = " << *y << endl;
}