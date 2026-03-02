#include <iostream>
using namespace std;

int main()
{
    int tinggi;

    cout << "Masukkan tinggi (angka positif): ";
    cin >> tinggi;

    for (int i = 1; i <= tinggi; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = tinggi; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= tinggi; i++)
    {
        for (int j = tinggi; j > i; j--)
        {
            cout << " ";
        }

        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }

        for (int l = 1; l < i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}