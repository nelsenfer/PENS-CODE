#include <iostream>
using namespace std;

class Player
{
private:
    int health;

public:
    Player(int h) { health = h; }

    void takedamage(int damage)
    {
        health -= damage;
        if (health < 0)
        {
            health = 0;
        }
    }

    int gethealth()
    {
        return health;
    }
};

int main()
{
    Player p(100);
    // p.health = 50; // Error: 'health' is private within this context
    p.takedamage(20);
    cout << "Health: " << p.gethealth() << endl; // Output: Health: 70
    return 0;
}