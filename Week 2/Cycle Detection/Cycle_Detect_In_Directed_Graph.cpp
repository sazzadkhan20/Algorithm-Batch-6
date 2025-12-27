#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
bool visit[N];
bool pathVisit[N];
bool isCycle;

void addEdge(int v1, int v2)
{
    graph[v1].push_back(v2); // Directed Graph
}

// DFS
void cycle_detect_using_dfs(int src)
{
    visit[src] = true;
    pathVisit[src] = true;
    for (int child : graph[src])
    {
        if (pathVisit[child])
        {
            cout << src << endl;
            isCycle = true;
        }
        if (!visit[child])
            cycle_detect_using_dfs(child);
    }
    pathVisit[src] = false;
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
    memset(visit, false, sizeof(visit));
    memset(pathVisit, false, sizeof(pathVisit));
    isCycle = false;
    // Component Handle
    for (int i = 0; i < vertices; i++)
        if (!visit[i])
            cycle_detect_using_dfs(i);
    if (isCycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle Detected\n";
}