#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int n, m;
char grid[N][N];
bool visit[N][N];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int roomCount;

bool validity(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int sr, int sc)
{
    visit[sr][sc] = true;
    roomCount++;
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
    vector<int> v;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && grid[i][j] == '.')
            {
                roomCount = 0;
                dfs(i, j);
                v.push_back(roomCount);
                flag = true;
            }
        }
    }
    if (!flag)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    for (int val : v)
        cout << val << " ";
    cout << endl;
}