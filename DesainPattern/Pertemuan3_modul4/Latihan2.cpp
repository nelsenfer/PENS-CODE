#include <iostream>
using namespace std;

class Animal
{
public:
    void eat() { cout << "Eating..." << endl; }
};
class Mammal : public Animal
{
public:
    void breathe() { cout << "Breathing..." << endl; }
};
class Dog : public Mammal
{
public:
    void bark() { cout << "Barking!" << endl; }
};

int main()
{
    Dog d;
    d.eat();
    d.breathe();
    d.bark();

    return 0;
}