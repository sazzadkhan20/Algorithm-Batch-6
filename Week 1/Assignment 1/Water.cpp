#include <bits/stdc++.h>
#define pa pair<int, int>

using namespace std;
const int N = 1e5 + 5;

bool cmp(pa l, pa r)
{
    return l.first >= r.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        pa heights[N];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights[i] = {x, i};
        }
        sort(heights, heights + n, cmp);
        if (heights[0].second < heights[1].second)
            cout << heights[0].second << " " << heights[1].second << endl;
        else
            cout << heights[1].second << " " << heights[0].second << endl;
    }
}