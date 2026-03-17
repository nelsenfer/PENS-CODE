#include <iostream>
#include <vector>
#include <string>

using namespace std;

void tampilkanMenu()
{
    cout << "\n--- Enemy Manager ---" << endl;
    cout << "1. Tambah Enemy" << endl;
    cout << "2. Tampilkan Enemy" << endl;
    cout << "3. Enemy Dikalahkan" << endl;
    cout << "4. Jumlah Enemy" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
}

void tambahEnemy(vector<string> &daftar)
{
    string nama;
    cout << "Masukkan nama enemy: ";
    getline(cin, nama);
    daftar.push_back(nama);
    cout << "Enemy berhasil ditambahkan." << endl;
}

void tampilkanDaftar(const vector<string> &daftar)
{
    if (daftar.empty())
    {
        cout << "\nDaftar Enemy: \n(kosong)" << endl;
        return;
    }
    cout << "\nDaftar Enemy:" << endl;
    for (int i = 0; i < daftar.size(); i++)
    {
        cout << i + 1 << ". " << daftar[i] << endl;
    }
}

void hapusEnemy(vector<string> &daftar)
{
    if (daftar.empty())
    {
        cout << "Tidak ada enemy untuk dikalahkan." << endl;
        return;
    }

    // Menampilkan daftar terlebih dahulu agar user tahu nomor mana yang mau dihapus
    tampilkanDaftar(daftar);

    int nomor;
    cout << "Pilih enemy yang dikalahkan: ";
    cin >> nomor;
    cin.ignore(); // Membersihkan buffer setelah input angka

    // Validasi nomor (karena user melihat angka mulai dari 1, sedangkan index mulai dari 0)
    if (nomor > 0 && nomor <= daftar.size())
    {
        string namaTerhapus = daftar[nomor - 1];
        daftar.erase(daftar.begin() + (nomor - 1));
        cout << "Enemy " << namaTerhapus << " dikalahkan." << endl;
    }
    else
    {
        cout << "Nomor tidak valid!" << endl;
    }
}

int main()
{
    vector<string> enemies;
    int pilihan;

    do
    {
        tampilkanMenu();
        if (!(cin >> pilihan))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            tambahEnemy(enemies);
            break;
        case 2:
            tampilkanDaftar(enemies);
            break;
        case 3:
            hapusEnemy(enemies);
            break;
        case 4:
            cout << "Jumlah enemy: " << enemies.size() << endl;
            break;
        case 5:
            cout << "Keluar..." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 5);

    return 0;
}