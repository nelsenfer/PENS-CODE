#include <iostream>
using namespace std;

void sapa(string nama = "Mahasiswa", string kampus = "PENS", string jurusan = "Game Technology")
{
    cout << "Hallo, " << nama << " dari " << kampus << "!, dengan jurusan " << jurusan << endl;
}

int main()
{
    sapa();
    sapa("john");
    sapa("john", "ITS");
    sapa("john", "ITS", "Informatika");
    return 0;
}