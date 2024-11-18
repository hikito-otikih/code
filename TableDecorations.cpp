#include <bits/stdc++.h>

#define MASK(i) (1LL << (i))
#define BIT(x, y) (((x) >> (y)) & 1)
#define sz(v) ((ll) (v).size())
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define F first
#define S second
#define pii(x, y) make_pair(x, y)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define lg(x) (63 - __builtin_clz(x))
#define task "test"

template <class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {x = y; return 1;}
        return 0;
    }

template <class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {x = y; return 1;}
        return 0;
    }

using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int M = 1e5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll oo = 2e18;
const double eps = 1e-9;

ll a[3];

void Input(void) 
{
    for (int i = 0; i < 3; i ++) cin >> a[i];
}

void solve(void) 
{
    sort(a, a + 3);
    ll res = 0;
    if (a[2] - a[1] > 0)
    {
        if (a[2] - a[1] > a[1] - a[0]) 
        {
            res += a[1] - a[0];
            a[2] -= 2 * (a[1] - a[0]);
            a[1] = a[0];
        }
        else
        {
            res += a[2] - a[1];
            a[1] = a[2] = 2 * a[1] - a[2];
        }
    }   
    if (a[0] == a[2]) 
    {
        cout << res + a[0];
        return;
    }
    if (a[0] == a[1])
    {
        int x = 2 * (a[2] - a[0]) / 3;
        if (a[0] - x / 2 - (x & 1) < 0) cout << res + 2 * a[0];
        else 
        {
            if (x % 2 == 0) cout << res + x + (a[0] - x / 2);
            else cout << res + x + (a[0] - x / 2 - 1);
        }
        return;
    }
    if (a[1] == a[2])
    {
        int x = 2 * (a[2] - a[0]) / 3;
        cout << res + x + a[0];
        return;
    }
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".INP", "r"))
        freopen(task ".INP", "r", stdin),
            freopen(task ".OUT", "w", stdout);
    int test = 1;
//    cin >> test;
    while (test --) 
    {
        Input();
        solve();
    }
    return 0;
}
