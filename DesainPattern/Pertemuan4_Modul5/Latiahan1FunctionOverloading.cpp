#include <iostream>
using namespace std;

void attack()
{
    cout << "Basic attack!" << endl;
}

void attack(int power)
{
    cout << "Attack power : " << power << endl;
}

void attack(string skillName)
{
    cout << "Using skill: " << skillName << endl;
}

int main()
{

    attack();           // memanggil versi tanpa paramater
    attack(50);         // memanggil versi dengan parameter integer
    attack("Fireball"); // memanggil versi dengan parameter string

    // eksperimen

    attack(3.5); // memanggil versi dengan parameter integer dan integer
    return 0;
}