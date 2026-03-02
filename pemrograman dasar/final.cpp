#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ITEMS = 2; // 0: Small Potion (+10 HP), 1: Bomb (+8 dmg)
const int MAX_ENEMIES = 3;

void initGame(string &playerName, int &hpPlayer, int &hpEnemy, int inv[], string &enemyName);
void showStatus(const string &playerName, int hpPlayer, const string &enemyName, int hpEnemy);
int randBetween(int lo, int hi);
void clampHP(int &hp);
void applyDamage(int &hpTarget, int dmg);
void playerAttack(const string &pname, int &hpEnemy);
void enemyAttack(const string &ename, int &hpPlayer, bool defended);
void useItem(int inv[], int &hpPlayer, int &hpEnemy);
char readAction();

int main()
{
    srand((unsigned)time(0));

    string playerName, enemyName;
    int hpPlayer, hpEnemy;
    int inventory[MAX_ITEMS]; // array inventory (jumlah tiap item)

    initGame(playerName, hpPlayer, hpEnemy, inventory, enemyName);

    cout << "=== MONSTER DUEL (Ultra Simple) ===\n";
    cout << "Halo, " << playerName << "! Lawanmu: " << enemyName << ".\n";
    cout << "Aksi: 1) Attack  2) Defend  3) Use Item\n\n";

    // Gameloop
    while (hpPlayer > 0 && hpEnemy > 0)
    {
        showStatus(playerName, hpPlayer, enemyName, hpEnemy);

        char act = readAction(); // switch-case
        bool defended = false;

        if (act == '1')
        {
            playerAttack(playerName, hpEnemy);
        }
        else if (act == '2')
        {
            defended = true;
            cout << playerName << " bersiap bertahan!\n";
        }
        else if (act == '3')
        {
            useItem(inventory, hpPlayer, hpEnemy);
        }
        else
        {
            cout << "Pilihan tidak dikenali. Dianggap diam.\n";
        }

        // Giliran musuh jika masih hidup
        if (hpEnemy > 0)
        {
            enemyAttack(enemyName, hpPlayer, defended);
        }
    }

    // Hasil akhir
    if (hpPlayer <= 0 && hpEnemy <= 0)
    {
        cout << "\nHasil seri! Keduanya tumbang.\n";
    }
    else if (hpEnemy <= 0)
    { // menambahkan kondisi menang
        cout << "\nSelamat! " << playerName << " menang!\n";
        if (hpPlayer >= 20)
            cout << "Kategori: Jago\n";
        else if (hpPlayer >= 10)
            cout << "Kategori: Cukup\n";
        else
            cout << "Kategori: Pemula\n";
    }
    else
    {
        cout << "\nKamu kalah. " << enemyName << " menang.\n";
    }
    // Task(4): Tampilkan kategori hasil berdasarkan sisa HP pemain (Pemula/Cukup/Jago). (sudah)

    return 0;
}

void initGame(string &playerName, int &hpPlayer, int &hpEnemy, int inv[], string &enemyName)
{
    cout << "Masukkan nama pemain: ";
    getline(cin, playerName);

    string enemyList[MAX_ENEMIES] = {"Doctor", "Bat", "Monkey"};
    int hpValues[MAX_ENEMIES] = {35, 40, 45}; // HP bervariasi untuk musuh dan pemain
    enemyName = enemyList[rand() % MAX_ENEMIES];

    hpPlayer = hpValues[rand() % MAX_ENEMIES]; // membuat hp pemain bervariasi
    hpEnemy = hpValues[rand() % MAX_ENEMIES];  // membuat hp musuh bervariasi

    // Inventory awal
    inv[0] = 2; // 2x Small Potion (+10 HP)
    inv[1] = 1; // 1x Bomb (+8 dmg ke musuh)

    // Task(1): Variasikan HP awal musuh atau pemain (mis. berdasarkan nama musuh). (sudah dilakukan)
}

void showStatus(const string &playerName, int hpPlayer, const string &enemyName, int hpEnemy)
{
    cout << "\n[" << playerName << " HP:" << hpPlayer << "] vs ["
         << enemyName << " HP:" << hpEnemy << "]\n";
}

int randBetween(int lo, int hi)
{
    return lo + (rand() % (hi - lo + 1));
}

void clampHP(int &hp)
{
    if (hp < 0)
        hp = 0;
}

void applyDamage(int &hpTarget, int dmg)
{
    hpTarget -= dmg;
    clampHP(hpTarget);
}

void playerAttack(const string &pname, int &hpEnemy)
{
    int dmg = 6; // sederhana dan konsisten ->6
    int randCriticalHit = randBetween(1, 100);

    if (randCriticalHit <= 20) // 20% peluang
    {
        dmg += 3;
        cout << "Critical Hit! +3 damage.\n";
    }
    applyDamage(hpEnemy, dmg);

    // damage=6+3 =9;
    cout << pname << " menyerang! Damage " << dmg << ".\n";
    // Task(2): Tambahkan 20% peluang Critical +3 dmg. (sudah)
}

void enemyAttack(const string &ename, int &hpPlayer, bool defended)
{
    int base = randBetween(4, 7); // 7

    if (ename == "Monkey")
    {
        base += 1; // Monkey punya +1 dmg tetap
    }

    int dmg;
    if (defended)
    {
        dmg = base / 2;
        if (dmg == 0)
            dmg = 1; // minimal 1
    }
    else
    {
        dmg = base;
    }

    applyDamage(hpPlayer, dmg);

    if (defended)
    {
        cout << "Bertahan! Damage musuh tereduksi.\n";
    }
    cout << ename << " menyerang! Damage " << dmg << ".\n";

    // Task(3): Variasikan musuh tertentu punya +1 dmg tetap (mis. Monkey).  (sudah)
}

char readAction()
{
    cout << "Pilih aksi [1/2/3]: ";
    char c;
    cin >> c;
    switch (c)
    {
    case '1':
        return '1';
    case '2':
        return '2';
    case '3':
        return '3';
    default:
        return c;
    }
}

void useItem(int inv[], int &hpPlayer, int &hpEnemy)
{
    cout << "\n== ITEM ==\n";
    cout << "0) Small Potion (+10 HP)  sisa: " << inv[0] << "\n";
    cout << "1) Bomb (+8 dmg ke musuh) sisa: " << inv[1] << "\n";
    cout << "Pilih item (angka), selain 0/1 untuk batal: ";
    int idx;
    cin >> idx;

    if (idx == 0)
    {
        if (inv[0] > 0)
        {
            inv[0]--;
            hpPlayer += 10;
            cout << "Meminum Potion. HP +10.\n";
        }
        else
        {
            cout << "Potion habis.\n";
        }
    }
    else if (idx == 1)
    {
        if (inv[1] > 0)
        {
            inv[1]--;
            applyDamage(hpEnemy, 8);
            cout << "Melempar Bomb! Musuh -8 HP.\n";
        }
        else
        {
            cout << "Bomb habis.\n";
        }
    }
    else
    {
        cout << "Batal menggunakan item.\n";
    }
}
