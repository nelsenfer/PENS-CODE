#include <iostream>
#include <string>
using namespace std;

string AmbilKataTerakhir(const string &kalimat)
{
    size_t pos = kalimat.find_last_of(' ');
    return kalimat.substr(pos + 1);
}

int main()
{
    int HFokal = 0;
    string quest;
    cout << "Masukkan deskripsi quest: ";
    getline(cin, quest);

    string KataTerakhir = AmbilKataTerakhir(quest);

    for (int i = 0; i < quest.length(); i++)
    {
        if (quest[i] == 'a' || quest[i] == 'e' || quest[i] == 'i' || quest[i] == 'o' || quest[i] == 'u' ||
            quest[i] == 'A' || quest[i] == 'E' || quest[i] == 'I' || quest[i] == 'O' || quest[i] == 'U')
        {
            HFokal++;
        }
    }

    cout << "Jumlah karakter: " << quest.length() << endl;
    cout << "Kata pertama: " << quest.substr(0, 4) << endl; // "Find"
    cout << "Kata terakhir: " << KataTerakhir << endl;
    cout << "Jumlah huruf vokal: " << HFokal << endl;

    quest.append(" - Urgent!");
    cout << "Update quest: " << quest << endl;
    return 0;
}
