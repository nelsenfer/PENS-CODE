#include <iostream>
using namespace std;
#define MAX 100

int fibonaci[MAX];

int main()
{
    int i;

    fibonaci[1] = 1;
    fibonaci[2] = 1;

    for (i = 3; i <= 10; i++)
    {
        fibonaci[i] = fibonaci[i - 1] + fibonaci[i - 2];
    }

    cout << "Deret Fibonaci: ";
    for (i = 1; i <= 10; i++)
    {
        cout << fibonaci[i] << " ";
    }
}
