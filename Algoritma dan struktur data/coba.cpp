#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
// blok ini tugasnya menjalankan eksekusi utama program simulasi vector.
{
    vector<string> item;

    item.push_back("Sword");
    item.push_back("Shield");
    item.push_back("Potion");
    item.push_back("Knife");

    cout << "nilai indek 2 adalah" << item[2] << "\n\n";

    cout << "Jumlah item di inventory: " << item.size() << "\n";
    cout << "Item terdepan: " << item.front() << "\n";
    cout << "Item paling belakang: " << item.back() << "\n\n";

    item.pop_back();

    cout << "Daftar isi inventory setelah pop_back:\n";
    for (int i = 0; i < item.size(); i++)
    // blok ini tugasnya melakukan perulangan untuk mencetak setiap indeks data vector ke layar.
    {
        cout << "- " << item[i] << "\n";
    }

    return 0;
}