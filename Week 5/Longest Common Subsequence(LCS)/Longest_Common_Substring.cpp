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
                dp[i][j] = 0;
        }
    }
    int maxLenghtOfSubstring = INT_MIN;
    int ci, cj;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maxLenghtOfSubstring < dp[i][j])
            {
                maxLenghtOfSubstring = dp[i][j];
                ci = i, cj = j;
            }
        }
    }
    cout << maxLenghtOfSubstring << endl;
    stack<char> st;
    while (ci != 0 && cj != 0)
    {
        if (s1[ci - 1] == s2[cj - 1])
            st.push(s1[ci - 1]);
        else
            break;
        ci--, cj--;
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}