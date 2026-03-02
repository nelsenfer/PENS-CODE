#include <iostream>
using namespace std;

int main()
{
    string username, password;

    cout << "Masukkan username: ";
    cin >> username;

    if (username == "jhon")
    {
        cout << "Masukkan password: ";
        cin >> password;

        if (password == "1sampai0")
        {
            cout << "\nSelamat datang di sistem!" << endl;
        }
        else
        {
            cout << "\nPassword salah!. anda gagal  masuk sistem" << endl;
        }
    }
    else
    {
        cout << "\nUsername tidak ditemukan!" << endl;
    }

    cout << "\nProgram Berakhir." << endl;

    return 0;
}