#include <iostream>
#include <string>
using namespace std;

int main()
{
    string playerName, npcName, dialog;

    cout << "Masukkan nama pemain: ";
    getline(cin, playerName);
    cout << "Masukkan nama NPC: ";
    getline(cin, npcName);
    cout << "Masukkan dialog NPC: ";
    getline(cin, dialog);

    playerName[0] = toupper(playerName[0]);
    npcName[0] = toupper(npcName[0]);

    cout << "\n=== SCENE 1 ===\n";
    cout << npcName << ": " << dialog << endl;
    cout << playerName << ": (menjawab dengan senyum)\n";
    cout << "\"Suasana di sekitar menjadi tegang\"" << endl;
    return 0;
}