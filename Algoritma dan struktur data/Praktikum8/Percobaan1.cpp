#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 4;
    vector<vector<int>> graph(n);
    // edge (undirected)
    graph[0] = {1, 3}; // A
    graph[1] = {0, 2}; // B
    graph[2] = {1};    // C
    graph[3] = {0};    // D
    // tampilkan graph
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j : graph[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}