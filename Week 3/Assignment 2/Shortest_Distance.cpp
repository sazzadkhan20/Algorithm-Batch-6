#include <bits/stdc++.h>
#define ll long long int

using namespace std;
int vertices, edges;
const int N = 102;
ll path[N][N];

void all_pair_shortest_path()
{
    for (int k = 1; k <= vertices; k++)
    {
        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                if (path[i][k] < 100000000000000 && path[k][j] < 100000000000000)
                {
                    if (path[i][k] + path[k][j] < path[i][j])
                        path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
}

int main()
{
    cin >> vertices >> edges;
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            if (i == j)
                path[i][j] = 0;
            else
                path[i][j] = 100000000000000;
        }
    }
    while (edges--)
    {
        int v1, v2;
        ll cost;
        cin >> v1 >> v2;
        cin >> cost;
        if (path[v1][v2] == 100000000000000)
            path[v1][v2] = cost;
        else
        {
            if (path[v1][v2] > cost)
                path[v1][v2] = cost;
        }
    }

    all_pair_shortest_path();
    int queries;
    cin >> queries;
    while (queries--)
    {
        int s, d;
        cin >> s >> d;
        if (path[s][d] < 100000000000000)
            cout << path[s][d] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
