#include <iostream>
#include <string>
using namespace std;

void ubahNama(string &nama, string &gelar, string &lastname, int level)
{
    nama = gelar + " " + nama + " " + lastname + " - Level " + to_string(level);
    cout << "Nama di dalam fungsi: " << nama << endl;
}

int main()
{
    string player = "Arion";
    string title = "Sir";
    string lastname = "of Light";
    int lv = 15;

    cout << "Nama sebelum fungsi: " << player << endl;
    ubahNama(player, title, lastname, lv);
    cout << "Nama setelah fungsi: " << player << endl;
    return 0;
}