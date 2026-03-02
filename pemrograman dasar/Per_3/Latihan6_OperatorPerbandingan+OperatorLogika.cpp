#include <iostream>
using namespace std;

int main()
{
    int y;

    cout << "masukkan nilai y: ";
    cin >> y;
    cout << " Apakah genap dan positif? " << (y % 2 == 0 && y > 0) << endl;
    return 0;
}