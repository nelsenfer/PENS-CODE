#include <iostream>
using namespace std;

struct Node
// blok ini tugasnya membuat struktur data untuk menyimpan nilai angka sekaligus penunjuk ke cabang anak kiri dan kanan.
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
// blok ini tugasnya mengalokasikan memori untuk node baru, mengisi angkanya, dan mengosongkan cabang anaknya.
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInorder(Node *root)
// blok ini tugasnya mengeksekusi penelusuran berurutan mulai dari cabang kiri terdalam, naik ke induk, lalu ke cabang kanan.
{
    if (root == NULL)
    // blok ini tugasnya menghentikan proses baca dan mundur jika node yang dicek ternyata kosong.
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
// blok ini tugasnya mengeksekusi program utama dengan merangkai tiga node menjadi satu tree dan mencetaknya.
{
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);

    cout << "Hasil Inorder Traversal: ";
    printInorder(root);

    return 0;
}