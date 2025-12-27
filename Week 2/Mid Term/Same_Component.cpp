#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int n, m;
char grid[N][N];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool validity(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int sr, int sc)
{
    grid[sr][sc] = '-';
    for (auto pa : p)
    {
        int cr = pa.first + sr;
        int cc = pa.second + sc;
        if (validity(cr, cc) && grid[cr][cc] == '.')
            dfs(cr, cc);
    }
}

int main()
{
    cin >> n >> m;
    int sr, sc, dr, dc;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    cin >> sr >> sc >> dr >> dc;
    dfs(sr, sc);
    if (grid[dr][dc] == '.')
        cout << "NO\n";
    else
        cout << "YES\n";
}