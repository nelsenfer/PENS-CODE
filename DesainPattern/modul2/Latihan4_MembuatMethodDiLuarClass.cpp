#include <iostream>
using namespace std;

// inisiasi class
class GameCharacter
{
public:
    string name;

    // deklarasi method
    void speak();
};

void GameCharacter::speak()
{
    cout << "Hello," << name << "," << endl;
    cout << "Selamat Datang di Mata Kuliah Desain Pattern" << endl;
}

int main()
{

    // inisiasi objek
    GameCharacter player1;

    // input nama dengan objek
    player1.name = "nelsen";

    // memanggil method dengan objek
    player1.speak();

    return 0;
}