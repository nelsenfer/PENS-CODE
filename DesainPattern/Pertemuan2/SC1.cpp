#include <iostream>
using namespace std;

class Weapon
{
public:
    string name;
    int damage;

    // Konstruktor untuk inisialisasi atribut
    Weapon(string weaponName, int weaponDamage)
    {
        name = weaponName;
        damage = weaponDamage;
    }

    void attack()
    {
        cout << "Menyerang dengan " << name << ", memberikan " << damage << " kerusakan!" << endl;
    }
};

int main()
{
    // Membuat 3 objek senjata berbeda
    Weapon sword("Pedang Excalibur", 50);
    Weapon bow("Panah Elf", 35);
    Weapon axe("Kapak Orc", 65);

    // Menguji method attack
    sword.attack();
    bow.attack();
    axe.attack();

    return 0;
}