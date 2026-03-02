#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha;
    string nama;
    int umur;
    double ipk;
    string kelas;
    int inputStatus;
    bool Status;

    cout << "masukan nama :";
    getline(cin, nama);

    cout << "masukan umur :";
    cin >> umur;

    cout << "masukan ipk :";
    cin >> ipk;

    cout << "masukan kelas (A/B/C) :";
    cin >> kelas;
    kelas = toupper(kelas[0]);

    cout << "Apakah sudah lulus? (1 = iya , 0 = tidak) :";
    cin >> inputStatus;

    if (inputStatus == 1)
    {
        Status = true;
    }
    else
    {
        Status = false;
    }

    cout << "== Data Mahasiswa==" << endl;
    cout << "Nama\t: " << nama << endl;
    cout << "Umur\t: " << umur << endl;
    cout << "Ipk\t: " << ipk << endl;
    cout << "Kelas\t: " << kelas << endl;
    cout << "Status Lulus: " << Status << endl;
}