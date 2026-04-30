#include <iostream>
using namespace std;
// =====================
// STRUCT NODE
// =====================
struct Node
{
    char data;
    Node *left;
    Node *right;
};
// =====================
// CREATE NODE
// =====================
Node *createNode(char data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// =====================
// MAIN
// =====================
int main()
{
    // Membuat node
    Node *A = createNode('A');
    Node *B = createNode('B');
    Node *C = createNode('C');
    // Menghubungkan node
    A->left = B;
    A->right = C;
    // Output
    cout << "Root : " << A->data << endl;
    cout << "Left Child : " << A->left->data << endl;
    cout << "Right Child : " << A->right->data << endl;
    return 0;
}