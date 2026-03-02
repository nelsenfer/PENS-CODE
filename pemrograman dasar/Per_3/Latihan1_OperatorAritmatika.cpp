#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "\n=== operasi aritmatika ===\n";
    cout << "masukkan nilai pertama: ";
    cin >> a;
    cout << "masukkan nilai kedua: ";
    cin >> b;

    // operrasi aritmatika
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a % b = " << a % b << endl;

    // hierarki operator aritmatika
    cout << "\n\nHierarki operator aritmatika" << endl;
    cout << "----------------------------" << endl;
    cout << "hasil dari 2 + 3 * 5 -2 adalah " << 2 + 3 * 5 - 2 << endl;

    // tanda ()
    cout << "hasil dari (2 + 4) * 3 - 2 adalah " << (2 + 4) * 3 - 2 << endl;
    cout << "hasil dari (2 + 4 - 1) % 2 adalah " << (2 + 4 - 1) % 2 << endl;

    return 0;
}