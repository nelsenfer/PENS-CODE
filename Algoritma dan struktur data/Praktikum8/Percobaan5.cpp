#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> &graph, int start)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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
    cout << "BFS: ";
    bfs(graph, 0);
    return 0;
}