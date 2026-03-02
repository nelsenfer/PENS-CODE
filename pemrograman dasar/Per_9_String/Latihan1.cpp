#include <iostream>
#include <string>
using namespace std;

int main()
{
    string gameTitle = "Legend of Code";
    string developer = "PENS GameLab";
    string version = "v1.2.0";
    string gendre = "Adventure RPG";
    string intro = "Selamat datang di " + gameTitle + " (" + version + ")";
    string fullintro = intro;

    cout << "=====================================\n";
    cout << fullintro << endl;
    cout << intro << endl;
    cout << "Dikembangkan oleh: " << developer << endl;
    cout << "Genre: " << gendre << endl;
    cout << "=====================================\n";

    return 0;
}