#include <iostream>
using namespace std;

class Charecter
{
protected:
    string name;
    int health;

private:
    int secretCode;

public:
    Charecter(string n, int h)
    {
        name = n;
        health = h;
        secretCode = 999;
    }

    void showStatus()
    {
        cout << name << " | Health: " << health << endl;
    }

    void revealSecret()
    {
        cout << "Secret Code: " << secretCode << endl;
    };
};

class player : public Charecter
{
public:
    player(string n, int h) : Charecter(n, h) {}
    void heal(int amount)
    {
        health += amount;
    }
};

int main()
{
    player p("Hero", 100);
    p.showStatus(); // Output: Hero | Health: 100
    p.heal(20);
    p.showStatus();   // Output: Hero | Health: 120
    p.revealSecret(); // Output: Secret Code: 999
    return 0;
}