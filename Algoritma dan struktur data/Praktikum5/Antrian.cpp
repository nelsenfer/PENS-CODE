#include <iostream>
using namespace std;
#define MAX 5

class CircularQueue
{
private:
    int front;
    int rear;
    string data[MAX];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(string value)
    {
        if (isFull())
        {
            cout << "Antrian Penuh\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        data[rear] = value;
        cout << "player masuk antrian Quest\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrian Kosong!\n";
            return;
        }

        cout << "Payer " << data[front] << "Mengambil quest" << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Antrian Kosong\n";
            return;
        }

        int i = front;
        cout << "Daftar Antrian:\n";

        while (true)
        {
            cout << data[i] << endl;
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
    }
};

int main()
{
    CircularQueue q;
    int pilihan;

    do
    {
        cout << "\n=== Antrian Quest NPC ===";
        cout << "\n 1. Ambil nomer antrian \n 2. Panggil antrian \n 3. Tampilkan Antrian\n 4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
        {
            string value;
            cout << "Masukkan nama untuk antrian: ";
            getline(cin, value);
            q.enqueue(value);
            break;
        }
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}