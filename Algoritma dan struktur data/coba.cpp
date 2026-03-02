#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

// Fungsi tambah di belakang
void insertBack(int value)
{
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
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Fungsi tampilkan list
void printList()
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int jumlah, nilai;

    cout << "Masukkan jumlah node: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan nilai node ke-" << i + 1 << ": ";
        cin >> nilai;
        insertBack(nilai);
    }

    cout << "\nIsi Linked List:\n";
    printList();

    return 0;
}