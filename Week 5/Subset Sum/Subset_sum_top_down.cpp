#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
const int S = 1e5 + 5;
int arr[N];
int dp[N][S];

bool subset_sum(int n, int sum)
{
    // Base Case
    if (n == 0)
    {
        if (sum == 0)
            return true;
        return false;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n - 1] <= sum)
    {
        bool op1 = subset_sum(n - 1, sum - arr[n - 1]);
        bool op2 = subset_sum(n - 1, sum);
        return dp[n][sum] = op1 || op2;
    }
    return dp[n][sum] = subset_sum(n - 1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    if (subset_sum(n, sum))
        cout << "Possible\n";
    else
        cout << "Not Possible\n";
}