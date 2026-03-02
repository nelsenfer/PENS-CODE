#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    // setw(n) -> set width mengatur lebar kolom
    cout << setw(10) << "Nama" << setw(5) << "Nilai" << endl;

    // fixed + setprecision(n) -> mengatur jumlah angka dibelakang koma
    cout << right << setw(10) << "Ani" << setw(10) << fixed << setprecision(2) << 87.456 << endl;

    cout << left << setw(10) << "Budi" << setw(10) << fixed << setprecision(3) << 90.5 << endl;

    // setw + setfill untuk mengisi area kolom dari setw yang kosong
    cout << setfill('-') << setw(10) << "123" << endl;
    return 0;
}