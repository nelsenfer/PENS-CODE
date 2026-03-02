#include <iostream>
using namespace std;

int main()
{
    int tinggi = 5;

    // segitiga kanan

    for (int i = 1; i <= tinggi; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    cout << "\n";

    // segitiga terbalik
    for (int i = tinggi; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}