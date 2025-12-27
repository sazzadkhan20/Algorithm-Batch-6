#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
int dp[N][N];

int lcs(string s1, string s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
        return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
    int l = lcs(s1, s2, n, m - 1);
    int r = lcs(s1, s2, n - 1, m);
    return dp[n][m] = max(l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    cout << lcs(s1, s2, s1.length(), s2.length()) << endl;
}