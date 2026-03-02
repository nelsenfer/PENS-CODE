#include <iostream>
using namespace std;

int hitungDamage(int attack, int defense)
{
    int damage = attack - defense;
    if (damage < 0)
    {
        damage = 0;
    }
    return damage;
}

void tampilkanHasil(string player, string enemy, int damage)
{
    cout << player << " menyerang " << enemy << " dan memberikan  " << damage << " damage!" << endl;
}

int main()
{
    string player = "Knight", enemy = "Goblin";
    int atk = 50, def = 35;
    int damage = hitungDamage(atk, def);
    tampilkanHasil(player, enemy, damage);

    return 0;
}