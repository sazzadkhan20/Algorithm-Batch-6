#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
bool visit[N];
int parent[N];
bool isCycle;

void addEdge(int v1, int v2)
{
    graph[v1].push_back(v2);
    graph[v2].push_back(v1); // Undirected Graph
}

// DFS
void cycle_detect_using_dfs(int src)
{
    visit[src] = true;
    for (int child : graph[src])
    {
        if (visit[child] && parent[src] != child)
        {
            cout << src << endl;
            isCycle = true;
        }
        if (!visit[child])
        {
            parent[child] = src;
            cycle_detect_using_dfs(child);
        }
    }
}

// BFS
void cycle_detect_using_bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        for (int connectedNode : graph[vertex])
        {
            if (visit[connectedNode] && parent[vertex] != connectedNode)
            {
                cout << vertex << endl;
                isCycle = true;
            }
            if (!visit[connectedNode])
            {
                q.push(connectedNode);
                visit[connectedNode] = true;
                parent[connectedNode] = vertex;
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
        int v1, v2;
        cin >> v1 >> v2;
        addEdge(v1, v2);
    }
    memset(visit, false, sizeof(visit));
    memset(parent, -1, sizeof(parent));
    isCycle = false;
    // Component Handle
    for (int i = 0; i < vertices; i++)
        if (!visit[i])
            cycle_detect_using_bfs(i);
    if (isCycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle Detected\n";
}