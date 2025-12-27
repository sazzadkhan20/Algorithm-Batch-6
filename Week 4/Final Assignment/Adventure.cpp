#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int dp[N][N];

int knapsack(int weight[], int value[], int n, int capacity)
{
    if (n == 0 || capacity == 0)
        return 0;
    if (dp[n][capacity] != -1)
        return dp[n][capacity];
    if (weight[n - 1] <= capacity)
        return dp[n][capacity] = max(value[n - 1] + knapsack(weight, value, n - 1, capacity - weight[n - 1]), knapsack(weight, value, n - 1, capacity));
    return dp[n][capacity] = knapsack(weight, value, n - 1, capacity);
}

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n, capacity;
        cin >> n >> capacity;
        int weight[N], value[N];
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> value[i];
        memset(dp, -1, sizeof(dp));
        cout << knapsack(weight, value, n, capacity) << endl;
    }
}