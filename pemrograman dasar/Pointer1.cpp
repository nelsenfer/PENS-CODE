#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *a = new int[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cout << "The integers you entered are:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }

    delete[] a;

    return 0;
}