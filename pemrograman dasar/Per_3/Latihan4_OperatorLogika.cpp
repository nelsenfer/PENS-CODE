#include <iostream>
using namespace std;

int main()
{
    bool x, y;

    cout << "masukkan nilai logika x ( 0 = false atau 1 = true ): ";
    cin >> x;
    cout << "masukkan nilai logika y ( 0 = false atau 1 = true ): ";
    cin >> y;

    cout << "\n=== Hasil Operator Logika ===\n";
    cout << " X AND Y ( X && Y ) : " << (x && y) << endl;
    cout << " X OR Y  ( X || Y ) : " << (x || y) << endl;
    cout << " NOT X   ( !X )     : " << (!x) << endl;
    cout << " NOT Y   ( !Y )     : " << (!y) << endl;

    return 0;
}