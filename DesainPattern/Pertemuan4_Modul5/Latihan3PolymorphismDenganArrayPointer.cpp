#include <iostream>
using namespace std;

class Character
{
public:
    virtual void speak()
    {
        cout << "I am a character." << endl;
    }
};

class Warrior : public Character
{
public:
    void speak() override
    {
        cout << "I am a Warrior" << endl;
    }
};

class Mage : public Character
{
public:
    void speak() override
    {
        cout << "I am a Mage" << endl;
    }
};

int main()
{

    Warrior w;
    Mage m;

    Character *party[2]; // array pointer ke Character
    party[0] = &w;       // pointer ke Warrior
    party[1] = &m;       // pointer ke Mage

    cout << "=== Party Members ===" << endl;
    for (int i = 0; i < 2; i++)
    {
        party[i]->speak(); // memanggil versi dari masing-masing class
    }

    return 0;
}