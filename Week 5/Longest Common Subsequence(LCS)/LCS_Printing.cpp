#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    // Base Case set
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    vector<char> lcs;
    while (n != 0 && m != 0)
    {
        if (dp[n][m] == max(dp[n - 1][m], dp[n][m - 1]) + 1)
        {
            lcs.push_back(s1[n - 1]);
            n--, m--;
        }
        else
        {
            if (dp[n - 1][m] >= dp[n][m - 1])
                n--;
            else
                m--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    for (char c : lcs)
        cout << c;
}