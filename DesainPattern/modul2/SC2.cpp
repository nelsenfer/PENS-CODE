#include <iostream>
using namespace std;

class Player
{
public:
    string name;
    int health;

    // Konstruktor inisialisasi name dan health
    Player(string playerName, int playerHealth)
    {
        name = playerName;
        health = playerHealth;
    }

    // Pass-by-reference (&) agar yang berkurang adalah HP musuh asli, bukan copy-annya
    void attack(Player &enemy)
    {
        cout << name << " menyerang " << enemy.name << "!" << endl;
        enemy.health -= 10;
        cout << "-> " << enemy.name << " menerima 10 damage." << endl;
    }

    void displayHealth()
    {
        cout << "Sisa Health " << name << ": " << health << endl;
    }
};

int main()
{
    Player hero("Nelss", 100);
    Player monster("Slime", 30);

    hero.displayHealth();
    monster.displayHealth();

    cout << "\n--- Pertarungan Dimulai ---\n";

    // hero menyerang monster
    hero.attack(monster);

    cout << "\n--- Status Terkini ---\n";
    hero.displayHealth();
    monster.displayHealth();

    return 0;
}