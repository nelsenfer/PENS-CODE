#include <iostream>
using namespace std;

int serangan(int *Target, int *pilihan)
{
    int damage = 25;
    *(Target + (*pilihan - 1)) -= damage;
    return *(Target + (*pilihan - 1));
}

int main()
{
    int enemyHPs[3] = {100, 80, 60};
    int pilihan;
    int *target = enemyHPs;

    cout << "=== Enemy Target Simulation ===" << endl;
    cout << "Musuh 1 HP: " << *target << endl;
    cout << "Musuh 2 HP: " << *(target + 1) << endl;
    cout << "Musuh 3 HP: " << *(target + 2) << endl;

    do
    {
        cout << "\n Pilih musuh yang ingin diserang (1-3): ";
        cin >> pilihan;
    } while (pilihan < 1 || pilihan > 3);

    serangan(target, &pilihan);
    cout << "Musuh " << pilihan << " terkena 25 damage!" << endl;

    cout << "\n=== Kondisi HP Musuh sekarang ===" << endl;
    cout << "Musuh 1 HP: " << *target << endl;
    cout << "Musuh 2 HP: " << *(target + 1) << endl;
    cout << "Musuh 3 HP: " << *(target + 2) << endl;

    return 0;
}