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
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        tukar(arr[i], arr[minIndex]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}