#include <iostream>
using namespace std;

class GameCharacter
{
public:
    string name;
    int health;
    double score;

    // inisiasi constructor dengan parameter
    GameCharacter(string username, int health_player, double score_player)
    {
        name = username;
        health_player = health;
        score = score_player;
    }
};

int main()
{

    // inisialisasi objek dengan parameter
    GameCharacter player1("Nelsen", 90, 100.0);

    // inisalisasi objek dengan parameter2
    GameCharacter player2("Alpha", 80, 90.0);

    // memanggil informasi 1 dengan constructor
    cout << player1.name << player1.health << player1.score << endl;
    cout << player2.name << player2.health << player2.score << endl;

    return 0;
}