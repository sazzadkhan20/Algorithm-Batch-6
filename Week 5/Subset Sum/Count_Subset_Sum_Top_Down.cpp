#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
const int S = 1e5 + 5;
int arr[N];
int dp[N][S];

int count_subset_sum(int n, int sum)
{
    // Base Case
    if (n == 0)
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n - 1] <= sum)
        return dp[n][sum] = count_subset_sum(n - 1, sum - arr[n - 1]) + count_subset_sum(n - 1, sum);
    return dp[n][sum] = count_subset_sum(n - 1, sum);
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
    cout << count_subset_sum(n, sum) << endl;
}