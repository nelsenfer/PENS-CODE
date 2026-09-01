#include <iostream>
using namespace std;

class Player
{
public:
    int health;
    string name;
    double score;
};

int main()
{
    // membuat object dari class Player
    Player player1;
    // mengisi nilai atribut dari object player1
    player1.health = 100;
    player1.name = "Nelsen";
    player1.score = 99.98;
    // menampilkan nilai atribut dari object player1
    cout << "Nama Player: " << player1.name << endl;
    cout << "Health Player: " << player1.health << endl;
    cout << "Score Player: " << player1.score << endl;
    cout << "\n";

    // membuat object dari class Player 2
    Player player2;
    // mengisi nilai atribut dari object player2
    player2.health = 80;
    player2.name = "Rizky";
    player2.score = 88.88;
    // menampilkan nilai atribut dari object player2
    cout << "Nama Player: " << player2.name << endl;
    cout << "Health Player: " << player2.health << endl;
    cout << "Score Player: " << player2.score << endl;
    cout << "\n";

    // mengubah status pemain ketika terkena damage
    player1.health -= 20;
    player1.score -= 20.0;

    player2.health -= 30;
    player2.score -= 30.0;

    // menampilkan informasi player setelah terkena damage
    cout << "Health Player1 setelah di serang: " << player1.health << endl;
    cout << "Score Player1 setelah di serang: " << player1.score << endl;
    cout << "Health Player2 setelah di serang: " << player2.health << endl;
    cout << "score Player2 setelah di serang: " << player2.score << endl;
    return 0;
}