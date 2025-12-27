#include <bits/stdc++.h>
#define ll long long int

using namespace std;
class Edge
{
public:
    int v1;
    int v2;
    ll cost;
    Edge(int v1, int v2, ll cost) : v1(v1), v2(v2), cost(cost)
    {
    }
};
const int N = 1e3 + 5;
vector<Edge> edgeList;
ll dis[N];

void addEdge(int v1, int v2, ll cost)
{
    edgeList.push_back(Edge(v1, v2, cost));
}

void bellmanford()
{
    for (Edge ch : edgeList)
    {
        int p = ch.v1;
        int child = ch.v2;
        ll pathCost = ch.cost;
        if (dis[p] < 1000000000000000 && dis[p] + pathCost < dis[child])
            dis[child] = dis[p] + pathCost;
    }
}

bool negative_cycle_check()
{
    for (Edge ch : edgeList)
    {
        int p = ch.v1;
        int child = ch.v2;
        ll pathCost = ch.cost;
        if (dis[p] < 1000000000000000 && dis[p] + pathCost < dis[child])
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
        int v1, v2;
        ll cost;
        cin >> v1 >> v2;
        cin >> cost;
        addEdge(v1, v2, cost);
    }
    for (int i = 0; i <= vertices; i++)
        dis[i] = 1000000000000000;
    int src, testCase;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i < vertices; i++)
        bellmanford();
    cin >> testCase;
    vector<int> v;
    while (testCase--)
    {
        int destination;
        cin >> destination;
        v.push_back(destination);
    }
    if (negative_cycle_check())
        cout << "Negative Cycle Detected\n";
    else
    {
        for (int x : v)
        {
            if (dis[x] < 1000000000000000)
                cout << dis[x] << endl;
            else
                cout << "Not Possible\n";
        }
    }

    return 0;
}
