#include <iostream>
#include <iomanip>
using namespace std;

void tampilkanData(string n, string j, string k, int s, float ip)
{
    cout << left << setw(10) << n << setw(10) << j << setw(10) << k << setw(10) << s << setw(10) << fixed << setprecision(2) << ip;
}

int main()
{
    string nama[10] = {"Andi", "Budi", "Caca", "Deni", "Eka", "Fani", "Gina", "Hani", "Indra", "Joko"};
    string jurusan[10] = {"GT", "GT", "GT", "TeKom", "TeKom", "IT", "IT", "IT", "MeKa", "MeKa"};
    string kelas[10] = {"A", "B", "C", "D", "B", "A", "B", "C", "C", "D"};
    int semester[10] = {1, 3, 5, 7, 1, 3, 5, 7, 1, 3};
    float ipk[10] = {3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 3.4, 3.3, 3.2, 3.1};

    cout << "Data Mahasiswa" << endl;
    cout << "======================" << endl;
    cout << left << setw(5) << "No" << setw(10) << "Nama" << setw(10) << "Jurusan" << setw(10) << "Kelas" << setw(10) << "Semester" << setw(10) << "IPK" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << left << setw(5) << (i + 1);
        tampilkanData(nama[i], jurusan[i], kelas[i], semester[i], ipk[i]);
        cout << endl;
    }
}