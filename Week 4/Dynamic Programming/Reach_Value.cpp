#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool reach_value(ll n, map<int, int> dp)
{
    if (n == 1)
        return true; // Base Case
    if (dp.count(n))
        return dp[n];
    if (n % 20 == 0)
        return dp[n] = reach_value(n / 10, dp) || reach_value(n / 20, dp); // 2 option
    else if (n % 10 == 0)
        return dp[n] = reach_value(n / 10, dp);
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        ll n;
        cin >> n;
        map<int, int> dp;
        if (reach_value(n, dp))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}