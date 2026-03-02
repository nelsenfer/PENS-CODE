#include <iostream>
using namespace std;

int getStartLife()
{
    return 3;
}

int main()
{
    int life = getStartLife();
    cout << "Nyawa awal pemain: " << life << endl;
    return 0;
}