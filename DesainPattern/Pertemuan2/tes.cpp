#include <iostream>
using namespace std;

class Player
{
private:
    // Atribut di-hide agar tidak bisa diubah seenaknya dari luar
    int health;

public:
    // Constructor untuk inisialisasi awal
    Player(int h)
    {
        health = h;
    }

    // Method untuk mengurangi health dengan validasi
    void takeDamage(int dmg)
    {
        health -= dmg;
        // Validasi: health tidak boleh kurang dari 0
        if (health < 0)
        {
            health = 0;
        }
    }

    // Method untuk menambah health (heal)
    void heal(int amount)
    {
        health += amount;
    }

    // Getter untuk membaca nilai health dari luar
    int getHealth()
    {
        return health;
    }
};

int main()
{
    Player p(100);

    // BISA DITANYAKAN SAAT UTS:
    // [link mencurigakan dihapus] = -999; // ERROR! Kompilator akan menolak karena health bersifat private.

    // Cara aman mengubah data melalui method public
    p.takeDamage(20);

    // Cara membaca data melalui getter
    cout << "Player health: " << p.getHealth() << endl; // Output: 80

    return 0;
}