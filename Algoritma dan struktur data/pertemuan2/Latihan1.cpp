#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int main()
{
    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    node *temp = node1;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

    return 0;
}