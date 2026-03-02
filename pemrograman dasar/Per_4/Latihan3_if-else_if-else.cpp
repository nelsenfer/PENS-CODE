#include <iostream>
using namespace std;

int main()
{
    int nilai;

    cout << "Masukkan nilai ujian: ";
    cin >> nilai;

    if (nilai >= 85)
    {
        cout << "sangat baik (A)" << endl;
    }
    else if (nilai >= 70)
    {
        cout << "baik (B)" << endl;
    }
    else if (nilai >= 55)
    {
        cout << "cukup (C)" << endl;
    }
    else
    {
        cout << "Tidak Lulus (D)" << endl;
    }
    return 0;
}