#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        string s1, s2;
        vector<char> v1;
        vector<char> v2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.length(); i++)
            v1.push_back(s1[i]);
        for (int i = 0; i < s2.length(); i++)
            v2.push_back(s2[i]);
        if (v1.size() != v2.size())
        {
            cout << "NO\n";
            continue;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        bool flag = false;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                flag = true;
                cout << "NO\n";
                break;
            }
        }
        if (!flag)
            cout << "YES\n";
    }
}