#include <iostream>
using namespace std;

// fungsi dengan nilai kembalian (return function)
float LuasSegitiga(float alas, float tinggi)
{
    return (alas * tinggi) / 2;
}

float KelilingSegitiga(float sisi_a, float sisi_b, float sisi_c)
{
    return sisi_a + sisi_b + sisi_c;
}

int main()
{
    float a, t;
    cout << "Masukkan alas atau sisi a segitiga: ";
    cin >> a;
    cout << "Masukkan tinggi segitiga: ";
    cin >> t;

    cout << "Luas segitiga adalah: " << LuasSegitiga(a, t) << endl;
    // a dan dan s1 sama karena alas dan sisi a segitiga
    float s2, s3;
    cout << "Masukkan sisi b: ";
    cin >> s2;
    cout << "Masukkan sisi c: ";
    cin >> s3;

    cout << "Keliling segitiga adalah: " << KelilingSegitiga(a, s2, s3) << endl;
    return 0;
}