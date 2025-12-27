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
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // Undirected Graph
    }
    int queries;
    cin >> queries;
    while (queries--)
    {
        int x;
        cin >> x;
        if (graph[x].empty())
        {
            cout << "-1\n";
            continue;
        }
        vector<int> v;
        for (int val : graph[x])
            v.push_back(val);
        sort(v.begin(), v.end(), greater<int>());
        for (int val : v)
            cout << val << " ";
        cout << endl;
    }
}