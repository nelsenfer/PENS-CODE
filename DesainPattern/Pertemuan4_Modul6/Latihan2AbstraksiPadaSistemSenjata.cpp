#include <iostream>
using namespace std;
// class abstrak : kerangka dasar semua senjata
class weapon
{
public:
    virtual void attack() = 0; // fungsi abstract
    void reload()
    {
        cout << "Reloading weapon.....\n";
    }
};

// Class turunan: pedang
class sword : public weapon
{
public:
    void attack() override
    {
        cout << "slash with sword\n";
    }
};

// Class turunan: senjata api
class gun : public weapon
{
public:
    void attack() override
    {
        cout << "shoot with gun\n";
    }
};

class bow : public weapon
{
public:
    void attack() override
    {
        cout << "shoot with bow!\n";
    }
};

void AttackAll(weapon *weapons[], int jumlahSenjata)
{
    for (int i = 0; i < jumlahSenjata; i++)
    {
        weapons[i]->attack();
    }
}

int main()
{
    weapon *weapons[3];       // array pointer ke Weapon
    weapons[0] = new sword(); // pointer ke Sword
    weapons[1] = new gun();   // pointer ke Gun
    weapons[2] = new bow();   // pointer ke Bow

    AttackAll(weapons, 3);

    for (int i = 0; i < 3; i++)
    {
        delete weapons[i];
    }

    return 0;
}