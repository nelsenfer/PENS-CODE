#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 20;
    int *p;

    p = &a; // p menunjuk ke a
    cout << "Nilai a: " << a << endl;
    cout << "Pointer menunjuk a, *p: " << *p << endl;

    p = &b; // p sekarang menunjuk ke b
    cout << "\nNilai b: " << b << endl;
    cout << "Pointer menunjuk b, *p: " << *p << endl;

    cout << "\nisi pointer p sekarang adalah: " << p << endl;
    cout << "dengan nilai: " << *p << endl;
    return 0;
}