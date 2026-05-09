#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int main()
{
    int n = 5;
    vector<vector<int>> graph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j : graph[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}