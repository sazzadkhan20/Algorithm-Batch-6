#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
const int S = 1e3 + 5;
int coins[N];
int dp[N][S];

int min_coins(int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return 0;
        return INT_MAX;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (coins[n - 1] <= sum)
    {
        int op1 = min_coins(n, sum - coins[n - 1]);
        int op2 = min_coins(n - 1, sum);
        if (op1 == INT_MAX && op2 == INT_MAX)
            return dp[n][sum] = INT_MAX;
        if (op1 == INT_MAX)
            return dp[n][sum] = op2;
        return dp[n][sum] = min(op1 + 1, op2);
    }
    return dp[n][sum] = min_coins(n - 1, sum);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int target;
    cin >> target;
    memset(dp, -1, sizeof(dp));
    cout << min_coins(n, target) << endl;
}