#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "masukkan nilai pertama: ";
    cin >> a;
    cout << "masukkan nilai kedua: ";
    cin >> b;

    cout << "\n=== Operator Relasional ===\n";
    cout << "**keterangan : ( 1 = benar, 0 = salah)**" << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;
    cout << "a > b  : " << (a > b) << endl;
    cout << "a < b  : " << (a < b) << endl;
    cout << "a >= b : " << (a >= b) << endl;
    cout << "a <= b : " << (a <= b) << endl;

    return 0;
}