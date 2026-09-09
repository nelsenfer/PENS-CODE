#include <iostream>
using namespace std;

#include <iostream>
#include <string>
using namespace std;
class Character
{
private:
    string name;

public:
    Character(string n) { name = n; }
    string getName() { return name; }
};
class Player : public Character
{
private:
    int score;

public:
    Player(string n, int s) : Character(n) { score = s; }
    void showInfo()
    {
        cout << "Player: " << getName() << " | Score: " << score << endl;
    }
};

int main()
{
    Player player1("Alice", 100);
    player1.showInfo();

    return 0;
}