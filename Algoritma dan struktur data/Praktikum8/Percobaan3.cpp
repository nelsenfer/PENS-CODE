#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v); // hanya satu arah
}
int main()
{
    int n = 4;
    vector<vector<int>> graph(n);
    addEdge(graph, 0, 1); // A → B
    addEdge(graph, 1, 2); // B → C
    addEdge(graph, 0, 3); // A → D
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j : graph[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}