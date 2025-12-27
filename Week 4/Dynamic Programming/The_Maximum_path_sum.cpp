#include <bits/stdc++.h>

using namespace std;
const int N = 15;
int n, m;
int mat[N][N];
int dp[N][N];

int maximum_path_sum(int i, int j)
{
    if (dp[i][j] != INT_MIN)
        return dp[i][j];
    if (i > 1 && j > 1)
    {
        int op1 = maximum_path_sum(i - 1, j);
        int op2 = maximum_path_sum(i, j - 1);
        if (op1 == INT_MIN && op2 == INT_MIN)
            return dp[i][j] = mat[i - 1][j - 1];
        return dp[i][j] = mat[i - 1][j - 1] + max(op1, op2);
    }
    else
        return mat[i - 1][j - 1]; // extended Row Column
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    n++, m++;
    for (int i = 0; i < m; i++)
        mat[0][i] = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
                mat[i][j] = INT_MIN;
            else
                cin >> mat[i][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            dp[i][j] = INT_MIN;
    }
    cout << maximum_path_sum(n, m) << endl;
}