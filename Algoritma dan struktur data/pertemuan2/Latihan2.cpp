#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = nullptr;

void insertfront(int value)
{
    node *newnode = new node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

int main()
{
    insertfront(10);
    insertfront(20);
    insertfront(30);

    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}