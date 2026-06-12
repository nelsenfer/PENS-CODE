#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// =======================
// GLOBAL STRUCT / DATA
// =======================
vector<string> inventory;
unordered_map<string, int> enemyHP;

// =======================
// FUNCTION DECLARATION
// =======================
void inputInventory();
void inputEnemy();
void showInventory();
void showEnemy();
vector<pair<string, int>> sortEnemyByHP();
string findLowestHPEnemy(vector<pair<string, int>> &enemyList);

// =======================
// MAIN
// =======================
int main()
{
    inputInventory();
    inputEnemy();

    cout << "=== INVENTORY PLAYER ===\n";
    showInventory();

    vector<pair<string, int>> sortedEnemy = sortEnemyByHP();

    cout << "\n=== DAFTAR ENEMY (SETELAH SORTING) ===\n";
    for (int i = 0; i < sortedEnemy.size(); i++)
    {
        cout << i + 1 << ". " << sortedEnemy[i].first << "\tHP: " << sortedEnemy[i].second << endl;
    }

    string target = findLowestHPEnemy(sortedEnemy);
    cout << "\n=== ENEMY DENGAN HP TERKECIL ===\n";
    cout << target << "\nHP: " << enemyHP[target] << endl;

    return 0;
}

// =======================
// IMPLEMENTATION
// =======================

void inputInventory()
{
    inventory.push_back("Sword");
    inventory.push_back("Potion");
    inventory.push_back("Shield");
    inventory.push_back("Bow");
    inventory.push_back("Helmet");
}

void inputEnemy()
{
    enemyHP["Goblin"] = 50;
    enemyHP["Orc"] = 120;
    enemyHP["Dragon"] = 300;
    enemyHP["Skeleton"] = 80;
    enemyHP["Troll"] = 150;
}

void showInventory()
{
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << i + 1 << ". " << inventory[i] << endl;
    }
}

void showEnemy()
{
    int i = 1;
    for (auto e : enemyHP)
    {
        cout << i << ". " << e.first << "\tHP: " << e.second << endl;
        i++;
    }
}

vector<pair<string, int>> sortEnemyByHP()
{
    vector<pair<string, int>> temp;

    for (auto e : enemyHP)
    {
        temp.push_back(e);
    }

    sort(temp.begin(), temp.end(), [](pair<string, int> &a, pair<string, int> &b)
         { return a.second < b.second; });

    return temp;
}

string findLowestHPEnemy(vector<pair<string, int>> &enemyList)
{
    if (enemyList.empty())
        return "";

    // int minHP = enemyList[0].second;
    return enemyList[0].first;

    // int minIndex = 0;

    // for (int i = 0; i < enemyList.size(); i++)
    // {
    //     if (enemyList[i].second < minHP)
    //     {
    //         minHP = enemyList[i].second;
    //         minIndex = i;
    //     }
    // }

    // return enemyList[minIndex].first;
}