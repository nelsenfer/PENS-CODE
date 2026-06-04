#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> inventory;

    // tambah item
    inventory["Potion"] = 5;
    inventory["Sword"] = 1;
    inventory["Arrow"] = 20;

    // gunakan potion
    inventory["Potion"]--;

    // jika habis
    if (inventory["Potion"] == 0)
    {
        inventory.erase("Potion");
    }

    // tampilkan inventory
    cout << "Inventory Player:\n";
    for (auto item : inventory)
    {
        cout << item.first << " : " << item.second << endl;
    }

    return 0;
}