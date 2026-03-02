#include <iostream>
#include <iomanip>
using namespace std;

int NilaiAkhir(int tugas, int uts, int uas)
{
    return 0.3 * tugas + 0.3 * uts + 0.4 * uas;
}

string Predikat(double na)
{
    if (na >= 85)
        return "A";
    else if (na >= 70)
        return "B";
    else if (na >= 55)
        return "C";
    else if (na >= 40)
        return "D";
    else
        return "E";
}

int main()
{
    int jumlahMahasiswa;
    string namaMahasiswa[10];
    int nilai[10][3];
    double nilaiAkhir;
    string Pred;

    do
    {
        cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
        cin >> jumlahMahasiswa;
    } while (jumlahMahasiswa < 1 || jumlahMahasiswa > 10);

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Masukkan nama mahasiswa ke-" << (i + 1) << ": ";
        cin >> namaMahasiswa[i];
        cout << "Masukkan nilai Tugas, UTS, dan UAS (0 - 100): ";
        for (int j = 0; j < 3; j++)
        {
            cin >> nilai[i][j];
        }
    }

    cout << left << setw(18) << "\nNama" << setw(10) << "Tugas" << setw(10) << "UTS" << setw(10) << "UAS" << setw(10) << "Akhir" << setw(10) << "Pred" << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++)
    {

        nilaiAkhir = NilaiAkhir(nilai[i][0], nilai[i][1], nilai[i][2]);
        Pred = Predikat(nilaiAkhir);
        cout << left << setw(18) << namaMahasiswa[i] << setw(10) << nilai[i][0] << setw(10) << nilai[i][1] << setw(10) << nilai[i][2] << setw(10) << fixed << setprecision(2) << nilaiAkhir << setw(10) << Pred;
        cout << endl;
    }
}