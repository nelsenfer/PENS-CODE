#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ns[2] = {20, 40};
    int *pns = ns;

    cout << ns << endl;
    cout << &ns[0] << endl;
    cout << pns << endl;
    cout << *pns << endl;
    cout << *(pns + 1) << endl;
    // * --- >> nilai
}