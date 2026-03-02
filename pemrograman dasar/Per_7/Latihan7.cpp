#include <iostream>
using namespace std;

void UbahNilai(int &x)
{
    x = x + 10;
    cout << "Nilai di dalam fungsi = " << x << endl;
}

int main()
{
    int a = 5;
    cout << "Nilai sebelum fungsi = " << a << endl;
    UbahNilai(a);
    cout << "Nilai setelah fungsi = " << a << endl;

    return 0;
}