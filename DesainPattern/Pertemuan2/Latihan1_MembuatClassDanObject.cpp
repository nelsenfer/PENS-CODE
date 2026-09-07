#include <iostream>
using namespace std;

class Player
{
public:
    int health;
    string name;
};

int main()
{
    // Membuat object dari class Player
    Player player1;

    // mengisi nilai atribut dari object player1
    player1.health = 100;
    player1.name = "Nelsen";

    // menampilkan nilai atribut dari object player1
    cout << "Nama Player: " << player1.name << endl;
    cout << "Health Player: " << player1.health << endl;

    // mengubah status health dari object player1
    player1.health -= 20;

    // menampilkan nilai atribut dari object player1 setelah diubah
    cout << "Nama Player: " << player1.name << endl;
    return 0;
}