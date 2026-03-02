#include <iostream>
using namespace std;

int main()
{
    int y, x = 67;
    int *px;

    px = &x;
    y = *px;

    cout << "alamat x: " << &x << endl;
    cout << "isi px: " << px << endl;
    cout << "isi x: " << x << endl;
    cout << "nilai yang ditunjuk oleh px: " << *px << endl;
    cout << "nilai y: " << y << endl;

    return 0;
}