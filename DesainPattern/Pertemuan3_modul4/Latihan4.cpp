#include <iostream>
using namespace std;

class Vehicle
{
public:
    void start() { cout << "Vehicle started!" << endl; }
};
class Car : public Vehicle
{
public:
    void honk() { cout << "Car honking!" << endl; }
};
class Motorcycle : public Vehicle
{
public:
    void rev() { cout << "Motorcycle revving!" << endl; }
};

int main()
{
    Car c;
    Motorcycle m;
    c.start();
    c.honk();
    c.start();
    m.rev();

    return 0;
}