#include <iostream>
using namespace std;

int main()
{

    // cetak semua keculali kelipatan 8

    for (int i = 0; i < 100; i += 2)
    {
        if (i % 8 == 0)
        {
            continue;
        }
        cout << i << " ";
    }

    cout << "\n";
}