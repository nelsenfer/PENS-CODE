#include <iostream>
using namespace std;

int main()
{
    int x = 25;
    int *px = &x;

    cout << "akses direct nilai x: " << x << endl;
    cout << "akses indirect nilai pX: " << *px << endl;

    *px = 40; // mengubah nilai x melalui pointer pX
    cout << "nilai x setelah diubah melalui pointer pX: " << x << endl;
    return 0;
}