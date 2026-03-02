#include <iostream>
#include <cmath>
using namespace std;

int tambah(double a, double b)
{
    return a + b;
}

int kurang(double a, double b)
{
    return a - b;
}

int kali(double a, double b)
{
    return a * b;
}

int bagi(double a, double b)
{
    return a / b;
}

int pangkat(double a, double b)
{
    return pow(a, b);
}

double akar(double a)
{
    return sqrt(a);
}

int main()
{
    string izin;
    double angka1, angka2, hasil;
    char op;

    cout << "Apakah Anda ingin menggunakan kalkulator? (y/n): ";
    cin >> izin;

    while (izin == "y" || izin == "Y")
    {
        cout << "Masukkan angka pertama: ";
        cin >> angka1;
        cout << "Masukkan operator Matematika (+, -, *, /, ^, r): ";
        cin >> op;
        cout << "Masukkan angka kedua (jika operator akar, masukkan 0): ";
        cin >> angka2;

        switch (op)
        {
        case '+':
            hasil = tambah(angka1, angka2);
            cout << "Hasil: " << hasil << endl;
            break;
        case '-':
            hasil = kurang(angka1, angka2);
            cout << "Hasil: " << hasil << endl;
            break;
        case '*':
            hasil = kali(angka1, angka2);
            cout << "Hasil: " << hasil << endl;
            break;
        case '/':
            hasil = bagi(angka1, angka2);
            cout << "Hasil: " << hasil << endl;
            break;
        case '^':
            hasil = pangkat(angka1, angka2);
            cout << "Hasil: " << hasil << endl;
            break;
        case 'r':
            hasil = akar(angka1);
            cout << "Hasil: " << hasil << endl;
            break;
        }
        cout << "Apakah Anda ingin melakukan perhitungan lagi? (y/n): ";
        cin >> izin;
    }
    cout << "Terima kasih telah menggunakan kalkulator!" << endl;
    return 0;
}