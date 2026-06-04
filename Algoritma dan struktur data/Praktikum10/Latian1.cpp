#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> player;

    // insert
    player["HP"] = 100;
    player["Mana"] = 50;
    player["Level"] = 10;

    // akses
    cout << "HP: " << player["HP"] << endl;
    cout << "Mana: " << player["Mana"] << endl;
    return 0;
}