#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int dp[N];

bool isMake(int n)
{
    if (n == 1)
        return true;
    if (n < 1)
        return false;
    if (dp[n] != -1)
        return dp[n];
    if (n % 2 == 0)
        return dp[n] = isMake(n - 3) || isMake(n / 2);
    else
        return dp[n] = isMake(n - 3);
}

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        if (isMake(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}