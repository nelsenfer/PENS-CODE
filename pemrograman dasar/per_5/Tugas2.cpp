#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string nama_mahasiswa[4] = {"jhon", "jane", "putra", "putri"};
    string nilai[4][3] = {
        {"90", "80", "70"},
        {"50", "60", "80"},
        {"75", "85", "90"},
        {"85", "95", "80"}};

    cout << "Data Nilai Mahasiswa" << endl;
    cout << "--------------------" << endl;
    cout << left << setw(5) << "NO." << setw(10) << "Nama" << setw(15) << "B. Indoneisa" << setw(15) << "Matematika" << setw(15) << "B. Inggris" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << left << setw(5) << 1 + i << setw(10) << nama_mahasiswa[i];

        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(15) << nilai[i][j];
        };

        cout << "\n";
    };
}