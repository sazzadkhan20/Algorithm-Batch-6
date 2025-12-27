#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int parent[N];
int dsuSize[N];

void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        dsuSize[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = dsu_find(parent[node]);
}

void dsu_union(int leader1, int leader2)
{
    if (dsuSize[leader1] < dsuSize[leader2])
        swap(leader1, leader2);
    dsuSize[leader1] += dsuSize[leader2];
    parent[leader2] = leader1;
}
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    dsu_initialize(vertices);
    int numberOfCycles = 0;
    while (edges--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        int leader1 = dsu_find(v1);
        int leader2 = dsu_find(v2);
        if (leader1 != leader2)
            dsu_union(leader1, leader2);
        else
            numberOfCycles++;
    }
    cout << numberOfCycles << endl;
    return 0;
}