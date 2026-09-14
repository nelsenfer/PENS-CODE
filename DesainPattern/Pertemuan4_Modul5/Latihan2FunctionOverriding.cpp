#include <iostream>
using namespace std;

class Character
{
public:
    virtual void speak()
    {
        cout << "I am a generic character." << endl;
    }
};

class Warrior : public Character
{
public:
    void speak() override
    {
        cout << "I am a Warrior, ready for battle!" << endl;
    }
};

class Mage : public Character
{
public:
    void speak() override
    {
        cout << "I am a Mage, master of magic!" << endl;
    }
};
int main()
{
    Character c;
    Warrior w;
    Mage m;

    Character *ptr; // pointer di stack

    ptr = &c;
    ptr->speak(); // memanggil versi dari Character
    ptr = &w;
    ptr->speak(); // memanggil versi dari Warrior
    ptr = &m;
    ptr->speak(); // memanggil versi dari Mage

    return 0;
}