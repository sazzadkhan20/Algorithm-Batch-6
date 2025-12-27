#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
vector<int> graph[N];

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    while (edges--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2); // Directed Graph
    }
    int queries;
    cin >> queries;
    while (queries--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        if (v1 == v2)
        {
            cout << "YES\n";
            continue;
        }
        bool flag = false;
        for (int val : graph[v1])
        {
            if (val == v2)
            {
                cout << "YES\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "NO\n";
    }
}