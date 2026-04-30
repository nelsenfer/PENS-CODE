#include <iostream>
using namespace std;

void preorder(int level, string nama)
{
    cout << "MASUK: " << nama << " (level " << level << ")" << endl;

    if (level >= 2)
    {
        cout << "KELUAR: " << nama << endl;
        return;
    }

    preorder(level + 1, nama + "->kiri");
    preorder(level + 1, nama + "->kanan");

    cout << "KELUAR: " << nama << endl;
}

int main()
{
    preorder(0, "A");
    return 0;
}