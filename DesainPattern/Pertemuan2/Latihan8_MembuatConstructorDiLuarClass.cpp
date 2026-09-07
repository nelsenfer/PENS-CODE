#include <iostream>
using namespace std;

class GameCharacter
{
public:
    string name;
    int health;
    double score;

    // memanggil constructor di luar class
    GameCharacter(string username, int health_player, double score_player);
};

// inisialisasi constructor di luar class
GameCharacter::GameCharacter(string username, int health_player, double score_player)
{
    name = username;
    health = health_player;
    score = score_player;
}

int main()
{
    // inisialisasi objek dengan parameter
    GameCharacter player1("Nelsen", 90, 100.0);
    // inisialisasi objek dengan parameter2
    GameCharacter player2("Alpha", 70, 70.0);

    // memanggil informasi 1 dengan constructor
    cout << player1.name << player1.health << player1.score << endl;
    cout << player2.name << player2.health << player2.score << endl;

    return 0;
}