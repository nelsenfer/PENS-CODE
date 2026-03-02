#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *px = &x;

    cout << "Nilai x: " << x << endl;                       // menampilkan nilai x
    cout << "Alamat x: " << &x << endl;                     // menampilkan alamat x
    cout << "isi pointer px: " << px << endl;               // menampilkan isi pointer px (alamat x)
    cout << "Nilai yang ditunjuk oleh px: " << *px << endl; // menampilkan nilai yang ditunjuk oleh px
    return 0;
}