#include <iostream>
using namespace std;

int hitungDamage(int atk, int def)
{
    int damage = atk - def;
    if (damage < 0)
    {
        damage = 0;
    }
    return damage;
}

int main()
{
    int atk = 40, def = 25;
    int dmg = hitungDamage(atk, def);
    cout << "Damage yang diterima musuh: " << dmg << endl;
    return 0;
}