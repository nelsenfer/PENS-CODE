#include <iostream>
using namespace std;

void tambahlima(int &nilai)
{

    cout << "niali alamat di fungsi: " << nilai << endl;
    nilai += 5;

    cout << "nilai: " << nilai << endl;
    cout << "niali alamat di fungsi: " << nilai << endl;
}

int main()
{
    int power = 10;
    cout << "power sebelum fungsi: " << power << endl;

    tambahlima(power);

    cout << "power setelah fungsi: " << power << endl;
    return 0;
}