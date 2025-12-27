#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int node1, node2, weight;
    Edge(int n1, int n2, int w)
    {
        node1 = n1;
        node2 = n2;
        weight = w;
    }
};
const int N = 1005;
int dis[N];
vector<Edge> edgeList;

void bellman_ford()
{
    for (auto edge : edgeList)
    {
        int u = edge.node1;
        int v = edge.node2;
        int c = edge.weight;
        // Path Relaxation
        if (dis[u] != INT_MAX && dis[u] + c < dis[v])
            dis[v] = dis[u] + c;
    }
}

bool negetive_cycle_detect()
{
    for (auto edge : edgeList)
    {
        int u = edge.node1;
        int v = edge.node2;
        int c = edge.weight;
        // Path Relaxation
        if (dis[u] != INT_MAX && dis[u] + c < dis[v])
            return true;
    }
    return false;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    while (edges--)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        edgeList.push_back(Edge(n1, n2, w));
        edgeList.push_back(Edge(n2, n1, w)); // Undirected
    }
    for (int i = 0; i <= vertices; i++)
        dis[i] = INT_MAX;
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i < vertices; i++)
        bellman_ford();
    if (negetive_cycle_detect())
        cout << "Negetive Cycle Detect,No Answer\n";
    else
    {
        for (int i = 0; i < vertices; i++)
            cout << dis[i] << " ";
    }
}