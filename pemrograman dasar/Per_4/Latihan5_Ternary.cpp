#include <iostream>
#include <string>
using namespace std;

int main()
{
    int nilai;
    string hasil;

    cout << "Masukkan nilai Ujian: ";
    cin >> nilai;

    hasil = (nilai >= 60) ? "Lulus" : "Tidak Lulus";
    cout << "status: " << hasil << endl;
    return 0;
}