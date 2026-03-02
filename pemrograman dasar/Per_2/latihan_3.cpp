#include <iostream>
using namespace std;

int main()
{
    const double phi = 3.14;
    int r = 10;

    // phi = 5.5;
    // error karena phi adalah konstanta

    double luas = phi * r * r;
    cout << "Luas Lingkaran: " << luas << " cm2" << endl;
    return 0;
}