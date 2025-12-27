#include <bits/stdc++.h>
#define pa pair<int, int>

using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> graph[N];
int dis[N];

class Compare
{
public:
    bool operator()(pa l, pa r)
    {
        return l.second > r.second;
    }
};
void addEdge(int v1, int v2, int cost)
{
    graph[v1].push_back({v2, cost});
    graph[v2].push_back({v1, cost}); // Undirected Graph
}

void dijkstra(int src)
{
    priority_queue<pa, vector<pa>, Compare> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pa p = pq.top();
        pq.pop();
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
                pq.push({childNode, dis[childNode]});
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