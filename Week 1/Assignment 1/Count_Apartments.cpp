#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int n, m;
char grid[N][N];
bool visit[N][N];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool validity(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int sr, int sc)
{
    visit[sr][sc] = true;
    for (auto child : p)
    {
        int cr = child.first + sr;
        int cc = child.second + sc;
        if (validity(cr, cc) && !visit[cr][cc] && grid[cr][cc] != '#')
            dfs(cr, cc);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    memset(visit, false, sizeof(visit));
    int apartmentsNum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && grid[i][j] == '.')
            {
                apartmentsNum++;
                dfs(i, j);
            }
        }
    }
    cout << apartmentsNum << endl;
}