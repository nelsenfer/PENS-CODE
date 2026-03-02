#include <iostream>
#include <cmath>
using namespace std;

struct Polar
{
    double r;
    double alpha;
};

struct Kartesian
{
    double x;
    double y;
};

int main()
{
    Polar p1;
    Kartesian k1;

    cout << "Masukkan nilai r untuk koordinat polar: ";
    cin >> p1.r;

    cout << "Masukkan nilai alpha (dalam radian): ";
    cin >> p1.alpha;

    k1.x = p1.r * cos(p1.alpha);
    k1.y = p1.r * sin(p1.alpha);

    cout << "\nNilai koordinat kartesian untuk polar\n";
    cout << "r = " << p1.r << " alpha = " << p1.alpha << endl;
    cout << "x = " << k1.x << "  y = " << k1.y << endl;

    return 0;
}
