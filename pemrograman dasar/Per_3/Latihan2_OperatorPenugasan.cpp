#include <iostream>
using namespace std;

int main()
{
    // deklarasi variabel bertipe integer
    int a, b, c, d, e;

    // asignment (pemberian nilai ke variabel)
    a = b = c = 0; // memberikan nilai 0 ke a, b, dan c
    d = 2;         // memberikan nilai 2 ke d
    e = 5;         // memberikan nilai 5 ke e

    // asignment dengan operasi aritmatika
    a += 2; // sama dengan a = a + 2
            //       a = 0 + 2
            //       a = 2
    cout << "setelah a += 2, a = " << a << endl;

    d--; // sama dengan d = d - 1
         //       d = 2 - 1
         //       d = 1
    cout << "setelah d--, d = " << d << endl;

    d *= 10;
    cout << "setelah d *= 10, d = " << d << endl;

    d /= 2;
    cout << "setelah d /= 2, d = " << d << endl;

    d %= 2;
    cout << "setelah d %= 2, d = " << d << endl;

    return 0;
}