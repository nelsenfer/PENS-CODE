#include <iostream>
using namespace std;
void tukar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// sorting dengan bubble sort
int main()
{
    int arr[4] = {8, 3, 5, 1};
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tukar(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}