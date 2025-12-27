#include <bits/stdc++.h>
#define ll long long int

using namespace std;
const int N = 100;

int main()
{
    ll n;
    cin >> n;
    ll dp[N];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    cout << dp[n] << endl;
}