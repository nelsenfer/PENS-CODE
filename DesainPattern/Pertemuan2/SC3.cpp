#include <iostream>
using namespace std;

class Character
{
public:
    string name;
    int level;
    int experience;

    // Konstruktor mengatur default value level dan experience
    Character(string charName)
    {
        name = charName;
        level = 1;
        experience = 0;
    }

    void levelUp()
    {
        level++;
        experience = 0; // Mengatur ulang EXP
        cout << "*** LEVEL UP! ***\nSelamat " << name << ", kamu naik ke level " << level << "!\n"
             << endl;
    }

    void gainExperience(int expGained)
    {
        cout << name << " mendapatkan " << expGained << " EXP." << endl;
        experience += expGained;

        // Memeriksa kalkulasi EXP
        if (experience >= 100)
        {
            levelUp();
        }
        else
        {
            cout << "EXP saat ini: " << experience << "/100\n"
                 << endl;
        }
    }
};

int main()
{
    Character mc("Nelss");

    // Simulasi mendapatkan EXP secara bertahap
    mc.gainExperience(40);
    mc.gainExperience(50);

    // Poin ini akan menembus batas 100 EXP dan memicu level up
    mc.gainExperience(30);

    return 0;
}