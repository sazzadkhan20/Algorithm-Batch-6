#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int dis[N][N];

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            dis[i][j] = INT_MAX;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (edges--)
    {
        int i, j, w;
        cin >> i >> j >> w;
        dis[i][j] = w;
    }

    // Floyd Warshall Algo
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }

    // Negetive Cycle Detect
    for (int i = 0; i < vertices; i++)
    {
        if (dis[i][i] < 0)
        {
            cout << "Negetive Cycle Detect\n";
            return 0;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (dis[i][j] == INT_MAX)
                cout << "INF" << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}