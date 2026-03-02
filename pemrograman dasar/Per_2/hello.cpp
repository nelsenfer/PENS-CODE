#include <iostream>
using namespace std;

int main()
{
    cout << "Nelsen Febri Handaka" << endl;
    cout << "Tulungagung" << endl;
    cout << "NRP.5225600095" << endl;

    int alas = 10;
    int tinggi = 20;
    int Luas_segitiga;

    Luas_segitiga = (alas * tinggi) / 2;
    cout << "Luas Segitiga: " << Luas_segitiga << "cm2" << endl;

    string nama;
    int umur;
    cout << "Masukkan nama lengkap anda: ";
    getline(cin, nama);
    cout << "Masukkan umur anda: ";
    cin >> umur;
    cout << "\nHalo, selamat datang " << nama << "!" << " \numur anda : " << umur << " tahun\n"
         << endl;

    // int angka;

    // cout << "Masukkan sebuah angka: ";
    // cin >> angka;

    // if (angka % 2 == 0)
    // {
    //     cout << angka << " adalah bilangan GENAP." << endl;
    // }
    // else
    // {
    //     cout << angka << " adalah bilangan GANJIL." << endl;
    // }

    // int angka[5];
    // cout << "Masukkan 5 angka: " << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> angka[i];
    // }

    // cout << "Data yang kamu masukkan: ";
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << angka[i] << " ";
    // }
}
