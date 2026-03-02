#include <iostream>
using namespace std;

int main()
{
    int a = 6; // dalam biner: 0000 0110
    int b = 3; // dalam biner: 0000 0011

    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;

    cout << "a & b = " << (a & b) << endl;    // AND
    cout << "a | b = " << (a | b) << endl;    // OR
    cout << " a << 1 = " << (a << 1) << endl; // gesser kiri
    cout << " a >> 1 = " << (a >> 1) << endl; // geser kanan
    return 0;
}