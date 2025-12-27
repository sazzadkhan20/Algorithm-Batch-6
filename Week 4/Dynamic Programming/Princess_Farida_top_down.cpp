#include <bits/stdc++.h>
#define ll long long int

using namespace std;
const int N = 1e4 + 5;
ll dp[N];

ll max_nums_coins(ll n, vector<ll> coins)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    ll op1 = coins[n - 1] + max_nums_coins(n - 2, coins);
    ll op2 = max_nums_coins(n - 1, coins);
    return dp[n] = max(op1, op2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; i++)
    {
        ll n;
        cin >> n;
        vector<ll> coins(n);
        for (int i = 0; i < n; i++)
            cin >> coins[i];
        memset(dp, -1, sizeof(dp));
        cout << "Case " << i << ": " << max_nums_coins(n, coins) << endl;
    }
}