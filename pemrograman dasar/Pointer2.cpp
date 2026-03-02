#include <iostream>
using namespace std;

int main()
{
    int *p2 = new int[3]; // menunjukan ke array dengan 3 elemen

    *p2 = 5; // p2 [0] = 5

    p2[1] = 10; // elemen kedua diatur ke 10
    p2[2] = 15; // elemen ketiga diatur ke 15
    return 0;
}