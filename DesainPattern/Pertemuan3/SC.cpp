#include <iostream>
using namespace std;

class Character
{
private:
    int health;

public:
    Character(int initialHealth) : health(initialHealth) {}

    void takeDamage(int dmg)
    {
        health -= dmg;
        if (health < 0)
        {
            health = 0;
        }
    }

    void heal(int amount)
    {
        health += amount;
    }

    int getHealth() const
    {
        return health;
    }
};

int main()
{
    Character player(100);
    Character enemy(55);

    cout << "Hero | HP: " << player.getHealth() << endl;
    cout << "Goblin | HP: " << enemy.getHealth() << endl;

    int turn = 1;
    while (enemy.getHealth() > 0)
    {
        cout << "\n-- Turn " << turn << " --" << endl;

        player.takeDamage(12);
        enemy.takeDamage(18);

        cout << "Goblin | HP: " << enemy.getHealth();

        if (enemy.getHealth() == 0)
        {
            cout << " (KO)" << endl;
            break;
        }

        cout << endl;
        cout << "Hero | HP: " << player.getHealth() << endl;

        ++turn;
    }

    cout << "\nHasil: Hero menang." << endl;

    return 0;
}