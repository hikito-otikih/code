#include <bits/stdc++.h>

using namespace std;
const int N = 100;

int n, a[N], b[N], c[N], d[N], ans = -1e9;

// 0 : +
// 1 : -
// 2 : *
// 3 : /

void rec(int i)
{
    if (i == n)
    {
        int k = 1;
        c[1] = a[1]; d[1] = 0;
        for (int x = 1; x < n; x ++)
        {
            if (b[x] >= 2) 
            {
                if (b[x] == 2) c[k] *= a[x + 1];
                else
                {
                    if (a[x + 1] == 0) return ;
                    c[k] /= a[x + 1];
                }
            }
            else c[++ k] = a[x + 1], d[k] = b[x];
        }
        int sum = 0;
        for (int x = 1; x <= k; x ++)
        {
            if (d[x] == 0) sum += c[x];
            else sum -= c[x];
        }
        ans = max(ans, sum);
        return ;
    }
    for (int j = 0; j < 4; j++)
    {
        b[i] = j;
        rec(i + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    rec(1);
    cout << ans ;
    return 0;
}