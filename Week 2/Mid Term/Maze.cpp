#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int n, m;
char grid[N][N];
bool visit[N][N];
pair<int, int> parent[N][N];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool validity(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visit[sr][sc] = true;
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (auto pa : p)
        {
            int cr = pa.first + node.first;
            int cc = pa.second + node.second;
            if (validity(cr, cc) && !visit[cr][cc] && grid[cr][cc] != '#')
            {
                q.push({cr, cc});
                visit[cr][cc] = true;
                parent[cr][cc] = node;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int sr = 0, sc = 0, dr = 0, dc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
                sr = i, sc = j;
            if (grid[i][j] == 'D')
                dr = i, dc = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            parent[i][j] = {-1, -1};
    }
    memset(visit, false, sizeof(visit));
    bfs(sr, sc);
    // cout << parent[sr][sc].first << " " << parent[sr][sc].second << endl;
    if (visit[dr][dc])
    {
        while (parent[dr][dc].first != -1 && parent[dr][dc].second != -1)
        {
            grid[parent[dr][dc].first][parent[dr][dc].second] = 'X';
            int val1 = parent[dr][dc].first;
            int val2 = parent[dr][dc].second;
            dr = val1;
            dc = val2;
        }
    }
    grid[sr][sc] = 'R';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }
}