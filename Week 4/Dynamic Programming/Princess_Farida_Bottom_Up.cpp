#include <bits/stdc++.h>
#define ll long long int

using namespace std;
const int N = 1e4 + 5;

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
        ll coins[N];
        ll dp[N];
        for (int i = 0; i < n; i++)
            cin >> coins[i];
        dp[0] = 0;
        dp[1] = 0;
        n++;
        for (int i = 2; i <= n; i++)
        {
            ll op1 = coins[i - 2] + dp[i - 2];
            ll op2 = dp[i - 1];
            dp[i] = max(op1, op2);
        }
        cout << "Case " << i << ": " << dp[n] << endl;
    }
}