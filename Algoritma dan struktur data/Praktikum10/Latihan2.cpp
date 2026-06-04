#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> player;

    player["HP"] = 100;
    player["Mana"] = 50;
    player["Level"] = 10;

    // update
    player["HP"] = 120;

    // tambah
    player["Gold"] = 200;

    // hapus
    player.erase("Mana");

    // tampilkan semua
    for (auto data : player)
    {
        cout << data.first << " : " << data.second << endl;
    }

    return 0;
}