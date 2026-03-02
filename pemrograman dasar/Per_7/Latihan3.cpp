#include <iostream>
using namespace std;

void salam(string nama, int umur, string asal)
{ // Parameter formal
    cout << "Hallo, " << nama << "!" << endl;
    cout << "Umur Anda " << umur << " tahun." << endl;
    cout << "Anda berasal dari " << asal << "." << endl;
}

int main()
{
    string nama_user, asal_user;
    int umur_user;
    cout << "Masukkan nama Anda: ";
    getline(cin, nama_user);
    cout << "Masukkan umur Anda: ";
    cin >> umur_user;
    cout << "Masukkan asal Anda: ";
    cin >> asal_user;
    salam(nama_user, umur_user, asal_user); // nama_user Parameter aktual / argumen
    return 0;
}