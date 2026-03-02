#include <iostream>
using namespace std;

int takeDamage(int *HP)
{
    if (*HP >= 100)
    {
        *HP -= 25;
    }
    else
    {
        *HP -= 50;
    }
    return *HP;
}

int Seranngan(int *serangan, int *HP)
{
    *HP -= *serangan;
    if (*HP < 0)
    {
        *HP = 0;
    }
    return *HP;
}

int main()
{
    int health = 100, serangan = 0;
    string izin;

    cout << "Apakah Anda ingin menggunakan program auto? (Y/N): ";
    cin >> izin;

    if (izin == "Y" || izin == "y")
    {
        cout << "HP Awal: " << health << endl;
        takeDamage(&health);
        cout << "HP Setelah Serangan 1: " << health << endl;
        takeDamage(&health);
        cout << "HP Setelah Serangan 2: " << health << endl;
    }
    else
    {
        int i = 1;
        while (health <= 100)
        {
            cout << "\nMasukkan jumlah serangan: ";
            cin >> serangan;
            cout << "HP Awal: " << health << endl;
            Seranngan(&serangan, &health);
            cout << "HP Setelah Serangan ke " << i << ": " << health << endl;
            if (health <= 0)
            {
                cout << "Karakter telah mati." << endl;
                break;
            }
            i++;
        }
    }
}