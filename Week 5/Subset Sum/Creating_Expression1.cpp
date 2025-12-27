#include <bits/stdc++.h>

using namespace std;
const int N = 22;
int nums[N];
map<pair<int, int>, int> dp;

bool subsetSum(int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return true;
        return false;
    }
    if (dp.count({n, sum}))
        return dp[{n, sum}];
    if (nums[n - 1] <= sum)
        return dp[{n, sum}] = subsetSum(n - 1, sum - nums[n - 1]) || subsetSum(n - 1, sum);
    return dp[{n, sum}] = subsetSum(n - 1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n, x;
    cin >> n >> x;
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        totalSum += nums[i];
    }
    if ((x + totalSum) % 2 != 0 || abs(x) > totalSum || x + totalSum < 0)
    {
        cout << "NO\n";
        return 0;
    }
    int s1 = (x + totalSum) / 2;
    if (subsetSum(n, s1))
        cout << "YES\n";
    else
        cout << "NO\n";
}