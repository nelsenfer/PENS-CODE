#include <iostream>
using namespace std;

class Character
{
public:
    virtual void Attack()
    {
        cout << "I am a character." << endl;
    }

    ~Character() {} // virtual destructor agar aman jika di pakai delete pada pointer ke base class
};

class Warrior : public Character
{
public:
    void Attack() override
    {
        cout << "Warrior Swing a sword" << endl;
    }
};

class Mage : public Character
{
public:
    void Attack() override
    {
        cout << "Mage Cast a Firewall" << endl;
    }
};

class Archer : public Character
{
public:
    void Attack() override
    {
        cout << "Archer Shoot an Arrow" << endl;
    }
};

int main()
{
    Character *team[3];      // array pointer ke Character
    team[0] = new Warrior(); // pointer ke Warrior
    team[1] = new Mage();    // pointer ke Mage
    team[2] = new Archer();  // pointer ke Archer

    for (int i = 0; i < 3; i++)
    {
        team[i]->Attack(); // memanggil versi dari masing-masing class
    }

    return 0;
}