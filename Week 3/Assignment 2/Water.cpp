#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back({x, i});
        }
        sort(heights.begin(), heights.end());
        int maxHeight = INT_MIN;
        int minDifference = INT_MAX;
        int start = 0, finish = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (heights[i].first - heights[i - 1].first < minDifference && heights[i - 1].first >= maxHeight)
            {
                maxHeight = heights[i - 1].first;
                minDifference = heights[i].first - heights[i - 1].first;
                start = heights[i].second, finish = heights[i - 1].second;
            }
        }
        if (start > finish)
            cout << finish << " " << start << endl;
        else
            cout << start << " " << finish << endl;
    }
}