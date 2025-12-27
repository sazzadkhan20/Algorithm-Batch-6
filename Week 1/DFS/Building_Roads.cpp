#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
bool visit[N];

void addEdge(int v1, int v2)
{
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

void dfs(int src)
{
    visit[src] = true;
    for (int node : graph[src])
        if (!visit[node])
            dfs(node);
}
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    while (edges--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        addEdge(v1, v2);
    }
    vector<int> v;
    for (int i = 1; i <= vertices; i++)
    {
        if (!visit[i])
        {
            v.push_back(i);
            dfs(i);
        }
    }
    if (v.size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << v.size() - 1 << endl;
    for (int i = 1; i < v.size(); i++)
        cout << v[i - 1] << " " << v[i] << endl;
}