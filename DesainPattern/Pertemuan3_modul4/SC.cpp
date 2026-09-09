#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name;
    int hunger;

public:
    Animal(string n, int h) : name(n), hunger(h) {}

    string getName() const
    {
        return name;
    }

    int getHunger() const
    {
        return hunger;
    }

    void feed(int amount)
    {
        hunger -= amount;

        if (hunger < 0)
        {
            hunger = 0;
        }
    }

    void showStatus() const
    {
        cout << "Name: " << name << " | Hunger: " << hunger << endl;
    }
};

class Mammal : public Animal
{
public:
    Mammal(string n, int h) : Animal(n, h) {}

    void makeSound() const
    {
        cout << getName() << " says: *roar*" << endl;
    }
};

class Bird : public Animal
{
public:
    Bird(string n, int h) : Animal(n, h) {}

    void flap() const
    {
        cout << getName() << " flaps its wings." << endl;
    }
};

int main()
{
    Mammal lion("Lion", 40);
    Bird eagle("Eagle", 70);

    lion.showStatus();
    eagle.showStatus();

    lion.feed(20);
    eagle.feed(10);

    lion.showStatus();
    eagle.showStatus();

    lion.makeSound();
    eagle.flap();

    return 0;
}