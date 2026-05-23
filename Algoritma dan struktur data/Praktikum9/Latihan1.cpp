#include <iostream>
using namespace std;
void tukar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// sorting dengan selection sort
int main()
{
    int arr[4] = {8, 3, 5, 1};
    if (arr[0] > arr[1])
        tukar(arr[0], arr[1]);
    if (arr[0] > arr[2])
        tukar(arr[0], arr[2]);
    if (arr[0] > arr[3])
        tukar(arr[0], arr[3]);
    if (arr[1] > arr[2])
        tukar(arr[1], arr[2]);
    if (arr[1] > arr[3])
        tukar(arr[1], arr[3]);
    if (arr[2] > arr[3])
        tukar(arr[2], arr[3]);
    for (int i = 0; i < 4; i++)
        cout << arr[i] << " ";
    return 0;
}
