#include <iostream>
using namespace std;

class character
{
protected:
    int health;

public:
    character(char h) { health = h; }
    int gethealth() { return health; }
};

class enemy : public character
{
public:
    enemy(int h) : character(h) {}
    void reducehealth(int dmg)
    {
        health -= dmg;
    }
};

int main()
{
    enemy e(50);
    e.reducehealth(10);
    cout << "Enemy Health: " << e.gethealth() << endl; // Output: Health: 40
    return 0;
}