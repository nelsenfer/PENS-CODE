#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int nilai, kehadiran;

    cout << "Masukkan nilai Ujian(0-100): ";
    cin >> nilai;
    cout << "Masukkan jumlah kehadiran(0-16): ";
    cin >> kehadiran;
    cout << "\n"
         << endl;

    if (nilai >= 60)
    {
        if (kehadiran >= 14)
        {
            cout << "===========================================" << endl;
            cout << left << setw(16) << "Nilai Ujian" << setw(16) << "Kehadiran" << setw(16) << "status" << endl;
            cout << "-------------------------------------------" << endl;
            cout << left << setw(16) << nilai << setw(16) << kehadiran << setw(16) << "Lulus" << endl;
            cout << "===========================================" << endl;
        }

        else
        {
            cout << "===========================================" << endl;
            cout << left << setw(16) << "Nilai Ujian" << setw(16) << "Kehadiran" << setw(16) << "status" << endl;
            cout << "-------------------------------------------" << endl;
            cout << left << setw(16) << nilai << setw(16) << kehadiran << setw(16) << "Tidak Lulus (kehadiran kurang)" << endl;
            cout << "===========================================" << endl;
        }
    }
    else
    {
        cout << "===========================================" << endl;
        cout << left << setw(16) << "Nilai Ujian" << setw(16) << "Kehadiran" << setw(16) << "status" << endl;
        cout << "-------------------------------------------" << endl;
        cout << left << setw(16) << nilai << setw(16) << kehadiran << setw(16) << "Tidak Lulus (nilai kurang)" << endl;
        cout << "===========================================" << endl;
    }
}