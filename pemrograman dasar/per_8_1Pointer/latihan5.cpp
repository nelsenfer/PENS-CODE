#include <iostream>
using namespace std;

int main()
{
    int score[3] = {10, 20, 30};
    int *p = score;

    for (int i = 0; i < 3; i++)
    {
        cout << "Element ke-" << i << " : " << *(p + i) << endl;
    }
    return 0;
}