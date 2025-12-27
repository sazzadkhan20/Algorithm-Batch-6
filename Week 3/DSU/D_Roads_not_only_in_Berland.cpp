#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
int parent[N];
int dsuSize[N];

void DSU_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        dsuSize[i] = 1;
    }
}

// Find Optimization --O(logN)
int DSU_find(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = DSU_find(parent[node]);
}

void DSU_union(int leader1, int leader2)
{
    if (dsuSize[leader1] < dsuSize[leader2])
        swap(leader1, leader2);
    parent[leader2] = leader1;
    dsuSize[leader1] += dsuSize[leader2];
}

int main()
{
    int vertices;
    cin >> vertices;
    vector<pair<int, int>> edgeList;
    for (int i = 1; i < vertices; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        edgeList.push_back({v1, v2});
    }
    DSU_initialize(vertices);
    vector<int> closeRoads;
    vector<int> openRoads;
    for (auto edge : edgeList)
    {
        int leader1 = DSU_find(edge.first);
        int leader2 = DSU_find(edge.second);
        if (leader1 != leader2)
        {
            DSU_union(leader1, leader2);
        }
        else
        {
            closeRoads.push_back(edge.first);
            closeRoads.push_back(edge.second);
        }
    }
    for (int i = 1; i <= vertices; i++)
    {
        if (parent[i] == -1)
            openRoads.push_back(i);
    }
    cout << openRoads.size() - 1 << endl;
    if (openRoads.size() > 1)
    {
        for (int i = 0; i < openRoads.size(); i += 2)
        {
            cout << closeRoads[i] << " " << closeRoads[i + 1] << " ";
            cout << openRoads[i] << " " << openRoads[i + 1] << endl;
        }
    }
}