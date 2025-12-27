#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
const int S = 1e5 + 5;
bool dp[N][S];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int arr[N];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    dp[0][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i][j])
                cout << "T ";
            else
                cout << "F ";
        }
        cout << endl;
    }
    // if (dp[n][sum])
    //     cout << "Possible\n";
    // else
    //     cout << "Not Possible\n";
}