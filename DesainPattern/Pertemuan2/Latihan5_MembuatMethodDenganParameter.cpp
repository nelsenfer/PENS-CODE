#include <iostream>
using namespace std;

// deklarasi class
class GameCharacter
{
public:
    void result(string name, int health);
};

// deklarasi metod result di luar class
void GameCharacter::result(string username, int health_player)
{
    health_player -= 20;
    cout << "Nama Player: " << username << endl;
    cout << "Health Player: " << health_player << endl;
}

int main()
{
    // inisialisasi objek
    GameCharacter player1;

    // memanggil method result dengan parameter
    player1.result("Nelsen", 90);

    return 0;
}