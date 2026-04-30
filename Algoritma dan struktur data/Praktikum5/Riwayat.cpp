#include <iostream>
using namespace std;
#define MAX 10

class Stack
{
private:
    int top;
    string command[MAX];

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(string cmd)
    {
        if (top == MAX - 1)
        {
            cout << "Command penuh\n";
            return;
        }
        top++;
        command[top] = cmd;
    }
    void undo()
    {
        if (isEmpty())
        {
            cout << "Tidak ada menu untuk kembali\n";
            return;
        }
        cout << "Keluar dari: " << command[top] << endl;
        top--;
    }
    void Riwayat()
    {
        cout << "Riwayat Menu:\n";
        for (int i = top; i >= 0; i--)
        {
            cout << command[i] << endl;
        }
    }
};

int main()
{
    Stack riwayat;
    int pilihan;

    do
    {
        cout << "\n=== Menu Navigation (Stack) ===";
        cout << "\n 1. Buka Menu\n 2. Kembali\n 3. Tampilkan Riwayat\n 4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
        {
            cout << "masukan nama menu: ";
            string menu;
            getline(cin, menu);
            riwayat.push(menu);
            break;
        }
        case 2:
            riwayat.undo();
            break;

        case 3:
            riwayat.Riwayat();
            break;

        case 4:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 4);

    return 0;
}