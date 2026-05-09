#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(graph, neighbor, visited);
        }
    }
}
int main()
{
    int n = 5;
    vector<vector<int>> graph(n);
    graph[0] = {1, 2}; // A
    graph[1] = {3};    // B
    graph[2] = {4};    // C
    graph[3] = {};     // D
    graph[4] = {};     // E
    vector<bool> visited(n, false);
    cout << "DFS: ";
    dfs(graph, 0, visited);
    return 0;
}