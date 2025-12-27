#include <bits/stdc++.h>
#define ll long long int

using namespace std;
const int N = 100;
ll dp[N];

ll tetranacci_sequence(ll n)
{
    // Base Case
    if (n < 2)
        return n;
    else if (n < 4)
        return n - 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = tetranacci_sequence(n - 1) + tetranacci_sequence(n - 2) + tetranacci_sequence(n - 3) + tetranacci_sequence(n - 4);
}

int main()
{
    ll n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << tetranacci_sequence(n) << endl;
}