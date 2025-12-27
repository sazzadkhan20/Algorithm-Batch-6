#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int stones[N];
int minIncurredCost;

int incurred_cost(int n)
{

    int op1 = abs(stones[n - 1] - incurred_cost(n - 1));
    int op2 = abs(stones[n - 2] - incurred_cost(n - 2));
    if (op1 < op2)
    {
        minIncurredCost += op1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> stones[i];
    minIncurredCost = 0;
}