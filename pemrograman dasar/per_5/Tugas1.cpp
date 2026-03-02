#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string nama[2], JenisKelamin[2], Prodi[2], Semester[2];

    cout << "input data mahasiswa" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < 2; ++i)
    {
        cout << "data Mahasiwa ke-" << 1 + i << endl;
        cout << "----" << endl;
        cout << left << setw(19) << "masukkan nama" << ": ";
        cin >> nama[i];
        cout << left << setw(19) << "Jenis Kelamin" << ": ";
        cin >> JenisKelamin[i];
        cout << left << setw(19) << "Program Studi" << ": ";
        cin >> Prodi[i];
        cout << left << setw(19) << "Semester" << ": ";
        cin >> Semester[i];
        cout << "\n";
    };

    cout << "\n\ndata Mahasiwa" << endl;
    cout << "-------------" << endl;
    cout << left << setw(5) << "No." << setw(10) << "nama" << setw(10) << "JK" << setw(10) << "Prodi" << setw(10) << "Semester" << endl;

    for (int i = 0; i < 2; ++i)
    {
        cout << left << setw(5) << 1 + i << setw(10) << nama[i] << setw(10) << JenisKelamin[i] << setw(10) << Prodi[i] << setw(10) << Semester[i] << endl;
    };
}