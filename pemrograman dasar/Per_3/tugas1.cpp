#include <iostream>
using namespace std;

int main()
{
    double suhu;

    cout << "Program konfersi suhu" << endl;
    cout << "===================" << endl;

    cout << "Masukkan suhu dalam Celcius:";
    cin >> suhu;

    cout << "\nSuhu dalam Kelvin\t= " << suhu + 273.15 << " K" << endl;
    cout << "Suhu dalam Fahrenheit\t= " << (suhu * 9 / 5) + 32 << " F" << endl;

    return 0;
}