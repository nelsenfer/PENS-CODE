#include <iostream>
using namespace std;

void ubahNilai(int x)
{
    x = x + 10;
    cout << "Nilai di dalam fungsi = " << x << endl;
}

int main()
{
    int a = 5;
    cout << "Nilai sebelum fungsi dipanggil = " << a << endl;
    ubahNilai(a);
    cout << "Nilai setelah fungsi dipanggil = " << a << endl;
    return 0;
}