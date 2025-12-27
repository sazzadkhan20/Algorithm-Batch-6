#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> graph[N];
int dis[N];

void addEdge(int v1, int v2, int cost)
{
    graph[v1].push_back({v2, cost});
    graph[v2].push_back({v1, cost}); // Undirected Graph
}

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int nodeCost = p.second;

        for (auto connectedNode : graph[node])
        {
            int pathCost = nodeCost + connectedNode.second;
            int childNode = connectedNode.first;
            // Path Relaxing
            if (pathCost < dis[childNode])
            {
                dis[childNode] = pathCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    while (edges--)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        addEdge(v1, v2, cost);
    }
    int src;
    cin >> src;
    for (int i = 0; i < vertices; i++)
        dis[i] = INT_MAX;
    dijkstra(src);
    for (int i = 0; i < vertices; i++)
        cout << dis[i] << " ";
}