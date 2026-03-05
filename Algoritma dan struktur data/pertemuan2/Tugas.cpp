#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *head = nullptr;

void SpawnAnemy()
{
    string value;
    cout << "Masukkan nama enemy: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void InsertAnemyBefore()
{
    if (head == nullptr)
    {
        cout << "List kosong.\n";
        return;
    }

    string key, value;
    cout << "Masukkan target (sebelum nama ini): ";
    cin >> key;
    cout << "Masukkan nama enemy baru: ";
    cin >> value;

    if (head->data == key)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "Target tidak ditemukan.\n";
        return;
    }

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;
    cout << "Enemy baru" << value << " berhasil disisipkan.\n";
}

void killAnemy()
{
    if (head == nullptr)
    {
        cout << "List kosong.\n";
        return;
    }

    string key;
    cout << "Masukkan nama enemy yang ingin dihapus: ";
    cin >> key;

    if (head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Enemy dihapus.\n";
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != nullptr && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "Enemy tidak ditemukan.\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Enemy dihapus.\n";
}

void ShowAnemy()
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void CountAnemy()
{
    Node *temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    cout << "Jumlah Enemy: " << count << endl;
}

int main()
{
    int pilihan;

    do
    {
        cout << "\n1. Spawn enemy\n";
        cout << "2. Insert BEFORE target\n";
        cout << "3. Kill enemy\n";
        cout << "4. Show enemy list\n";
        cout << "5. Count enemies\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka!\n";
            pilihan = -1;
            continue;
        }

        switch (pilihan)
        {
        case 1:
            SpawnAnemy();
            break;
        case 2:
            InsertAnemyBefore();
            break;
        case 3:
            killAnemy();
            break;
        case 4:
            ShowAnemy();
            break;
        case 5:
            CountAnemy();
            break;
        case 0:
            cout << "Keluar program...\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 0);

    return 0;
}