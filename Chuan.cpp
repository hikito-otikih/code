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
#define task "chuan"

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

ll x, m;

void Input(void) 
{   
    cin >> x >> m;
}

void solve(void) 
{
    ll ans = 0;
    for (int i = 1; i <= min(m, x); i ++)
    {
        int k = i ^ x;
        if (k % i == 0 || k % x == 0) ans ++;
    }
    for (ll i = m + 1; i <= m + x; i ++)
        if (i % x == 0)
        {
            ll k = i ^ x;
            if (k <= m && k > x) ans ++;
        }
    // for (int i = 1; i <= m; i ++)
    // {
    //     int k = i ^ x;
    //     if (k % i == 0 || k % x == 0) 
    //     {
    //         cout << i << ' ' << k << '\n';
    //     }
    // }
    if (x < m) 
    {
        ans += m / x - 1;
        if (x * 2 <= m)
            if (((2 * x) ^ x) <= x) ans --;
        ll final = m / x * x;
        if ((x ^ final) > m) ans --;
    }
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".INP", "r"))
        freopen(task ".INP", "r", stdin),
            freopen(task ".OUT", "w", stdout);
    int test = 1;
    cin >> test;
    while (test --) {
        Input();
        solve();
    }
    return 0;
}
