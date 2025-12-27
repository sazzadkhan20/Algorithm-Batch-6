#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int n, m;
bool visit[N][N];
vector<pair<int, int>> p = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};

class Node
{
public:
    int row, column, level;
    Node(int r, int c, int l)
    {
        row = r;
        column = c;
        level = l;
    }
};

bool validity(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(int sr, int sc, int dr, int dc)
{
    queue<Node> q;
    q.push(Node(sr, sc, 0));
    visit[sr][sc] = true;
    int level = -1;
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        if (node.row == dr && node.column == dc)
            level = node.level;

        for (auto pa : p)
        {
            int cr = pa.first + node.row;
            int cc = pa.second + node.column;
            if (validity(cr, cc) && !visit[cr][cc])
            {
                q.push(Node(cr, cc, node.level + 1));
                visit[cr][cc] = true;
            }
        }
    }
    return level;
}

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int Ki, Kj, Qi, Qj;
        cin >> n >> m >> Ki >> Kj >> Qi >> Qj;
        memset(visit, false, sizeof(visit));
        int level = bfs(Ki, Kj, Qi, Qj);
        cout << level << endl;
    }
}