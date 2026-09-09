#include <iostream>
using namespace std;

class Flyer
{
public:
    void fly() { cout << "Flying..." << endl; }
};
class Swimmer
{
public:
    void swim() { cout << "Swimming..." << endl; }
};
class Duck : public Flyer, public Swimmer
{
public:
    void sound() { cout << "Quack!" << endl; }
};

int main()
{
    Duck d;
    d.fly();
    d.swim();
    d.sound();

    return 0;
}