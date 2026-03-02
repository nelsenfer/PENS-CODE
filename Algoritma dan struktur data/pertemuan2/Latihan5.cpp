#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

void insertFront(int value)
{
    Node *newnode = new Node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insertAfter(int key, int value)
{
    Node *temp = head;
    while (temp != nullptr && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return;
    }

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(int key, int value)
{
    if (head == nullptr)
        return;

    if (head->data == key)
    {
        insertFront(value);
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
        return;
    }

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;
}

void deleteByValue(int key)
{
    if (head == nullptr)
    {
        cout << "List kosong.\n";
        return;
    }
    // Jika head adalah key
    if (head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node dengan nilai " << key << " dihapus.\n";
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
        cout << "Nilai dengan nilai " << key << " tidak ditemukan.\n";
        return;
    }
    prev->next = curr->next;
    delete curr;
    cout << "Node dengan nilai " << key << " dihapus.\n";
}

int main()
{
    insertFront(20);
    insertFront(10);

    insertAfter(20, 30);
    insertBefore(20, 15);

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    deleteByValue(22);

    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}