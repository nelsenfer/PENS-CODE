#include <iostream>
using namespace std;

int luasPersegi(int a)
{
    return a * a;
}

int kelilingPersegi(int a)
{
    return 4 * a;
}

int main()
{
    int sisi;
    cout << "Masukkan panjang sisi persegi: ";
    cin >> sisi;
    cout << "Luas persegi: " << luasPersegi(sisi) << endl;
    cout << "Keliling persegi: " << kelilingPersegi(sisi);

    return 0;
}