#include <bits/stdc++.h>
#define ll long long int
#define pa pair<int, ll>

using namespace std;
const int N = 1e5 + 5;
vector<pair<int, ll>> graph[N];
ll dis[N];
int parent[N];

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
        ll nodeCost = p.second;

        for (auto connectedNode : graph[node])
        {
            ll pathCost = nodeCost + connectedNode.second;
            int childNode = connectedNode.first;
            // Path Relaxing
            if (pathCost < dis[childNode])
            {
                dis[childNode] = pathCost;
                pq.push({childNode, dis[childNode]});
                parent[childNode] = node;
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
    for (int i = 1; i <= vertices; i++)
    {
        dis[i] = INT64_MAX;
        parent[i] = -1;
    }
    dijkstra(1);
    if (dis[vertices] == INT64_MAX)
        cout << -1 << endl;
    else
    {
        vector<int> v;
        while (vertices != -1)
        {
            v.push_back(vertices);
            vertices = parent[vertices];
        }
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i] << " ";
        cout << endl;
    }
}