#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    cout << "array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << "\n";

    /*
    Letakkan kode di bawah ini!
    buat variable array bertipe string dengan 5 nama.
    kemudian tampilkan ke layar dengan range based for
    */

    string nama[] = {"Andi", "Budi", "Caca", "Dodi", "Erik"};
    cout << "nama orang: ";

    for (string n : nama)
    {
        cout << n << ", ";
    }

    return 0;
}