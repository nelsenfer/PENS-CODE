#include <iostream>
using namespace std;
#define MAX 20

int *fibo;

int main()
{
    int i;
    fibo = new int[MAX];
    fibo[1] = 1;
    fibo[2] = 1;

    for (i = 3; i <= MAX; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    cout << "bilangan fibonaci pertama adalah: ";
    for (i = 1; i <= MAX; i++)
    {
        cout << fibo[i] << " ";
    }

    return 0;
}