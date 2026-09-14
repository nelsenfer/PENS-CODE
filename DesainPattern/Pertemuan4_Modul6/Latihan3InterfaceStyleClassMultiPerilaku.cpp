#include <iostream>
using namespace std;

// Interface-style class
class IUpdateable
{
public:
    virtual void Update() = 0;
    virtual ~IUpdateable() {} // Tambahan virtual destructor yang aman
};

class IDrawable
{
public:
    virtual void Draw() = 0;
    virtual ~IDrawable() {}
};

class Player : public IUpdateable, public IDrawable
{
public:
    void Update() override { cout << "Player moves forward.\n"; }
    void Draw() override { cout << "Draw Player sprite.\n"; }
};

class Enemy : public IUpdateable, public IDrawable
{
public:
    void Update() override { cout << "Enemy patrols area.\n"; }
    void Draw() override { cout << "Draw Enemy model.\n"; }
};

class NPC : public IUpdateable, public IDrawable
{
public:
    void Update() override { cout << "NPC interacts with player.\n"; }
    void Draw() override { cout << "Draw NPC character.\n"; }
};

// Fungsi terpisah untuk GameLoop
void GameLoop(IUpdateable *up[], IDrawable *dr[], int size)
{
    cout << "=== UPDATE ===\n";
    for (int i = 0; i < size; i++)
    {
        up[i]->Update();
    }

    cout << "\n=== DRAW ===\n";
    for (int i = 0; i < size; i++)
    {
        dr[i]->Draw();
    }
}

int main()
{
    // Objek dibuat sekali dan pointernya dibagikan
    Player *p = new Player();
    Enemy *e = new Enemy();
    NPC *n = new NPC();

    IUpdateable *up[3] = {p, e, n};
    IDrawable *dr[3] = {p, e, n};

    // Memanggil sistem GameLoop
    GameLoop(up, dr, 3);

    // Membersihkan memori
    delete p;
    delete e;
    delete n;

    return 0;
}