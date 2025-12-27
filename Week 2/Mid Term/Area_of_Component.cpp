#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int n, m;
char grid[N][N];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int components;

bool validity(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int sr, int sc)
{
    grid[sr][sc] = '-';
    components++;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    int areaOfComponent = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                components = 0;
                dfs(i, j);
                areaOfComponent = min(areaOfComponent, components);
            }
        }
    }

    if (areaOfComponent == INT_MAX)
        cout << -1 << endl;
    else
        cout << areaOfComponent << endl;
}