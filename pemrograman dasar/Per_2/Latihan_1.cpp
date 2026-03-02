#include <iostream>
using namespace std;

int main()
{
    // deklarasi + inisiasi

    int a = 2;
    int b = 3;

    cout << "Nilai variable a saat ini: " << a << endl;
    cout << "Nilai variable b saat ini: " << b << endl;
    cout << endl;

    a = 4; // merubah nilai variable a dari 2 menjadi 4
    b = 5; // merubah nilai variable b dari 3 menjadi 5
    b = 9; // merubah nilai variable b dari 5 menjadi 9
    b = 7; // merubah nilai variable b dari 9 menjadi 7

    cout << "Nilai variable a saat ini: " << a << endl; // output yang dihasilkan adalah 4 setelah diubah dari 2 menjadi 4
    cout << "Nilai variable b saat ini: " << b << endl; // output yang dihasilkan adalah 7 setelah diubah dari 3 menjadi 5, 9, dan 7

    return 0;
}
