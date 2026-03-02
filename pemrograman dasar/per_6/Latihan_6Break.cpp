#include <iostream>
using namespace std;

int main()
{

    for (int i = 1; i <= 100; i++)
    {
        cout << i << " ";
        if (i % 8 == 0)
        {
            cout << "Kelipatan 8 pertama : " << i << endl;
            break;
            cout << "apakah saya di cetak di layar?";
        }
    }
    return 0;
}