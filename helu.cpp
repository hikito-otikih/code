#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t = 0;
    cin >> t;
    while (t --)
    {
        int n = 0;
        cin >> n;
        map<int, int> m;
        long long ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            int c;
            cin >> c;
            ans += m[c - i];
            m[c - i] ++;
        }
        cout << ans << '\n';
    }
    return 0;
}