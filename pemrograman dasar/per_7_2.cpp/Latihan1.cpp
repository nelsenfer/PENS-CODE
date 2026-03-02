#include <iostream>
using namespace std;

void ubahnilai(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] += 10;
    }
}

int main()
{
    int data[5] = {1, 2, 3, 4, 5};

    cout << "sebelum di pnggil fungsi unahnilai" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;

    ubahnilai(data, 5);

    cout << "sesudah di panggil fungsi ubahnilai" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}