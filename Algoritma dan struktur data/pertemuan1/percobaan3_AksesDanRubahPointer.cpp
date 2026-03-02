#include <iostream>
using namespace std;

int main()
{
    float d = 54.5f, *pd;
    cout << "Nilai d awal: " << d << endl;

    pd = &d;
    *pd += 10;
    cout << "Nilai d setelah diubah: " << d << endl;
    return 0;
}